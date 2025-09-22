# EEG_CONTROLLED_WHEELCHAIR 

## Problem Statement
The EEG powered wheelchair allows bounded wheelchair users whose physical limitation severely limits their ability to move. By collecting and processing EEG inputs from a NeuroSky MindWave Mobile smartphone, we have created a non-invasive device that can be powered by an Arduino Uno and a Bluetooth module in order to take charge of the ZK-2WD Robot Car kit with an L298N motor driver, which will give priority to attention and blink strength associated with forward movement to move the wheelchair and stop, left movement and right movement.

## Target Audience
It is targeted at people with severe physical disabilities (e. g. quadriplegia, cerebral palsy, advanced ALS) who cannot safely use traditional wheelchairs but caregivers and rehabilitation facilities that want to design accessible mobility solutions as well as assistive technology researchers and developers who would be interested in adapting and using this cheap, fully autonomous, low cost prototype for the use of brain-computer interfaces (BCIs).

## Proposed Solution & Key Features

### Proposed Solution

The EEG controlled wheelchair is using a NeuroSky MindWave Mobile to record brainwave activity and sending it via an HC-05 Bluetooth module to an Arduino Uno. The Arduino parses the EEG data (attention and blink strength) to control the ZK-2WD Robot Car kit via an L298N motor driver which allows for motions like forward movement, stop maneuver, left direction and right movement for users with restricted motor capacity.



### Key Features

- **Brainwave Control** Monitors attention (>60 for full speed, 30–60 for half speed, 30 to stop ) and blink strength (>50 for left and >100 for right) for wheelchair movement.

- **No-Invasive and Affordable** Using very inexpensive MindWave Mobile & Arduino setup (no fancy hardware required).

- **Wireless Connectivity**: Bluetooth module of HC-05 guarantee high performance EEG data transmission.

- **Customizable Control**: adjustable attention and blink thresholds to suit user needs.

- **Portable Design**: Portable ZK-2WD Robot Car kit adjustable for use in real world wheelchair.## Technology Stack

- **Hardware**:

- NeuroSky MindWave Mobile (EEG data capture)

- Arduino Uno (signal processing and control)

- HC-05 Bluetooth Module (wireless communication)

- L298N Motor Driver (motor control)

- ZK-2WD Robot Car Kit (mobility base)

- **Languages**: C/C++ (Arduino programming)

- **Frameworks/Libraries**: SoftwareSerial Library (Arduino, for HC-05 communication)

- **APIs**: None

- **Databases**: None (real-time processing)



## Does Your Solution Already Exist? How Is It Different?

### Does It Exist?

Yes there are EEG controlled wheelchairs in research ( University of Technology Sydney ) and commercial projects ( Toyota ) which use brain signals to control mobility.



### How Is It Different?

This approach is more affordable / adaptable to a low cost NeuroSky MindWave Mobile ($100) / Arduino environment rather than a medical-grade system, with simplified control logic (adjustment and blink thresholds), open source modular code base allowing easy customization and a non-invasive, user-friendly approach with minimal training required.



## How Will You Validate the Effectiveness?

A user test phase will be run with people with extreme disabilities where we test the response accuracy, user comfort, and navigation efficiency while in a controlled environment. We will then measure the overall success by comparison with a joystick based wheelchair to compare ease of operation and satisfaction; these details will be fine tuned continuously with feedback.



## Expected Challenges

- Poorer quality EEG signal due to movement of user (or sensor placement) which can lead to inaccurate commands.

- HC-05 Bluetooth reliability issues at 57600 baud may be interrupting real-time control.

- Individual EEG variations requiring extensive user-specific calibration.
## Task Division Among Team Members

With 7 team members, tasks are divided as follows:

- **Member 1**: Hardware setup (Arduino, HC-05, L298N, ZK-2WD).

- **Member 2**: HC-05 Bluetooth configuration.

- **Member 3**: Arduino coding for EEG parsing.

- **Member 4**: Arduino coding for motor control logic.

- **Member 5**: User testing and validation.

- **Member 6**: Documentation and presentation.

- **Member 7**: Future enhancements (e.g., obstacle detection, digital twin in Unreal Engine 5).

# Wiring Diagram for Arduino-Based Motor Control

This project connects an **Arduino Uno** with an **HC-05 Bluetooth Module**, an **L298N Motor Driver**, and **ZK-2WD Motors** to control a robotic system wirelessly.

## Components
- **Arduino Uno**
- **HC-05 Bluetooth Module**
- **L298N Motor Driver**
- **ZK-2WD Motors**
- **12V Battery**

## Wiring Connections

### Arduino Uno to HC-05 Bluetooth Module
| Arduino Uno | HC-05 |
|------------|------|
| 5V         | VCC  |
| GND        | GND  |
| Pin 10     | RXD  |
| Pin 11     | TXD  |

### Arduino Uno to L298N Motor Driver
| Arduino Uno | L298N |
|------------|------|
| GND        | GND  |
| Pin 5      | IN1  |
| Pin 6      | IN2  |
| Pin 7      | IN3  |
| Pin 8      | IN4  |
| Pin 3 (PWM)| ENA  |
| Pin 9 (PWM)| ENB  |

### L298N Motor Driver to Motors and Power Supply
| L298N       | Connection |
|------------|-----------|
| VCC        | 12V Battery |
| GND        | Arduino GND |
| OUT1, OUT2 | Left Motor |
| OUT3, OUT4 | Right Motor |

## Notes
- Ensure proper power connections to avoid damage to components.
- PWM-enabled pins (ENA and ENB) allow speed control for the motors.
- The HC-05 Bluetooth module enables wireless control.

- For a detailed visual, refer to [ARCHITECTURE_DIAGRAM.jpg](ARCHITECTURE_DIAGRAM.jpg)

## Demo
- **Serial Monitor Output**: Example output showing EEG data and wheelchair commands:
PoorQuality: 0 Attention: 83 BlinkStrength: 0
Moving Forward 
PoorQuality: 0 Attention: 45 BlinkStrength: 60
Turning Left

## Getting Started

1. **Hardware Setup**:

- Connect the HC-05, L298N, and ZK-2WD Robot Car kit to the Arduino Uno as per the wiring diagram (to be added).

- Pair the HC-05 with the MindWave Mobile (MAC: `CC:78:AB:25:2A:95`) using AT commands.

2. **Code**:

- Upload the Arduino code (`eeg_wheelchair.ino`) to parse EEG data and control motors.

3. **Testing**:

- Wear the MindWave Mobile and test movements: focus for forward, relax to stop, blink to turn.

4. **Iterate**:

- Adjust thresholds based on user feedback for optimal control.



## Future Improvements

- Add obstacle detection with ultrasonic sensors.

- Implement a digital twin in Unreal Engine 5 for simulation.

- Use machine learning to improve EEG signal interpretation for individual users.



## Contributors

- Developed by a team Watermelon during the BITS College Hackathon, March 22, 2025.

- Battery life is limited for MindWave and other components of the wheelchair, we need good power management.

- Ensuring user safety during navigation without obstacle detection sensors
