# Wall Follower
---
Arduino Uno based wall-follower robot

![2023-04-19_14-29](https://user-images.githubusercontent.com/77029165/233075361-f7e812b8-99c4-4b1b-a623-f74817de1faa.png)


### Power supply
- 6 AA batteries connected in series to achieve 9V with decent operating time

### Arduino Shield
- Shield with built in [DRV8835 driver](https://botland.store/arduino-shield-motor-controllers/2671-drv8835-dual-2-channel-motor-driver-11v12-a-shield-for-arduino-pololu-2511-5903351244848.html)

### DC Motors
Given the weight of robot (400g), material and radius of wheels (32.5mm)
the minimal torque was calculated

![2023-04-19_15-18](https://user-images.githubusercontent.com/77029165/233096668-f3187669-8325-40c9-9329-4dbdff317f40.png)

Just 2 cheap [DNG-16016 motors](https://botland.store/geared-dc-angle-motors/16016-dc-motor-with-148-gear-3-6v-with-double-sided-shaft-200rpm-5904422344078.html) with 0.8 kg\*cm torque will suffice

### Sensors
- 2 anolog optical distance [sensors](https://botland.store/analog-distance-sensors/29-sharp-gp2y0a21yk0f-analog-distance-sensor-10-80cm-5904422304713.html)
