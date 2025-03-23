# EEG_CONTROLLED_WHEELCHAIR

## Problem Statement
The EEG-controlled wheelchair project enables individuals with severe physical disabilities to navigate using brainwave signals captured by a NeuroSky MindWave Mobile device. EEG data, processed via an Arduino Uno and HC-05 Bluetooth module, controls a ZK-2WD Robot Car kit through an L298N motor driver, mapping attention and blink strength to movements like forward, stop, left, and right. This AI-powered, non-invasive solution offers an affordable alternative to joystick-based wheelchairs, enhancing user independence.

## Target Audience
This project targets individuals with severe physical disabilities (e.g., quadriplegia, cerebral palsy, advanced ALS) who cannot use traditional wheelchairs, as well as caregivers and rehabilitation centers seeking accessible mobility solutions. Assistive technology researchers and developers can also benefit by building on this affordable, AI-driven prototype for brain-computer interface (BCI) applications.

## Proposed Solution & Key Features
### Proposed Solution
The EEG-controlled wheelchair uses a NeuroSky MindWave Mobile to capture brainwave signals, transmitted via an HC-05 Bluetooth module to an Arduino Uno. The Arduino processes EEG data (attention, blink strength) to control a ZK-2WD Robot Car kit through an L298N motor driver, enabling movements like forward, stop, left, and right for users with limited motor function.

### Key Features
- **Brainwave Control**: Maps attention (>60 for full speed, 30–60 for half speed, <30 to stop) and blink strength (>50 for left, >100 for right) to wheelchair movements.
- **Non-Invasive & Affordable**: Uses a cost-effective MindWave Mobile and Arduino setup, avoiding expensive hardware.
- **Wireless Connectivity**: HC-05 Bluetooth module ensures seamless EEG data transmission.
- **Customizable Control**: Adjustable thresholds for attention and blink strength to suit user needs.
- **Portable Design**: Lightweight ZK-2WD Robot Car kit, adaptable for real-world wheelchair integration.

## Technology Stack
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
Yes, EEG-controlled wheelchairs exist in research (e.g., University of Technology Sydney) and commercial projects (e.g., Toyota), using brain signals for mobility.

### How Is It Different?
This solution is more affordable, using a budget-friendly NeuroSky MindWave Mobile (~$100) and Arduino setup, unlike costly medical-grade systems. It employs simplified control logic (attention and blink thresholds), an open-source modular design for easy customization, and a non-invasive, user-friendly approach with minimal training required.

## How Will You Validate the Effectiveness?
We’ll validate the wheelchair through user testing with individuals with severe disabilities, measuring response accuracy, user comfort, and navigation efficiency in a controlled environment. Success will be assessed by comparing performance against a joystick-based wheelchair, focusing on ease of use and satisfaction, with iterative refinements based on feedback.

## Expected Challenges
- Inconsistent EEG signal quality due to user movement or sensor placement, risking inaccurate commands.
- HC-05 Bluetooth reliability issues at 57600 baud, potentially disrupting real-time control.
- Individual EEG variations requiring extensive user-specific calibration.
- Limited battery life of MindWave and wheelchair components, needing efficient power management.
- Ensuring user safety during navigation without obstacle detection sensors.

## Task Division Among Team Members
With 7 team members, tasks are divided as follows:
- **Member 1**: Hardware setup (Arduino, HC-05, L298N, ZK-2WD).
- **Member 2**: HC-05 Bluetooth configuration.
- **Member 3**: Arduino coding for EEG parsing.
- **Member 4**: Arduino coding for motor control logic.
- **Member 5**: User testing and validation.
- **Member 6**: Documentation and presentation.
- **Member 7**: Future enhancements (e.g., obstacle detection, digital twin in Unreal Engine 5).

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
- Developed by a team of 7 during the BITS College Hackathon, March 21, 2025.
