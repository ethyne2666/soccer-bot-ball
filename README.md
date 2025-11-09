
# ⚽ Soccer Bot Ball

### 🤖 Presented by: SEAL Robotics Club  
**Project Title:** Soccer Bot Ball – Bluetooth Controlled Soccer Robot  
**Developed by:** Charan Kumar (ECE)  

---

## 🧠 Project Overview

**Soccer Bot Ball** is a Bluetooth-controlled robot built using **Arduino** and an **L298N motor driver**, designed to simulate a soccer-playing robot.  
It can move in all directions, adjust its speed, honk, and toggle LEDs — all through a mobile app interface.  

The bot was designed and programmed to **play robot soccer matches** in the SEAL Robotics Club’s **BotBall Competition**, where multiple teams controlled their robots to dribble, defend, and score goals inside a mini-arena.  

The project demonstrates practical skills in **robot motion control**, **Bluetooth communication**, and **embedded system design**, integrating both software and hardware elements seamlessly.

---

## ⚙️ How It Works

The Arduino microcontroller acts as the **central brain**, receiving commands from the mobile phone via the **HC-05 Bluetooth module**.  
Each command corresponds to a motion or function — for example:
- `'F'` → move forward  
- `'B'` → move backward  
- `'L'` → turn left  
- `'R'` → turn right  
- `'S'` → stop  
- `'Y'` → horn  
- `'0–9'` → speed control  

The **L298N motor driver** receives these control signals from Arduino and drives two DC motors accordingly, controlling both direction and speed.  

---

## 🔩 Components and Their Roles

### 🟦 1. **Arduino (UNO / Nano)**
- Acts as the **main controller** of the robot.  
- Processes commands received from the HC-05 Bluetooth module through the serial interface.  
- Sends control signals to the L298N motor driver for direction and speed control.  
- Uses PWM (Pulse Width Modulation) to regulate motor speed.  
- Provides digital outputs for controlling buzzer and LED indicators.

---

### 📡 2. **Bluetooth Module (HC-05)**
- Enables **wireless communication** between the robot and the smartphone.  
- Operates via **UART serial communication** (TX/RX pins).  
- The **TX of HC-05** is connected to **RX of Arduino**, and **RX of HC-05** to **TX of Arduino** (cross connection).  
- Communication baud rate: **9600 bps**.  

#### 🔗 Connection with Mobile App (BlueDuino)
1. **Power ON** the robot — the HC-05 LED blinks rapidly, indicating pairing mode.  
2. On your phone, open **Bluetooth settings → Pair new device → HC-05** (PIN: `1234` or `0000`).  
3. Open the **BlueDuino App** (available on Play Store).  
4. Tap **Connect** and choose the paired HC-05 module.  
5. Once connected, the LED on HC-05 blinks slowly — meaning communication is active.  
6. The app’s virtual joystick and buttons send characters (`F`, `B`, `L`, etc.) through Bluetooth serial, which Arduino interprets to control the robot in real time.  

This setup allowed us to **control the robot like a remote car** on the soccer field — passing, turning, and shooting using only a phone.

---

### ⚙️ 3. **Motor Driver Module (L298N)**
- Dual H-bridge motor driver used to **control direction and speed** of two DC motors.  
- Inputs from Arduino decide whether the motors rotate **forward**, **reverse**, or **stop**.  
- PWM pins (ENA, ENB) are used to control motor **speed** dynamically.  
- Provides **5V logic control** and separate **12V motor power input**, ensuring stability.  

---

### ⚙️ 4. **BO Motors (x2)**
- Lightweight DC geared motors designed for small robotic platforms.  
- Provide adequate **torque and speed** for fast, smooth movement.  
- Connected to the L298N’s motor outputs.  

---

### 🔋 5. **Power Supply**
- Two **9V batteries** or a **Li-ion pack** used to power the entire robot.  
- One battery powers the motor driver, the other powers Arduino and Bluetooth for noise isolation.  

---

### 🔔 6. **Buzzer**
- Acts as the **horn** of the bot.  
- Controlled by Arduino through a digital pin.  
- Produces short beeps to signal start, stop, or goal events.

---

### 💡 7. **LED (Indicator Light)**
- Optional LED indicator used for signaling or as a headlight.  
- Can be turned on/off from the mobile app.

---

### 🚗 8. **Chassis and Wheels**
- Acrylic or plastic base used to mount all components.  
- Two **driven wheels** (attached to BO motors) and one **caster wheel** for balance.  
- The design ensured stability and control even during fast turns on the soccer field.

---

## 📱 Bluetooth Control via BlueDuino

The **BlueDuino mobile app** provides a **custom Bluetooth controller interface** for Arduino-based bots.

### 🔧 App Setup
- Download **BlueDuino** from Google Play Store.  
- Pair HC-05 with your phone.  
- Open BlueDuino and connect to “HC-05”.  
- Use on-screen buttons for movement and speed control.

### 🕹️ During the Competition
During the **SEAL Robotics Club – BotBall Robo Soccer Competition**,  
the bot was controlled entirely through the **BlueDuino interface**:
- Forward movement for dribbling.  
- Quick left/right turns for dodging opponents.  
- Stop and reverse for defense.  
- The buzzer was used to signal goal or communication success.  

The Bluetooth connection remained **stable and responsive**, allowing precise real-time control during gameplay.

---

## 🏁 Conclusion

The **Soccer Bot Ball** project showcases how a simple Arduino and HC-05 module can be used to create a fully functional, wireless robot capable of controlled movement and interaction.  

This project successfully demonstrated:
- Wireless communication and serial data handling.  
- DC motor speed and direction control using PWM.  
- Integration of electronics, mechanics, and programming.  

It served as an excellent foundation for exploring **autonomous robotics**, **sensor-based navigation**, and **IoT communication** in future upgrades.

---

### 💡 Developed by
**Charan Kumar**  
Department of Electronics and Communication Engineering (ECE)  
SEAL Robotics Club  
[GitHub: ethyne2666](https://github.com/ethyne2666)
