const int LED_PIN = 13;
const int STARTING_SENSOR_PIN = 0;

void setup(){
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
  //turn on the IR leds
  digitalWrite(LED_PIN,HIGH);
}

void loop(){
  int raw_sensor_values[8];
  for (int i=0;i<8;i++){
    raw_sensor_values[i]=analogRead(STARTING_SENSOR_PIN+i);
    Serial.print(raw_sensor_values[i]);
    Serial.print("\t");
  }
  Serial.println();
}
