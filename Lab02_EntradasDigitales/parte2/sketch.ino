// LAB 02 - Parte 2 (Pull-up interno + debounce + contador)

const int BTN = 2;
const int LED = 13;

const unsigned long DEBOUNCE_MS = 20;

int estado_led = LOW;
int estado_boton = HIGH;
int ultimo_estado = HIGH;

unsigned long ultimo_tiempo = 0;
int conteo = 0;

void setup() {
  pinMode(BTN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Lab 02 - Iniciado");
}

void loop() {
  int lectura = digitalRead(BTN);

  // Detecta cambio
  if (lectura != ultimo_estado) {
    ultimo_tiempo = millis();
  }

  // Debounce
  if ((millis() - ultimo_tiempo) > DEBOUNCE_MS) {

    if (lectura != estado_boton) {
      estado_boton = lectura;

      // Detecta pulsación
      if (estado_boton == LOW) {
        conteo++;

        estado_led = !estado_led;
        digitalWrite(LED, estado_led);

        Serial.print("Pulsacion #");
        Serial.print(conteo);
        Serial.print(" - ");

        if (estado_led == HIGH) {
          Serial.println("LED ON");
        } else {
          Serial.println("LED OFF");
        }
      }
    }
  }

  ultimo_estado = lectura;
}