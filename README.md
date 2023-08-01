# ESP32-S3-EYE

ESP32-S3-EYE is an image and audio processing development platform based on Espressif chips. It contains development examples that may be applied in practical applications.

## Overview

ESP32-S3-EYE provides examples such as Human Face Detection, Human Face Recognition, Cat Face Detection, Wake Word Detection, Speech Commands Recognition, etc. You can develop a variety of practical applications based on these examples.

## Hardware

![A02-en](https://user-images.githubusercontent.com/10337553/155143732-deeb9ef0-8227-4b59-8a4a-90dac969e62f.png)


![A07](https://user-images.githubusercontent.com/10337553/167303523-9fa0c80a-f047-408c-8b5f-ac5a52b9cdc2.png)

## Software
All the examples are stored in .../examples folder. Please build it with **ESP-IDF 4.4.2**
![f348cb5e-235e-468a-8372-5e6ca2c9965f](https://github.com/W00ng/ESP32-S3-HMI-V3/assets/10337553/a69f3fcd-1425-4838-94a4-f8502d2b7bf5)

### Step 1: Enter the examples folder
Open the terminal and go to any folder that stores examples (e.g. lvgl_demo):

```bash
cd ...\examples\lvgl_demo
```

### Step 2: Build the example

```bash
idf.py build
```

### Step 3: Flash and launch monitor
Flash the program and launch IDF Monitor:

```bash
idf.py flash monitor
```

## Known Issues

ESP32-S3-EYE does not have a USB-to-UART bridge, which may cause a problem: If the program flashed onto the board keeps the chip rebooting, you cannot flash more programs onto the board.

In case this issue occurs, you need to:

Hold down BOOT button and press RST button, then release RST button first, and BOOT button next. In this way, the board enters Firmware Download mode and you can start flashing program onto the board.
After flashing the program, press RST button to start the program.

## Support

if you need any help, please contact: aemails@163.com

