#define PIN_BOTON_A 2
#define PIN_BOTON_B 3

//Variables globales
int pulsos_a = 0;
int pulsos_b = 0;
boolean anterior_a;
boolean anterior_b;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  pinMode(PIN_BOTON_B, INPUT);

  anterior_a = digitalRead(PIN_BOTON_A);
  anterior_b = digitalRead(PIN_BOTON_B);

}

void loop() {
  boolean estado_a = digitalRead(PIN_BOTON_A);
  boolean estado_b = digitalRead(PIN_BOTON_B);

  if (anterior_a != estado_a) {
    if (estado_a == LOW) {  //flanco descendente pull-up
      pulsos_a++;
      imprimePulsaciones();
    }
  }
  anterior_a = estado_a;
  delay(50); //Evitar rebotes
}

void imprimePulsaciones() {
  Serial.println("Contador A: " + (String)pulsos_a + "\tContador B: " + (String)pulsos_b);
}
