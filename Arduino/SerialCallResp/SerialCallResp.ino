int sensor1;
int sensor2;
int sensor3;

void setup() {
  Serial.begin(9600);
  sensor1 = random(255.0);
  sensor2 = random(255.0);
  sensor3 = random(255.0);
}

void loop() {
  // sensor1 = analogRead(A0);
  // sensor2 = analogRead(A1);
  // sensor3 = analogRead(A2);
//   sensor1 += 0.001;
//  if(sensor1>255){
//    sensor1 = 0.0;
//  }
//   sensor2 += 0.001;
//  if(sensor2>255){
//    sensor2 = 0.0;
//  }
//   sensor3 += 0.001;
// if(sensor3>255){
//    sensor3 = 0.0;
//  }

  if (Serial.available() > 0) {
    int incoming = Serial.read();
    Serial.print(sensor1);
    Serial.print(",");
    Serial.print(sensor2);
    Serial.print(",");
    Serial.print(sensor3);
    Serial.print('\n');
  }
}
