
//PINES
#define PIN_BOTON_A 2
#define PIN_BOTON_B 3
int suma=0;



void setup() {
  //Inicializo puerto serie
  Serial.begin(9600);


  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  pinMode(PIN_BOTON_B, INPUT);

  }



void loop() {


  int pulsos_a = 0;
  int pulsos_b = 0;
  static boolean anterior_a = digitalRead(PIN_BOTON_A);
  static boolean anterior_b = digitalRead(PIN_BOTON_B);

  while (true) {
    //Compruebo si llega una q
    if (Serial.available() > 0) {
      char caracter_leido = Serial.read();
      if (caracter_leido == 'q')
        break;
    }

    boolean estado_a = digitalRead(PIN_BOTON_A);
    boolean estado_b = digitalRead(PIN_BOTON_B);

    if (anterior_a != estado_a) {
      if (estado_a == LOW) {  //flanco descendente pull-up
       
        pulsos_a++;
        suma++;
        Serial.println("Numero pulsaciones boton A: " + (String)pulsos_a);
        Serial.print("Numero pulsaciones totales: ");
        Serial.println(suma);
        
      }
    }

    if (anterior_b != estado_b) {
      if (estado_b == HIGH) {  //flanco ascendente pull-down
       
        pulsos_b++;
         suma++;
        Serial.println("Numero pulsaciones boton B: " + (String)pulsos_b);
        Serial.print("Numero pulsaciones totales: ");
        Serial.println(suma);
      }
    }
    anterior_a = estado_a;
    anterior_b = estado_b;
    delay(50); //Evitar rebotes
  }
}

