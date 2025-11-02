# 🚀 ESP32 ↔ STM32F4-Discovery UART Communication# IoT-Bridge: ESP32 to STM32 MQTT Communication



**Simple LED Control via UART - NO Resistors Needed!****Project Name:** IoT-Bridge  

**Version:** 1.0  

[![Platform](https://img.shields.io/badge/ESP32-DevBoard-blue)](https://www.espressif.com/en/products/socs/esp32)**Author:** AZIZ  

[![Platform](https://img.shields.io/badge/STM32-F4Discovery-green)](https://www.st.com/en/evaluation-tools/stm32f4discovery.html)**Date:** October 2025

[![Protocol](https://img.shields.io/badge/Protocol-UART-orange)](https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter)

[![Status](https://img.shields.io/badge/Status-Working-success)](https://github.com)A wireless IoT project demonstrating MQTT communication between ESP32 and STM32 Nucleo-L476RG. Control the STM32 LED remotely via button press or MQTT commands from anywhere!



---## 📋 Project Overview



## 📋 Table of Contents- **ESP32**: Reads button state and sends commands via UART

- **STM32 Nucleo-L476RG**: Receives commands and controls LED

- [Overview](#overview)- **Communication**: UART at 9600 baud

- [Features](#features)- **Protocol**: 'L' = LED ON, 'F' = LED OFF

- [Hardware Requirements](#hardware-requirements)

- [Wiring](#wiring)## 🛠️ Hardware Requirements

- [Software Setup](#software-setup)

- [How It Works](#how-it-works)- ESP32 Development Board (any variant with BOOT button)

- [Testing](#testing)- STM32 Nucleo-L476RG Board

- [Troubleshooting](#troubleshooting)- 2x Jumper Wires (Male-to-Male or Female-to-Female depending on your boards)

- 2x USB Cables (for programming and power)

---

## 🔌 Wiring Connections

## 🎯 Overview

| ESP32 Pin | STM32 Pin | Description |

This project demonstrates simple and reliable UART communication between an ESP32 and STM32F4-Discovery board. Press a button on the ESP32 to control an LED on the STM32 - no external resistors required!|-----------|-----------|-------------|

| GPIO17 (TX) | PA3 (RX) | Serial data transmission |

**Key Achievement:** Simple 2-wire communication without any external components.| GND | GND | Common ground (REQUIRED!) |



---**Note**: The button is built into the ESP32 (BOOT button on GPIO0), and the LED is built into the STM32 (LD2 on PA5).



## ✨ FeaturesSee [WIRING.md](WIRING.md) for detailed connection diagram.



- ✅ **Simple UART Communication** - Only 2 wires needed## 📁 Project Structure

- ✅ **NO External Resistors** - Direct connection

- ✅ **Button Control** - Press BOOT button on ESP32 to control STM32 LED```

- ✅ **Real-time Feedback** - Serial Monitor shows all communicationPROJECTCV/

- ✅ **Beginner Friendly** - Complete step-by-step instructions├── ESP32/

- ✅ **Reliable** - 9600 baud, 8N1 configuration│   └── esp32_button_sender.ino    # Arduino code for ESP32

├── STM32/

---│   └── Core/

│       ├── Inc/

## 🛠️ Hardware Requirements│       │   ├── main.h

│       │   └── stm32l4xx_it.h

### Required Components:│       └── Src/

│           ├── main.c

| Component | Description | Quantity |│           └── stm32l4xx_it.c

|-----------|-------------|----------|├── WIRING.md                       # Detailed wiring diagram

| **ESP32** | Any ESP32 Dev Board | 1 |└── README.md                       # This file

| **STM32F4-Discovery** | STM32F407VGT6 | 1 |```

| **Jumper Wires** | Male-to-Male or Male-to-Female | 2 |

| **USB Cables** | Micro-B (ESP32) + Mini-B (STM32) | 2 |## 🚀 Setup Instructions



### Built-in Components Used:### Part 1: ESP32 Setup (Arduino IDE)



- **ESP32 BOOT Button** (GPIO0) - Input1. **Install Arduino IDE** (if not already installed)

- **STM32 Green LED** (PD12 / LD4) - Output   - Download from: https://www.arduino.cc/en/software



**Total Cost:** ~$20-30 (if you already have the boards)2. **Install ESP32 Board Support**

   - Open Arduino IDE

---   - Go to `File` → `Preferences`

   - Add to "Additional Board Manager URLs":

## 🔌 Wiring     ```

     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

### Connection Diagram:     ```

   - Go to `Tools` → `Board` → `Boards Manager`

```   - Search for "ESP32" and install "esp32 by Espressif Systems"

┌──────────────┐                    ┌──────────────────┐

│   ESP32      │                    │  STM32F4-Discovery│3. **Upload ESP32 Code**

│              │                    │                  │   - Open `ESP32/esp32_button_sender.ino`

│   GPIO17 ────┼────────────────────┤ PA3 (D0)         │   - Select your ESP32 board: `Tools` → `Board` → `ESP32 Arduino` → (your board model)

│   (TX)       │    Wire 1          │ (USART2_RX)      │   - Select the correct COM port: `Tools` → `Port` → (your ESP32 port)

│              │                    │                  │   - Click `Upload` button (→)

│   GND ───────┼────────────────────┤ GND              │

│              │    Wire 2          │                  │4. **Test ESP32**

└──────────────┘                    └──────────────────┘   - Open Serial Monitor (`Tools` → `Serial Monitor`)

```   - Set baud rate to `115200`

   - You should see "ESP32 Button Sender Started"

### Detailed Connections:

### Part 2: STM32 Setup (STM32CubeIDE)

| ESP32 Pin | → | STM32 Pin | Description |

|-----------|---|-----------|-------------|1. **Install STM32CubeIDE** (if not already installed)

| **GPIO17** | → | **PA3** (D0) | UART TX → RX |   - Download from: https://www.st.com/en/development-tools/stm32cubeide.html

| **GND** | → | **GND** | Common Ground |

2. **Create New STM32 Project**

### Pin Location Tips:   - Open STM32CubeIDE

   - `File` → `New` → `STM32 Project`

**ESP32:**   - Select Board: `NUCLEO-L476RG`

- GPIO17 is labeled "17" or "TX2" on most boards   - Project name: `STM32_UART_LED`

- GND pins are usually labeled clearly   - Click `Finish`



**STM32F4-Discovery:**3. **Configure STM32CubeMX**

- **PA3** can be found on the Arduino headers as **D0** or **RX**   - In the `.ioc` file (automatically opened):

- Look for the digital pin headers (D0, D1, D2...)   - **System Core → RCC**: Set HSE to "Crystal/Ceramic Resonator" (optional)

- GND is available on multiple pins   - **Connectivity → USART2**:

     - Mode: Asynchronous

---     - Baud Rate: 9600

     - Word Length: 8 Bits

## 💻 Software Setup     - Parity: None

     - Stop Bits: 1

### 1️⃣ ESP32 Setup (Arduino IDE)   - **System Core → GPIO**:

     - PA5 is already configured as LED (LD2)

**Requirements:**   - Click `Ctrl+S` to save and generate code

- Arduino IDE 1.8.x or 2.x

- ESP32 Board Support installed4. **Replace Generated Files**

   - Copy files from `STM32/Core/Src/` to your project's `Core/Src/` folder

**Steps:**   - Copy files from `STM32/Core/Inc/` to your project's `Core/Inc/` folder

   - Or manually copy the code from `main.c` into your generated `main.c`

1. Open `ESP32/ESP32_UART_Simple.ino` in Arduino IDE

5. **Build and Upload**

2. Configure Arduino IDE:   - Click `Build` (hammer icon)

   - **Tools** → **Board** → **ESP32 Dev Module**   - Connect STM32 Nucleo via USB

   - **Tools** → **Port** → Select your ESP32 port   - Click `Run` (play icon) or `Debug`

   - **Tools** → **Upload Speed** → 115200   - The code will be uploaded to your STM32



3. Click **Upload** (➡️ button)### Alternative: Using Mbed for STM32



4. Open **Serial Monitor** (Tools → Serial Monitor)If you prefer using Mbed Online Compiler or Mbed Studio:

   - Set baud rate to **115200**

1. Create a new project for NUCLEO-L476RG

**Expected Serial Output:**2. Implement the same logic as in `main.c`

```3. Use Mbed's `Serial` and `DigitalOut` classes

╔════════════════════════════════════╗

║  ESP32 → STM32 UART (Simple!)     ║## 🔧 Hardware Setup

╚════════════════════════════════════╝

1. **Connect the wires** according to the wiring diagram

✓ UART: 9600 baud2. **Power both boards** via USB

✓ TX: GPIO17 → STM32 PA33. **Ensure common ground** connection is made

✓ Button: GPIO0

## ✅ Testing

Press BOOT button!

```1. Both boards should be powered and programmed

2. Press the **BOOT button** on ESP32

---3. The **green LED (LD2)** on STM32 should turn **ON**

4. Release the button

### 2️⃣ STM32 Setup (STM32CubeIDE)5. The LED should turn **OFF**



**Requirements:**### Debugging

- STM32CubeIDE

- STM32F4-Discovery board drivers**If LED doesn't turn on:**



**Quick Steps:**1. Check wiring connections (especially GND!)

2. Verify both boards are powered

1. Open STM32CubeIDE3. Check ESP32 Serial Monitor for "Command sent" messages

4. Verify baud rates match (9600 on both sides)

2. Create new STM32 project:5. Test UART connection:

   - **File** → **New** → **STM32 Project**   - Short RX and TX on STM32 temporarily

   - Select **STM32F4DISCOVERY** board   - Send data from STM32, it should receive its own data

   - Project name: `UART_LED_Control`

**ESP32 Serial Monitor Output:**

3. Configure USART2 in CubeMX:```

   - **Connectivity** → **USART2** → Mode: **Asynchronous**ESP32 Button Sender Started

   - Baud Rate: **9600**Ready! Press BOOT button to send command to STM32

   - Word Length: **8 Bits**Button pressed! Sending command to STM32...

   - Parity: **None**Command sent: L (LED ON)

   - Stop Bits: **1**Button released! Sending command to STM32...

   - Mode: **Receive Only**Command sent: F (LED OFF)

```

4. Configure LED Pin (PD12):

   - Should be auto-configured as **LD4**## 📚 How It Works

   - If not: Set **PD12** as **GPIO_Output**

1. **ESP32 Side**:

5. Generate code (Ctrl+S)   - Continuously monitors BOOT button (GPIO0)

   - Uses debouncing to avoid false triggers

6. Use the code structure from `STM32F4_DISCOVERY/main.c` as reference:   - When button is pressed: sends 'L' via UART (Serial2)

   ```c   - When button is released: sends 'F' via UART

   // In USER CODE BEGIN PV:

   uint8_t uartRxData = 0;2. **STM32 Side**:

      - Continuously listens on USART2 (PA3)

   // In USER CODE BEGIN 2:   - When 'L' is received: turns LED ON (PA5 HIGH)

   HAL_GPIO_WritePin(GPIOD, LD4_Pin, GPIO_PIN_RESET);   - When 'F' is received: turns LED OFF (PA5 LOW)

   

   // In while(1) loop USER CODE BEGIN 3:## 🔄 Protocol

   if (HAL_UART_Receive(&huart2, &uartRxData, 1, 100) == HAL_OK) {

       if (uartRxData == 'L')| Command | Meaning | Action |

           HAL_GPIO_WritePin(GPIOD, LD4_Pin, GPIO_PIN_SET);|---------|---------|--------|

       else if (uartRxData == 'F')| `'L'`   | LED ON  | Turn on PA5 (LED) |

           HAL_GPIO_WritePin(GPIOD, LD4_Pin, GPIO_PIN_RESET);| `'F'`   | LED OFF | Turn off PA5 (LED) |

   }

   ```## 🎓 Learning Resources



7. Build project (Ctrl+B)- [ESP32 Arduino Core Documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/)

- [STM32 HAL Documentation](https://www.st.com/en/embedded-software/stm32cube-mcu-mpu-packages.html)

8. Upload to STM32:- [UART Communication Basics](https://learn.sparkfun.com/tutorials/serial-communication/all)

   - Right-click project → **Run As** → **STM32 C/C++ Application**

## 🛠️ Customization Ideas

---

1. **Add more commands**: Control multiple LEDs or peripherals

## 🔄 How It Works2. **Bidirectional communication**: STM32 can send data back to ESP32

3. **Add more buttons**: Control different functions

### Communication Protocol:4. **Use external LED**: Connect LED to any GPIO pin

5. **Implement protocol**: Add start/stop bytes, checksums, etc.

**ESP32 (Master) → STM32 (Slave)**

## ⚠️ Troubleshooting

| Action | ESP32 Sends | STM32 Receives | STM32 Action |

|--------|-------------|----------------|--------------|| Problem | Solution |

| Button Press | `'L'` (0x4C) | `'L'` | LED ON ||---------|----------|

| Button Release | `'F'` (0x46) | `'F'` | LED OFF || ESP32 won't upload | Hold BOOT button while uploading |

| STM32 won't program | Install ST-Link drivers, check USB cable |

### Technical Details:| No Serial output | Check baud rate, COM port selection |

| LED doesn't respond | Verify GND connection, check wiring |

- **Protocol:** UART (Universal Asynchronous Receiver-Transmitter)| Intermittent operation | Add pull-up/down resistors, check power supply |

- **Baud Rate:** 9600 bps

- **Data Bits:** 8## 📝 Notes

- **Parity:** None

- **Stop Bits:** 1- Both boards operate at 3.3V logic levels - safe for direct connection

- **Flow Control:** None- Always connect GND between boards for UART communication

- **Direction:** ESP32 TX → STM32 RX (one-way)- The BOOT button on ESP32 is active LOW (pressed = LOW)

- The built-in LED (LD2) on STM32 is on PA5

### Code Flow:

## 📄 License

**ESP32 Side:**

```This project is open source and available for educational purposes.

1. Wait for button press

2. Debounce (50ms)## 🤝 Contributing

3. Send 'L' via Serial2 (GPIO17)

4. Show message on Serial MonitorFeel free to modify and improve this project for your needs!

5. Wait for button release

6. Send 'F' via Serial2---

```

**Created**: October 2025  

**STM32 Side:****Platform**: ESP32 + STM32 Nucleo-L476RG  

```**Communication**: UART Serial

1. Wait for UART data (100ms timeout)
2. Receive 1 byte
3. Check if 'L' → Turn LED ON
4. Check if 'F' → Turn LED OFF
5. Repeat
```

---

## 🧪 Testing

### Step-by-Step Test:

1. **Power Up:**
   - Connect both boards via USB
   - STM32 LED should be OFF initially

2. **Open Serial Monitor:**
   - Arduino IDE → Tools → Serial Monitor
   - Set to **115200 baud**

3. **Press BOOT Button (ESP32):**
   - Serial Monitor shows: `🔘 PRESSED!`
   - Serial Monitor shows: `→ Sent: 'L' (LED ON)`
   - **STM32 Green LED turns ON** ✅

4. **Release BOOT Button:**
   - Serial Monitor shows: `🔘 RELEASED!`
   - Serial Monitor shows: `→ Sent: 'F' (LED OFF)`
   - **STM32 Green LED turns OFF** ✅

5. **Repeat:**
   - Press/release multiple times
   - LED should respond instantly

### Success Indicators:

- ✅ Serial Monitor shows button events
- ✅ LED responds to button press/release
- ✅ No errors in Serial Monitor
- ✅ LED turns ON/OFF instantly

---

## 🔧 Troubleshooting

### Problem: LED doesn't respond to button

**Possible Causes:**

1. **Wrong Wiring**
   - ✅ Check: GPIO17 → PA3 (D0)
   - ✅ Check: GND → GND
   - ✅ Ensure good connections

2. **Baud Rate Mismatch**
   - ✅ ESP32: 9600 (in Serial2.begin)
   - ✅ STM32: 9600 (in USART2 config)
   - ❌ Don't use 115200 on STM32!

3. **Wrong Pin on STM32**
   - ✅ Use PA3 (also labeled D0 or RX)
   - ❌ Not PA2, PA10, or other pins

4. **Missing while(1) loop**
   - ✅ UART receive code must be inside `while(1) { }`

---

### Problem: Serial Monitor shows "PRESSED" but no LED change

**Solution:**
- STM32 is not receiving data
- Check wiring: GPIO17 must connect to PA3 (D0)
- Verify USART2 is configured in CubeMX
- Verify baud rate is 9600 on both sides

---

### Problem: Serial Monitor shows garbage

**Solution:**
- Wrong baud rate selected
- Set Serial Monitor to **115200** (not 9600!)
- 9600 is only for ESP32↔STM32 communication

---

### Problem: STM32 upload fails

**Solutions:**
1. Press **RESET** button on STM32
2. Use **Run** mode instead of **Debug**
3. Unplug/replug USB cable
4. Check ST-LINK drivers installed

---

## 📊 Performance

- **Response Time:** < 100ms
- **Reliability:** 100% with proper wiring
- **Range:** Limited by wire length (~1-2m recommended)
- **Power:** Low power consumption

---

## 🎓 Learning Outcomes

From this project, you've learned:

- ✅ UART serial communication basics
- ✅ ESP32 GPIO and button handling
- ✅ STM32 HAL library usage
- ✅ Debugging embedded systems
- ✅ Hardware interfacing without external components

---

## 🚀 Next Steps

Want to expand this project?

1. **Add More LEDs:** Control multiple LEDs with different commands
2. **Bi-directional:** Add STM32→ESP32 communication
3. **Multiple Commands:** Send numbers, strings, or JSON
4. **Wireless:** Replace UART with WiFi/Bluetooth
5. **Sensors:** Read sensors and send data between boards

---

## 📁 Project Structure

```
PROJECTCV/
├── README.md                    # This file
├── ESP32/
│   └── ESP32_UART_Simple.ino   # ESP32 code (Arduino)
└── STM32F4_DISCOVERY/
    └── main.c                   # STM32 code (reference)
```

---

**Made with ❤️ for the embedded community**

*Last Updated: November 2025*
