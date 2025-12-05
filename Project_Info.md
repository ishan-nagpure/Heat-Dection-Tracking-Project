# Non Contact Heat Detection and Tracking Project
Automatically find, follow, and monitor any heat source with this project, a smart, servo-driven device that brings thermal tracking to your workbench. Whether you're a hobbyist looking for a captivating project, a student exploring robotics, or a technician needing a simple monitoring solution, this project is your eye in the world of heat.

This project is built on the powerful ESP32 platform, making it a fantastic educational tool for learning about sensors, robotics, and real-time control systems.

## **Features :**

Automatic 180° Scanning: The turret continuously pans across a 180-degree arc to search for heat signatures.

Precise Target Locking: Utilizes a Melexis MLX90614-DCI sensor with a narrow 35° Field of View (FOV) to isolate and lock onto specific heat sources.

Real-Time Tracking: Gives real time Teprature and Distance of the traget.

Audible and Visible Alarm: An onboard buzzer and LEDs provides an immediate alert when a target's temperature surpasses a pre-defined critical limit.

Serial Data Monitoring: Outputs live temperature and position data to the Serial Monitor for debugging and monitoring.

## **How It Works:**

The system operates in a continuous loop with a simple but effective logic:

Scan Mode: The pan servo sweeps from 0 to 180 degrees. At each step, the MLX90614 sensor takes a temperature reading.

Detect Mode: If a temperature reading exceeds the HEAT_THRESHOLD or distance is less than DISTANCE_THRESHOLD, the system stops scanning and locks onto that bearing. 

Alarm Mode: If the locked-on temperature exceeds the HEAT_THRESHOLD or objects breakes DISTANCE_THRESHOLD, the buzzer and LED is activated to signal a critical event.

Reset: If the heat source is lost (temperature drops below the threshold), the system returns to Scan Mode.

<img width="650" height="726" alt="flowchart" src="https://github.com/user-attachments/assets/67d4b7fa-3de0-4978-9582-d84aa42fb640" />



## Hardware Components:
| Component  | Quantity | Note |
| ------------- | ------------- | ------------- |
| ESP32 Development Board  | 1 | Any dev board will work|
| Melexis MLX90614-DCI  | 1  | FOV of 35° |
| HC-SR04 sensor| 1 |  Ultrasonic distance sensor |
| SG90 Micro Servo Motor | 1 | Positional Rotation Servos |
| Buzzer | 1 | 3.3V or 5V would work |
| LEDs | 2 | Red & Green |

## Circuit Diagram

![Heat D T_schem_led_page-0001](https://github.com/user-attachments/assets/a817f249-b1db-4930-8627-c1e4d23acbe2)


The IO connections may not be accurate to your dev board.

## Limitations and Precautions 

1.Ensure stable power supply and proper wiring to avoid false alarms.

2.Never paint or cover the sensor.

3.Keep surface clean and scratch-free.

4.Inaccurate in dusty or foggy conditions.

5.The if the distance increases then the sensors might give inaccurate reading.


