#define trigPin 9
#define echoPin 8

int distance;
int refreshRateUS= 100;


class HRSR04{
    public:
        HRSR04(int Trigger, int Echo):_Trigger(Trigger), _Echo(Echo){}
        ~HRSR04()=default;
        void init(){
            pinMode(_Trigger, OUTPUT);
            pinMode(_Echo, INPUT);
        }
        int getDist(){
            // Waarom de triggerpin eerst 2 microseconden uit staat is een beetje onduidelijk
            digitalWrite(_Trigger, LOW);
            delayMicroseconds(2);

            // Stuurt een geluidsgolf van 10 microseconden lang uit
            digitalWrite(_Trigger, HIGH);
            delayMicroseconds(10);
            digitalWrite(_Trigger, LOW);

            // Checkt hoelang het duurt voordat de echo pin een input geeft
            // duration = pulseIn(echoPin, HIGH);

            // Omrekenen van tijd naar afstand
            return (pulseIn(_Echo,HIGH)/2)/29;


        }

    private:
        int _Trigger,_Echo;

}






HRSR04 hrsr(9,8);

void setup() {
  Serial.begin(9600);

  hrsr.init();

  // Trigger pin als output en echo pin als input
}

void loop() {
    //hrsr.getDist();

    // Print afstand in serial monitor
    Serial.print("Distance: ");
    Serial.println(hrsr.getDist());

    delay(refreshRateUS);

}
