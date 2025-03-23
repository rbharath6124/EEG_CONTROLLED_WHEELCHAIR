#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RX, TX

// Motor pins
#define IN1 5
#define IN2 6
#define IN3 7
#define IN4 8
#define ENA 3
#define ENB 9

byte payloadData[64] = {0};
byte poorQuality = 0;
byte attention = 0;
byte blinkStrength = 0;
byte generatedChecksum = 0;
byte checksum = 0;
int payloadLength = 0;
boolean bigPacket = false;

void setup() {
  Serial.begin(57600);
  BTSerial.begin(57600);
  Serial.println("EEG-Controlled Wheelchair Starting...");

  // Set motor pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Initialize motors to stop
  stopMotors();
}

byte ReadOneByte() {
  while (!BTSerial.available());
  return BTSerial.read();
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void moveForward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}

void loop() {
  if (ReadOneByte() == 170) { // Sync byte 1 (0xAA)
    if (ReadOneByte() == 170) { // Sync byte 2 (0xAA)
      payloadLength = ReadOneByte();
      if (payloadLength > 169) return;

      generatedChecksum = 0;
      for (int i = 0; i < payloadLength; i++) {
        payloadData[i] = ReadOneByte();
        generatedChecksum += payloadData[i];
      }

      checksum = ReadOneByte();
      generatedChecksum = 255 - generatedChecksum;

      if (checksum == generatedChecksum) {
        poorQuality = 200;
        attention = 0;
        blinkStrength = 0;

        for (int i = 0; i < payloadLength; i++) {
          switch (payloadData[i]) {
            case 2:
              i++;
              poorQuality = payloadData[i];
              bigPacket = true;
              break;
            case 4:
              i++;
              attention = payloadData[i];
              break;
            case 0x05: // Blink strength
              i++;
              blinkStrength = payloadData[i];
              break;
            default:
              break;
          }
        }

        if (bigPacket) {
          Serial.print("PoorQuality: ");
          Serial.print(poorQuality, DEC);
          Serial.print(" Attention: ");
          Serial.print(attention, DEC);
          Serial.print(" BlinkStrength: ");
          Serial.println(blinkStrength, DEC);

          // Control wheelchair based on EEG data
          if (poorQuality == 0) { // Good signal quality
            // Handle blink strength for turning
            if (blinkStrength > 100) {
              turnRight();
              Serial.println("Turning Right");
              delay(500); // Turn for 500ms
              stopMotors();
            } else if (blinkStrength > 50) {
              turnLeft();
              Serial.println("Turning Left");
              delay(500); // Turn for 500ms
              stopMotors();
            } else {
              // Handle attention for forward movement
              if (attention > 60) {
                moveForward(255); // Full speed
                Serial.println("Moving Forward (Full Speed)");
              } else if (attention >= 30 && attention <= 60) {
                moveForward(128); // Half speed
                Serial.println("Moving Forward (Half Speed)");
              } else {
                stopMotors();
                Serial.println("Stopped");
              }
            }
          } else {
            stopMotors();
            Serial.println("Poor Signal Quality - Stopped");
          }
        }
        bigPacket = false;
      }
    }
  }
}