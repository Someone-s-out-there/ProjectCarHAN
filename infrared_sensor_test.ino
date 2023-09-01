#define sensor1 8   // Sensor 1 op pin D8
#define sensor2 9   // Sensor 2 op pin D9
#define sensor3 10  // Sensor 3 op pin D10
#define sensor4 11  // Sensor 4 op pin D11

int sensorState1 = 0;
int sensorState2 = 0;
int sensorState3 = 0;
int sensorState4 = 0;

long refreshRateIR = 100;

void setup() {
  Serial.begin(9600);

  // Sensor pinnen instellen als input
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
}

void loop() {
  // Leest constant de waarde van de pinnen af. 1 = zwart, 0 = wit
  sensorState1 = digitalRead(sensor1);
  sensorState2 = digitalRead(sensor2);
  sensorState3 = digitalRead(sensor3);
  sensorState4 = digitalRead(sensor4);

  // Print de afgelezen waarde in de serial monitor
  Serial.print(sensorState1);
  Serial.print(sensorState2);
  Serial.print(sensorState3);
  Serial.println(sensorState4);

  delay(refreshRateIR);
}
