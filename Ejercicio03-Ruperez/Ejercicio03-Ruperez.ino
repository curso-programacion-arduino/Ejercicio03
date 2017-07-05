/*EJERCICIO 03 CONTADOR DE PULSOS DE LOS DOS BOTONES*/
#define PIN_BOTON_A 2
#define PIN_BOTON_B 3

void setup()
{
  // Definicion de losdos pulsadores
  Serial.begin (9600);
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  pinMode(PIN_BOTON_B, INPUT);
  int pulsos_a = 0;
  int pulsos_b = 0;
  int pulsos_ambos = 0;
  static boolean reposo_a = (digitalRead PIN_BOTON_A);
  static boolean reposo_b = (digitalRead PIN_BOTON_B);
}

void loop()
{
  
if ()

  While (true)
  {

  }
  // put your main code here, to run repeatedly:

}
