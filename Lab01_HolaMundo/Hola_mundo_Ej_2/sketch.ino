const int PIN_LED = 13;

void setup() {
    pinMode(PIN_LED, OUTPUT);
}

void loop() {

    // S: 3 cortos (200 ms)
    for (int i = 0; i < 3; i++) {
        digitalWrite(PIN_LED, HIGH);
        delay(200);
        digitalWrite(PIN_LED, LOW);
        delay(200);
    }

    // 0: 3 largos (600 ms)
    for (int i = 0; i < 3; i++) {
        digitalWrite(PIN_LED, HIGH);
        delay(600);
        digitalWrite(PIN_LED, LOW);
        delay(200);
    }

    // S: 3 cortos (200 ms)
    for (int i = 0; i < 3; i++) {
        digitalWrite(PIN_LED, HIGH);
        delay(200);
        digitalWrite(PIN_LED, LOW);
        delay(200);
    }

    // Pausa de 2 segundos
    delay(2000);
}