const int PIN_BUZZER = 6;

// Frecuencias de notas
int notas[] = {262, 294, 330, 349, 392, 440, 494};
String nombres[] = {"Do","Re","Mi","Fa","Sol","La","Si"};

int duracion = 300;

void setup() {
    Serial.begin(9600);
    Serial.println("Lab 03 - Buzzer: escala musical");
}

void loop() {
    // Escala ascendente
    for (int i = 0; i < 7; i++) {
      Serial.print("Nota: ");
      Serial.print(nombres[i]);
      Serial.print(" Freq: ");
      Serial.print(notas[i]);
      Serial.println(" Hz");

      tone(PIN_BUZZER, notas[i], duracion);
      delay(duracion + 50);
    }

    noTone(PIN_BUZZER); // detener sonido
    delay(1000);       // pausa
}