# Gesture Controlled Car (ESP-NOW + Arduino)

## Overview
This project is a **gesture-controlled car** using **ESP-NOW communication** and an **Arduino**.  
Gesture data is transmitted wirelessly via **ESP-NOW** using **binary bits**, and finally received through **serial communication** between an ESP device and Arduino for motor control.

## Key Features
- **ESP-NOW** protocol for fast, connectionless wireless data transfer.
- **Binary bits** are used to efficiently represent gesture commands.
- **Serial communication (UART)** between ESP and Arduino for final control.
- **Arduino** reads the incoming bits and moves the car based on the commands.

## Project Structure
- **ESP Sender Code**: Captures gesture data, encodes it into binary bits, and sends it using ESP-NOW.
- **ESP Receiver Code**: Receives gesture bits over ESP-NOW and forwards them via serial to Arduino.
- **Arduino Code**: Reads serial data, decodes gesture commands, and drives the motors accordingly.

## How It Works
1. **ESP Device 1** captures gestures and sends corresponding **binary bits** over **ESP-NOW**.
2. **ESP Device 2** receives the bits and sends them to **Arduino** via serial TX/RX.
3. **Arduino** runs the final "read and drive" code to control the car's motors based on the received gesture.

## Hardware Required
- 2× ESP8266 or ESP32 Modules (for ESP-NOW communication)
- Arduino Uno/Nano
- Motor Driver Module (e.g., L298N)
- Motors and Chassis
- Power Supply (LiPo Battery)
- Connecting Wires

## Connection Diagram (ESP to Arduino)

| Receiving ESP Pin | Arduino Pin |
|:------------------|:------------|
| TX                | RX          |
| RX                | TX          |
| GND               | GND         |
| VCC               | 3.3V (or 5V depending on ESP model) |

> **Important:** If using a 5V Arduino and 3.3V ESP, use a voltage divider for the ESP RX pin.

## Setup Instructions
1. **Program** the transmitter ESP to send gesture binary data using **ESP-NOW**.
2. **Program** the receiver ESP to forward the received binary data over serial.
3. **Connect** the receiver ESP and Arduino via serial (TX to RX, RX to TX).
4. **Upload** the Arduino "final read and drive" code.
5. **Power on** the system and control your car with gestures!

## Code Files
- `/ESP_Sender/` → Code for sending gestures using ESP-NOW.
- `/ESP_Receiver/` → Code for receiving gestures and forwarding via serial.
- `/Arduino_Code/` → Code to read serial data and drive motors.

## Demo

![image](https://github.com/user-attachments/assets/c44f94d8-e2ec-4370-9962-690b630156af)
![image](https://github.com/user-attachments/assets/54b76dee-ccab-4470-a5fe-562d9d9d477f)
![image](https://github.com/user-attachments/assets/1423fb6b-85f0-47a7-8927-e0b03c166205)


https://drive.google.com/file/d/1jZrstY58wcINUSevZBhy4UyP-NzMkalM/view?usp=sharin
https://drive.google.com/file/d/1hCq1aDgSWL1GhbkVPWYBvk3fTxPZ2wnN/view?usp=sharing
https://drive.google.com/file/d/155bS7g5rFuW2yxv4fs_HORT4VwKUnh5y/view?usp=sharing

by Prabal Khare
