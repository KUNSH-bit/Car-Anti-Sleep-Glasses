#include <SoftwareSerial.h>

// HC-05 Bluetooth
SoftwareSerial BT(10, 11); // RX, TX

// Pins
const int IR_SENSOR = 2;
const int BUZZER = 3;
const int VIBRATION = 4;

// Timing
const unsigned long EYE_CLOSED_TIME = 2000;   // 2 seconds
const unsigned long PHONE_ALERT_DELAY = 5000; // 5 seconds after alarm

bool eyesClosed = false;
bool alarmActive = false;
bool phoneAlertSent = false;

unsigned long closeStartTime = 0;
unsigned long alarmStartTime = 0;

void setup() {
  pinMode(IR_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(VIBRATION, OUTPUT);

  digitalWrite(BUZZER, LOW);
  digitalWrite(VIBRATION, LOW);

  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Drowsiness Detection System Started");
}

void loop() {

  int eyeState = digitalRead(IR_SENSOR);

  // Assuming:
  // HIGH = Eye Open
  // LOW = Eye Closed

  if (eyeState == LOW) {

    if (!eyesClosed) {
      eyesClosed = true;
      closeStartTime = millis();
      Serial.println("Eyes Closed");
    }

    unsigned long closedDuration = millis() - closeStartTime;

    // Trigger alarm after 2 seconds
    if (closedDuration >= EYE_CLOSED_TIME && !alarmActive) {

      alarmActive = true;
      alarmStartTime = millis();

      digitalWrite(BUZZER, HIGH);
      digitalWrite(VIBRATION, HIGH);

      Serial.println("DROWSINESS DETECTED");
      BT.println("ALARM_ON");
    }

    // Send phone alert if alarm didn't work
    if (alarmActive &&
        !phoneAlertSent &&
        (millis() - alarmStartTime >= PHONE_ALERT_DELAY)) {

      BT.println("DROWSY_ALERT");

      Serial.println("PHONE ALERT SENT");

      phoneAlertSent = true;
    }

  } else {

    // Eyes Open

    if (eyesClosed) {
      Serial.println("Eyes Open");
    }

    eyesClosed = false;
    alarmActive = false;
    phoneAlertSent = false;

    digitalWrite(BUZZER, LOW);
    digitalWrite(VIBRATION, LOW);
  }

  delay(50);
}
