#define PIN_BOTON_A 2
#define PIN_BOTON_B 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  pinMode(PIN_BOTON_B, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(F("Prueba Botones"));
  static int pulsos_a = 0;
  static int pulsos_b = 0;
    
    boolean estado_a = digitalRead(PIN_BOTON_A);
    boolean estado_b = digitalRead(PIN_BOTON_B);

    if (anterior_a != estado_a) {
      if (estado_a == LOW) {  //flanco descendente pull-up
        Serial.println(F("Pulsado boton A"));
        pulsos_a++;
        Serial.println("Numero pulsaciones boton A: " + (String)pulsos_a);
      }
    }

    if (anterior_b != estado_b) {
      if (estado_b == HIGH) {  //flanco ascendente pull-down
        Serial.println(F("Pulsado boton B"));
        pulsos_b++;
        Serial.println("Numero pulsaciones boton B: " + (String)pulsos_b);
      }
    }
    anterior_a = estado_a;
    anterior_b = estado_b;
    delay(50); //Evitar rebotes
  }
}
void imprimePulsaciones() {
  Serial.println("Contador A: " + (String)pulsos_a + "\tContador B: " + (String)pulsos_b);
}


