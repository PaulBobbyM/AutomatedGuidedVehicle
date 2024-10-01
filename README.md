# Automated Guided Vehicle (AGV) using Arduino
# Project Overview
This project involves building an Automated Guided Vehicle (AGV) using an Arduino microcontroller. The AGV uses ultrasonic sensors for obstacle detection, an H-Bridge for motor control, and other components to autonomously navigate a predefined path or environment.

# Components Used
* Arduino Uno (or any compatible board)
* Ultrasonic sensor (HC-SR04) - for obstacle detection
* H-Bridge (L298N) - for motor control
* DC motors - for vehicle movement
* Motor driver module - for controlling the DC motors
* Battery pack - for power supply
* Wheels and chassis - for the vehicle body
* LEDs (optional) - for visual feedback
# Working Principle
* The AGV uses an ultrasonic sensor to detect obstacles in its path. The sensor sends out ultrasonic waves and measures the time it takes for the waves to return after hitting an obstacle. Based on the distance calculated, the AGV will take appropriate actions, such as stopping or turning to avoid the obstacle.

* The H-Bridge is used to control the direction and speed of the DC motors, allowing the AGV to move forward, reverse, and turn.

# Features
* Autonomous navigation using ultrasonic sensors
* Obstacle detection and avoidance
* Motor control using H-Bridge
* Power management via battery pack
* Modular design for easy hardware upgrades
