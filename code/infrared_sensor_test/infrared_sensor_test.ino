#define sensor1 2   // Sensor 1 op pin D8
#define sensor2 3   // Sensor 2 op pin D9
#define sensor3 4  // Sensor 3 op pin D10
#define sensor4 5  // Sensor 4 op pin D11

int sensorState1 = 0;
int sensorState2 = 0;
int sensorState3 = 0;
int sensorState4 = 0;

long refreshRateIR = 100;

class IR{
    public:
    IR(char ir1,char ir2,char ir3,char ir4): _ir1(ir1),_ir2(ir2),_ir3(ir3),_ir4(ir4){}
    ~IR()=default;
    void init(){
        pinMode(_ir1,INPUT);
        pinMode(_ir2,INPUT);
        pinMode(_ir3,INPUT);
        pinMode(_ir4,INPUT);
    }
    char getSensor(){
        return (0x00 |digitalRead(_ir4)<<3 | digitalRead(_ir3)<<2|digitalRead(_ir2)<<1 | digitalRead(_ir1));
    }

    private:
    int _ir1,_ir2,_ir3,_ir4;
};






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
