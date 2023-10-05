#define trigPin 9
#define echoPin 8

long duration;
int distance;
int refreshRateUS;
int i = 0;

int readings[4];
int average;

void calculateAverage(int distance)
{
  readings[i] = distance;
  i++;

  if (i = 3)
  {
    average = (readings[0] + readings[1] + readings[2] + readings[3]) / 4;
    i = 0;

    Serial.println(average);
  }
}

void setup() {
  Serial.begin(9600);

  // Trigger pin als output en echo pin als input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Waarom de triggerpin eerst 2 microseconden uit staat is een beetje onduidelijk
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Stuurt een geluidsgolf van 10 microseconden lang uit
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Checkt hoelang het duurt voordat de echo pin een input geeft
  duration = pulseIn(echoPin, HIGH);

  // Omrekenen van tijd naar afstand
  distance = duration / 29 / 2;

  calculateAverage(distance);

  // Print afstand in serial monitor
  // Serial.print("Distance: ");
  // Serial.println(distance);

  // delay(refreshRateUS);

}
