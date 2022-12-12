void setup() {
  pinMode(2, INPUT_PULLUP);
  // pinMode(2, INPUT); // USE input if you have 10k Pulldown resistors
  Serial.begin(9600);
}

void loop() {
  int button = digitalRead(2);
  int sensor1 = analogRead(A0);
  int sensor2 = analogRead(A1);

  Serial.print(button);
  Serial.print(',');
  Serial.print(sensor1);
  Serial.print(',');
  Serial.println(sensor2);
}
