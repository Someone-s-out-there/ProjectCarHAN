#define trigPin 9
#define echoPin 8

uint32_t duration;
uint8_t distance;
uint8_t refreshRateUS = 10;

constexpr uint8_t FILTER_SHIFT = 4U; // Parameter K
uint16_t
simpleRecursiveFilter(uint16_t filterInput) {
        static uint16_t filterReg; // Delay element - 32 bits

        filterReg = filterReg - (filterReg >> FILTER_SHIFT) + filterInput;
        // Scale output for unity gain.
        return (filterReg >> FILTER_SHIFT);
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
  distance = duration / 58;
  
    uint16_t tmp = simpleRecursiveFilter(distance);

  // Print afstand in serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(", Duration: ");
  Serial.print(duration);
  Serial.print(", AVG: ");
  Serial.println(tmp);

  // kleine delay, ter voorkoming van afwijkende metingen 
   delay(refreshRateUS);
}
