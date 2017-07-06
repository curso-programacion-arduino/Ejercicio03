#define PIN_BOTON_A 2
#define PIN_BOTON_B 3

//Variables globales
int pulsaciones_A = 0;
int pulsaciones_B = 0;
int totalPulsaciones = 0;
boolean estadoInicial_A;
boolean estadoInicial_B;
void setup() {
  Serial.begin(9600);

  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  pinMode(PIN_BOTON_B, INPUT_PULLUP);

  //Guardo los estados inciales de los botones
  estadoInicial_A = digitalRead(PIN_BOTON_A);
  estadoInicial_B = digitalRead(PIN_BOTON_B);
  Serial.println("Pulse por favor los botones para inicializar las cuentas");
}

void loop() {
  boolean estadoActual_A = digitalRead(PIN_BOTON_A);
  boolean estadoActual_B = digitalRead(PIN_BOTON_B);

  if (estadoInicial_A != estadoActual_A) {
    if (estadoActual_A == LOW) {
      pulsaciones_A++;
      Serial.println("Has pulsado el boton A");
      totalPulsaciones++;
      imprimePulsaciones();
      Serial.println();
    }
  }

  if (estadoInicial_B != estadoActual_B) {
    if (estadoInicial_B == LOW) {
      pulsaciones_B++;
      Serial.println("Has pulsado el boton B");
      imprimePulsaciones();
      totalPulsaciones++;
      Serial.println();
    }
  }
  estadoInicial_A = estadoInicial_A;
  estadoInicial_B = estadoInicial_B;

  delay(90);
}

void imprimePulsaciones() {
  Serial.println("Contador A: " + (String)pulsaciones_A + "\tContador B: " + (String)pulsaciones_B);
  Serial.println("Total pulsaciones: " + (String)totalPulsaciones);
}

