
/*
   Ejercicio 03
   Contar pulsaciones de botones
   desde el codigo de jecrespo:
   https://github.com/curso-programacion-arduino/Ejercicio03/blob/master/Ejercicio03-Enrique/Ejercicio03-Enrique.ino

*/

#define PIN_BOTON_A 2
/*
   #define: el compilador sabrá que nos referimos al pin 2
   cuando tecleamos "PIN_BOTON_A"
*/

#define PIN_BOTON_B 3

//Variables globales
int pulsos_a = 0;
int pulsos_b = 0;
boolean anterior_a;
boolean anterior_b;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  pinMode(PIN_BOTON_B, INPUT);

  anterior_a = digitalRead(PIN_BOTON_A);
  anterior_b = digitalRead(PIN_BOTON_B);
}

void loop()
{
  boolean estado_a = digitalRead(PIN_BOTON_A);
  boolean estado_b = digitalRead(PIN_BOTON_B);

  /*
     Vamos a usar una funcion:
     La funcion "imprimePulsaciones()" nos
     sirve para imprimir en el monitor serie los datos.
     Para mantener el codigo un poco ordenado trasladamos
     el codigo de la funcion al final, despues del void loop

     Usamos la funcion porque escribiendola una sola vez
     podremos usarla repetidamente llamandola desde
     diferentes partes del programa.
     en este caso cada vez que pulsemos un boton.
  */

  if (anterior_a != estado_a)
  {
    if (estado_a == LOW)
    {
      //flanco descendente pull-up
      pulsos_a++;
      imprimePulsaciones();
      // aqui llamamos a la funcion "imprimePulsaciones()"
    }
  }

  if (anterior_b != estado_b)
  {
    if (estado_b == HIGH)
    {
      //flanco ascendente pull-down
      pulsos_b++;
      imprimePulsaciones();
    }
  }
  anterior_a = estado_a;
  /*
     Es fundamental que el estado actual de cada boton pase a ser el estado anterior
     a cada vuelta del loop...
  */
  anterior_b = estado_b;
  delay(50);
  /*
    El delay evita que una pulsacion demasiado rapida o prolongada
    nos pueda dar errores. Arduino necesita unos milisegundos para procesar,
    sin el delay podriamos perder pulsaciones
  */
}
// Funcion:
void imprimePulsaciones()
{
  Serial.println("Contador A: " + (String)pulsos_a + "\tContador B: " + (String)pulsos_b);
}

