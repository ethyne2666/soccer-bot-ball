
// ----- L298N Motor Driver Pin Connections -----
#define ENA 5     // Left motor speed (PWM)
#define IN1 8     // Left motor direction
#define IN2 9
#define IN3 10    // Right motor direction
#define IN4 11
#define ENB 6     // Right motor speed (PWM)

// Optional: Buzzer and LED pins (if used)
#define BUZZER 2
#define LED A5

int valSpeed = 150;  // Reduced default speed (0–255)
char command;        // Command received from Bluetooth

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  analogWrite(ENA, valSpeed);
  analogWrite(ENB, valSpeed);

  Serial.begin(9600); // Communicate with HC-05
  Serial.println("⚽ Soccer Bot Ready!");
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    Serial.println(command);

    switch (command) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'S': stopBot(); break;
      case 'Y': horn(); break;
      case 'X': digitalWrite(LED, HIGH); break;
      case 'x': digitalWrite(LED, LOW); break;

      // Speed control (0–9)
      case '0': setSpeed(0); break;
      case '1': setSpeed(60); break;
      case '2': setSpeed(80); break;
      case '3': setSpeed(100); break;
      case '4': setSpeed(120); break;
      case '5': setSpeed(140); break;
      case '6': setSpeed(150); break;
      case '7': setSpeed(160); break;
      case '8': setSpeed(175); break;
      case '9': setSpeed(190); break;
    }
  }
}

void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void stopBot() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}

void horn() {
  digitalWrite(BUZZER, HIGH);
  delay(200);
  digitalWrite(BUZZER, LOW);
}

void setSpeed(int spd) {
  valSpeed = spd;
  analogWrite(ENA, valSpeed);
  analogWrite(ENB, valSpeed);
}
