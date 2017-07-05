#define PIN_LDR A1
int V_max = 0;
int V_min = 1023;

void setup() {
 Serial.begin(9600);
}

void loop() {
 //Valor inicial del sensor
 int sensorValue = analogRead(PIN_LDR);
 //Calculo los valores maximos y minimos, comparando el actual con 
 //el que devuelve el sensor
 V_max = max(V_max,sensorValue);
 V_min = min(V_min,sensorValue);
 //saco por pantalla dichos valores
 Serial.print("el valor del sensor es: ");
 Serial.print(sensorValue);
 Serial.print(",");
 Serial.print("Valor maximo: ");
 Serial.print(V_max);
 Serial.print(",");
 Serial.print("Valor minimo: ");
 Serial.println(V_min);
 delay(500);
}

