# Line Follower Robot using ATmega32 and IR Sensors

This project is a basic line-following robot built using the ATmega32 microcontroller. The robot uses IR sensors to detect and follow a line on the ground, making it suitable for various autonomous robot applications, such as guiding or sorting systems.

## Components Used

- **ATmega32 Microcontroller**: The main controller that processes sensor data and drives the motors.
- **Motor Driver**: Enables control of the DC motors based on signals from the microcontroller.
- **2 DC Motors with Wheels**: Provide movement to the robot.
- **2 IR Sensors**: Detect the line by sensing differences in surface reflectivity.
- **Wires**: Used to connect the components.

## How It Works

The IR sensors detect the line by identifying variations in reflected infrared light:

- **Both sensors on the line**: The robot moves forward.
- **Left sensor on the line**: The robot turns left.
- **Right sensor on the line**: The robot turns right.
- **No sensor on the line**: The robot stops or waits until it detects the line again.

This logic allows the robot to follow the path defined by a dark line on a light surface.

## Circuit Diagram

- **Microcontroller**: Connects to the motor driver, which controls the DC motors.
- **Sensors**: IR sensors are connected to the ATmega32 to provide the input signals needed for line detection.

## Installation and Setup

1. **Code Upload**: Write and upload the code to the ATmega32 microcontroller using AVR programming (in C).
2. **Circuit Assembly**: Connect all components as per the circuit diagram provided.

## Usage

1. Place the robot on a track with a clearly defined dark line on a light surface.
2. Power on the robot, and it will autonomously follow the line.

## Additional Notes

- Ensure the track has smooth curves for optimal line-following performance.
- Test the IR sensors on your surface to adjust thresholds as necessary.
