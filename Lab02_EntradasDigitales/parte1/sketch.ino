const int PIN_BOTON = 2;
const int PIN_LED   = 8;

void setup() {
  pinMode(PIN_BOTON, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  int estado = digitalRead(PIN_BOTON);

  if (estado == HIGH) {
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }
}