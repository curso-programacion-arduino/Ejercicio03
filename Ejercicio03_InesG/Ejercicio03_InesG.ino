#define PIN_BOTON_A 2
#define PIN_BOTON_B 3
static boolean anterior_a = digitalRead(PIN_BOTON_A);
static boolean anterior_b = digitalRead(PIN_BOTON_B);
int pulsos_a = 0;
int pulsos_b = 0;
int pulsos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  pinMode(PIN_BOTON_B, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean estado_a = digitalRead(PIN_BOTON_A);
  boolean estado_b = digitalRead(PIN_BOTON_B);

  if (anterior_a != estado_a) {
    if (estado_a == HIGH) {  //flanco ascendente pull-up
      Serial.println(F("Pulsado boton A"));
      pulsos_a++;
      Serial.println("Numero pulsaciones botones: " + (String)pulsos);
    }
  }

  if (anterior_b != estado_b) {
    if (estado_b == LOW) {  //flanco ascendente pull-down
      Serial.println(F("Pulsado boton B"));
      Serial.println("Numero pulsaciones botones: " + (String)pulsos);
      pulsos_b++;
    }
  }
  anterior_a = estado_a;
  anterior_b = estado_b;
  pulsos = pulsos_a + pulsos_b;
  delay(50); //Evitar rebotes
}
