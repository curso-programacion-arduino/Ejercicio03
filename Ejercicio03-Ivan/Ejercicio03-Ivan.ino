int pulsaciones=0;
int flanco = 0;
#define pin 3
void setup() {
  // put your setup code here, to run once:
  pinMode(pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(pin)==1 && flanco == 0){
    flanco = 1;
    Serial.println(++pulsaciones);
  }
  if (digitalRead(pin)==0){
    flanco = 0;
  }
}
