void pruebaBotones() {
  Serial.println(F("Prueba Botones"));
  Serial.println(F("Pulsar 'q' para salir."));
  int pulsos_a = 0;
  int pulsos_b = 0;
  anterior_a = digitalRead(PIN_BOTON_A);
  anterior_b = digitalRead(PIN_BOTON_B);

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
