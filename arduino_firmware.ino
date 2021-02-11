//arduino pro micro
//https://www.drive2.ru/b/576063005045818805/
#define wipesRead A3
#define relay 2
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(wipesRead, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  Serial.begin(115200);
  delay(500);

}
// the loop function runs over and over again forever
void loop() {
  delay(2500);
  int count = 0;

  int wipesR = analogRead(wipesRead);
  float volts = wipesR / 224.6;
  Serial.print("\t Voltage = ");
  Serial.println (volts);
  Serial.print("\t analpgRead = ");
  Serial.println (wipesR);
  if (volts >= 0.9  && volts <= 5.5 ) {
    if (volts >= 3.51  && volts <= 5.5 && count == 1) {
      digitalWrite(relay, HIGH);
      delay(500);
      digitalWrite(relay, LOW);
      Serial.println("2 second");
      delay(500);
    } else if (volts >= 3 && volts <= 3.5 ) {
      digitalWrite(relay, HIGH);
      delay(500);
      digitalWrite(relay, LOW);
      Serial.println("4 second");
      delay(1500);
    }
    else if (volts >= 2.61 && volts <= 2.99) {
      digitalWrite(relay, HIGH);
      delay(500);
      digitalWrite(relay, LOW);
      Serial.println("10 second");
      delay(5500);
    } else if (volts > 2.4 && volts <= 2.6) {
      digitalWrite(relay, HIGH);
      delay(500);
      digitalWrite(relay, LOW);
      Serial.println("15 second");
      delay(13000);

    } else if (volts >= 1 && volts <= 2.39) {
      digitalWrite(relay, HIGH);
      delay(500);
      digitalWrite(relay, LOW);
      Serial.println("21 second");
      delay(18000);
    }
    count = 1;

  } else if (volts <= 0.9) {
    Serial.println("auto is disable");
    count = 0;

  }
}
