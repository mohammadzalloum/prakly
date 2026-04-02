# Parkly
### Smart Parking System with IoT, NFC Access, Real-Time Monitoring, and EV Charging Support
![WhatsApp Image 2026-02-01 at 6 46 34 PM](https://github.com/user-attachments/assets/e8269b9d-b1cf-48c1-9e4f-45eab901d944)


Parkly is a smart parking solution designed to automate vehicle access, monitor parking availability in real time, and improve the overall parking experience using IoT and wireless communication. The system supports NFC-based entry, live parking spot tracking, mobile-based reservation, and EV charging management. :contentReference[oaicite:1]{index=1}

---

## Overview

Urban parking systems often suffer from inefficient space usage, manual processes, lack of visibility, and poor user experience. Parkly addresses these challenges through an integrated smart parking platform that combines hardware automation with a user-friendly mobile interface. The system is built around an ESP32 controller and supports both standard parking users and pro users with advanced reservation and EV features. :contentReference[oaicite:2]{index=2}

---

## Problem Statement

Managing limited parking spaces in urban environments is a growing challenge. Traditional parking systems are often slow, error-prone, and unable to provide real-time parking insights. Users waste time searching for empty spots, while administrators lack live operational data. Parkly was developed to solve these issues with a smarter, automated, and connected parking solution. :contentReference[oaicite:3]{index=3}

---

## Solution

Parkly delivers a fully automated parking system powered by IoT, wireless communication, and mobile technology. It simplifies entry and exit through NFC authentication, allows users to check and reserve parking spaces from a mobile app, and supports EV charging operations through an integrated control system. All major processes are managed through a central ESP32 microcontroller. :contentReference[oaicite:4]{index=4}

---

## Key Features

- **NFC Access Control**  
  Vehicles can enter using NFC cards, ensuring secure and authorized access only. :contentReference[oaicite:5]{index=5}

- **Mobile Application**  
  Users can view parking availability and interact with the system through a mobile interface. Pro users can reserve spots in advance. :contentReference[oaicite:6]{index=6}

- **Real-Time Parking Monitoring**  
  IR sensors detect vehicle presence and update spot availability live. The system displays current parking status in real time. :contentReference[oaicite:7]{index=7}

- **Dual Parking Zones**  
  The system separates standard parking spots and electric vehicle spots for better organization and smoother navigation. :contentReference[oaicite:8]{index=8}

- **Pro Reservation Hub**  
  Pro users can instantly reserve available parking spaces through one-tap booking. :contentReference[oaicite:9]{index=9}

- **Admin Monitoring Dashboard**  
  Administrators can monitor parking status, gate state, NFC state, fire alarm alerts, and lighting controls from a dedicated dashboard. :contentReference[oaicite:10]{index=10}

- **EV Charging Support**  
  Parkly includes smart EV charging controls with start/stop options, telemetry monitoring, and charging session details such as voltage, current, power, time, and price. :contentReference[oaicite:11]{index=11}

- **Safety Alert System**  
  The platform includes fire detection and alert mechanisms to improve operational safety and provide fail-safe protection. :contentReference[oaicite:12]{index=12}

- **Language Support**  
  The mobile app interface supports both English and Arabic. :contentReference[oaicite:13]{index=13}

---

## User Roles

### Standard User
- View available parking spaces
- Monitor standard and EV sections
- Access the main dashboard interface :contentReference[oaicite:14]{index=14}

### Pro User
- Reserve parking spots in advance
- Access integrated EV charging controls
- Use the instant reservation hub for faster booking :contentReference[oaicite:15]{index=15}

### Admin
- Monitor parking spot availability
- Track gate and NFC status
- Control lighting
- Monitor fire alerts and safety events :contentReference[oaicite:16]{index=16}

---

## Hardware Components

Parkly integrates multiple hardware modules to build a complete smart parking ecosystem:

- ESP32 DevKitC — main controller
- PN532 NFC Module — access authentication
- IR Sensors — vehicle detection
- Relay Module — motor/light control
- INA219 Sensor — power monitoring
- MAX7219 LED Matrix — visual availability display
- Servo Motors — gate control
- Lithium Batteries — main and backup power
- DC-DC Converters — voltage regulation :contentReference[oaicite:17]{index=17}

---

## System Modules

### 1. Access & Security
The gate system uses NFC authentication and servo motors to allow secure, automated entry and exit. It also integrates with IR sensors for safer operation. :contentReference[oaicite:18]{index=18}

### 2. Parking Detection
IR sensors continuously detect car presence in each parking slot and feed the data to the ESP32 for live status updates. :contentReference[oaicite:19]{index=19}

### 3. EV Charging System
The EV charging module supports smart charging actions and monitors electrical values for transparency and analytics. :contentReference[oaicite:20]{index=20}

### 4. Safety & Power Management
The system includes fire detection, audible alerts, stable voltage regulation, and resilience against electrical fluctuations. :contentReference[oaicite:21]{index=21}

---

## Mobile App Interfaces

The Parkly mobile application includes several interfaces:

- **Main Parking Dashboard** for standard users
- **Access & Login Selection** for Pro and Admin users
- **Pro Instant Reservation Hub**
- **Admin Monitoring Dashboard**
- **EV Charging Station Details Page** :contentReference[oaicite:22]{index=22}

---

## Project Goals

- Reduce time spent searching for parking
- Improve parking space utilization
- Automate entry, monitoring, and charging processes
- Enhance security and safety
- Deliver a better user experience through mobile interaction :contentReference[oaicite:23]{index=23}

---

## Technologies Used

- IoT-based parking management
- ESP32 microcontroller
- NFC authentication
- IR-based vehicle detection
- Wireless communication
- Mobile-based control and reservation
- EV charging integration :contentReference[oaicite:24]{index=24}

---

## Future Improvements

- Cloud database integration
- Analytics dashboard for usage insights
- Online payments for parking and charging
- License plate recognition
- Notification system for booking and charging events
- Multi-location parking management

---

## Project Presentation

This repository represents the **Parkly Smart Parking System**, a graduation/project-style implementation that combines embedded systems, automation, mobile control, and real-time monitoring to create a modern smart parking experience. :contentReference[oaicite:25]{index=25}

---

## Contact

For more information about the project, feel free to reach out through the repository or project presentation contact details. :contentReference[oaicite:26]{index=26}

---

## License

This project is intended for educational and demonstration purposes unless otherwise specified.
