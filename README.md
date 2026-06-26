# Parkly
**Smart Parking System using IoT, NFC Access, Real-Time Monitoring, and EV Charging**
![WhatsApp Image 2026-02-01 at 6 46 34 PM](https://github.com/user-attachments/assets/e8269b9d-b1cf-48c1-9e4f-45eab901d944)

Parkly is an IoT-based smart parking system that automates vehicle entry, tracks parking availability in real time, and improves user experience through a mobile application. It combines **NFC authentication**, **IR-based vehicle detection**, **ESP32 control**, **admin monitoring**, and **EV charging support** in one integrated solution.

---

## Key Features

- **NFC Access Control** for authorized vehicle entry
- **Real-Time Spot Monitoring** using IR sensors
- **Mobile App Support** for viewing and reserving spots
- **Standard / Pro User Modes**
- **Admin Dashboard** for live monitoring and control
- **EV Charging Management** with telemetry and charging controls
- **Fire Alert & Safety System**
- **English / Arabic Language Support**

---

## How It Works

Parkly uses an **ESP32 DevKitC** as the main controller to connect sensors, access modules, charging units, and gate mechanisms.  
The system detects parking occupancy, updates spot availability, controls vehicle access through NFC cards, and allows users to interact with parking and charging services from a mobile app.

---

## System Modules

### 1. Access & Security
- PN532 NFC authentication
- Automated gate control using servo motors
- Secure access for Pro/Admin users

### 2. Parking Detection
- IR sensors detect vehicle presence
- Live availability updates for each parking slot
- Visual display through LED matrix / app dashboard

### 3. Mobile Application
- View available parking spots
- Reserve spots as a Pro user
- Access EV charging and system settings
- Language switching between English and Arabic

### 4. EV Charging
- Start / Stop / Wireless charging controls
- Voltage, current, and power monitoring
- Charging session details for time and billing visibility

### 5. Admin Monitoring
- Parking status overview
- Gate and NFC status tracking
- Fire alarm and safety alerts
- Light control and system supervision

### 6. Safety & Power Management
- Flame detection with buzzer alert
- Stable voltage regulation using buck converters
- Backup power support with lithium batteries

---

## Hardware Components

| Component | Function |
|---|---|
| ESP32 DevKitC | Main controller |
| PN532 NFC Module | NFC authentication |
| IR Sensors | Vehicle detection |
| Relay Module | Controls motors, lights, and charging actions |
| INA219 Sensor | Voltage, current, and power monitoring |
| MAX7219 LED Matrix | Parking availability display |
| Servo Motors | Gate operation |
| Lithium Batteries | Main and backup power |
| LM2596 / DC-DC Converters | Voltage regulation |
| KY-026 Flame Sensor | Fire detection |
| Buzzer | Local alarm |
| Wireless Charging Coil | EV wireless charging |
| 2N2222 Transistor | Switching in charging circuit |

---

## User Roles

### Standard User
- View available parking spots

### Pro User
- Reserve parking spots
- Access EV charging options

### Admin
- Monitor parking, gates, NFC, safety alerts, and lighting

---

## Project Goal

To build a modern smart parking solution that:
- reduces manual parking operations,
- improves parking efficiency,
- enhances user convenience,
- and supports future smart city infrastructure.

---

## Tech Stack

- **ESP32**
- **NFC (PN532)**
- **IR Sensors**
- **INA219 Power Monitoring**
- **Relay + Servo Control**
- **Mobile App Interface**
- **IoT / Wireless Communication**

---

## Future Improvements

- Cloud database integration
- Online booking and payment
- License plate recognition
- Analytics dashboard
- Multi-location parking management

---

## Collaboration Notes

This project is open to collaborative improvements, including documentation updates, feature planning, hardware testing notes, and mobile app workflow refinements.

---

## Project Status

This repository documents the current Parkly prototype, including the IoT hardware modules, mobile app features, user roles, and planned future improvements.

The project is still under development, and future updates may include cloud integration, online booking, payment support, license plate recognition, and analytics.

---

## License

This project is for **educational and demonstration purposes**
