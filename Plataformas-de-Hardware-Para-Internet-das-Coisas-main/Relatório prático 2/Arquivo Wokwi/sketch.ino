const int PIN_TRIG = 27; //Trigger Pulse
const int PIN_ECHO = 26; //Echo Pulse




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);


  digitalWrite(PIN_TRIG, LOW);
}

void loop() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(11);
  digitalWrite(PIN_TRIG, LOW);


  long medicao = pulseIn(PIN_ECHO, HIGH, 60000);

  float distancia = medicao / 58.0;

  if(distancia < 2.0 || distancia > 400.0 || medicao == 0){
    distancia = 0.0;
  }

  Serial.print("Distancia: ");
  Serial.print((float)distancia);
  Serial.println("cm");

}
