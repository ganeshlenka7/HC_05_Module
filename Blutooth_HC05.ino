char data;          // to store received data
int lightPin = 13;   // Pin connected to light/LED/Relay

void setup() {
  Serial.begin(9600);      // Bluetooth default baud rate
  pinMode(lightPin, OUTPUT);
  digitalWrite(lightPin, LOW); // Light OFF initially
}

void loop() {
  if (Serial.available()) {        // if data is available to read
    data = Serial.read();          // read it and store in 'data'

    if (data == '1') {             // if '1' received
      digitalWrite(lightPin, HIGH); // turn ON light
      Serial.println("Light ON");
    }
    else if (data == '0') {        // if '0' received
      digitalWrite(lightPin, LOW);  // turn OFF light
      Serial.println("Light OFF");
    }
  }
}
