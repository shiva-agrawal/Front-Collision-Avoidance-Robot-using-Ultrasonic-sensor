# Front Collision Avoidance using Ultrasonic sensor and Raspberry pi 3 Model B with Linux (OS)

This project is more hardware oriented as compared to software. The aim of the project is to understand the working and interface of Ultrasonic sensor (one of the important sensors used in autonomous driving for near range obstacle detection) together with raspebrry pi and RC car. To demostrate the working, a function named as front collision avoidance is developed using the same sensor.

For the project, I have selected a RC car which has DC motors for throttle and steering. These motors are then connected to motor shield circuit which consist of L293D (direction control H-bridge IC) and serial to parallel shift register. Further the motor shield is connected to Raspberry pi 3 Model B development board. The used Ultrasonic sensor is HC-SR04 having range upto 400 cm and it is interfaced directly with rasp-pi via a simple voltage divider circuit.

I have installed Ubuntu Mint OS on the rasp-pi and written the DC motor drivers for the vehicle motion control and Ultrasonic sensor driver for distance measurement in cm using embedded C++ and Geany IDE (open source) in Ubuntu. Further to run the application / function, the pi OS is accessed remotely using VNC server-client mode from PC.

This project is one of the basic foundation to work towards the autonomous driving / autonomous robotics.

## Project Folder structure

1. docs 
    * Project details.pdf - detailed project report covering hardware and software description
    * HC-SR04_ultrasonic_module_user_guide.pdf - description of sensor and its working
    * RC car with hardware.jpg - Photo of the final RC car mounted with required hardware
2. src
    * std_int.h - datatype declaration
    * vehicle_actuator.cpp, vehicle_actuator.h - driver files of DC motor control 
    * ultrasonic_sensor.cpp, ultrasonic_sensor.h - driver files of ultrasonic sensor for distance measurement 
3. test
    * main.cpp - test file of the project
