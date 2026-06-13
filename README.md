# Anti-Car-Sleeping Glasses

## Overview

Anti-Car-Sleeping Glasses is a driver drowsiness detection system built using an Arduino Nano, an IR eye detection sensor, a buzzer, a vibration motor, and an HC-05 Bluetooth module.

The system monitors the driver's eyelid state in real time. If the driver's eyes remain closed for more than two seconds, the glasses trigger an audible and vibration-based alert. If the driver does not respond and keeps their eyes closed, a Bluetooth alert is sent to a connected mobile application for an additional notification.

The goal of the project is to help reduce accidents caused by driver fatigue and microsleep episodes.


## Features

* Real-time eyelid monitoring
* Drowsiness detection based on prolonged eye closure
* Buzzer alert system
* Vibration motor alert system
* Bluetooth communication via HC-05
* Secondary mobile notification support
* Low-cost and lightweight hardware design


## Hardware Used

* Arduino Nano
* IR LED and IR Receiver
* HC-05 Bluetooth Module
* Buzzer
* Vibration Motor
* Battery Pack


## Working Principle

1. The IR sensor continuously monitors whether the driver's eyes are open or closed.
2. If the eyes remain closed for more than two seconds, the Arduino activates:

   * Buzzer
   * Vibration Motor
3. If the driver opens their eyes, the system resets automatically.
4. If the eyes remain closed after the initial alert, a Bluetooth message is sent to a paired mobile device.
5. The mobile device can then trigger a louder alarm or notification.


## Bluetooth Protocol

The system sends the following messages through the HC-05 module:

### Alarm Triggered

```text
ALARM_ON
```

### Drowsiness Alert

```text
DROWSY_ALERT
```

These messages can be used by a companion mobile application to provide additional notifications.


## Important Note

The mobile application used to receive Bluetooth notifications is **not included in this repository**.

This repository only contains the Arduino implementation of the project. The companion mobile application was developed separately and is therefore not available here.
