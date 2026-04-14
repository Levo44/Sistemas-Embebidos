// ==============================================
// LABORATORIO 06 - SERVOMOTOR CON POTENCIÓMETRO
// ==============================================

#include <Servo.h>   // Librería para controlar servomotores

// CREAR OBJETO SERVO
Servo miServo;       // Esto crea un objeto llamado "miServo"

// DEFINICIÓN DE PINES
const int PIN_SERVO = 11;   // Pin donde está conectado el servo
const int PIN_POT = A0;      // Pin donde está el potenciómetro

// VARIABLE PARA EVITAR VIBRACIONES
int anguloAnterior = -1;     // Guarda el último ángulo enviado al servo

// ==============================================
// SETUP: Se ejecuta UNA SOLA vez
// ==============================================
void setup() {
  // Inicializar el servo
  miServo.attach(PIN_SERVO);   // Conectar el objeto servo al pin físico
  
  // Colocar el servo en posición CENTRAL (90 grados)
  miServo.write(90);
  anguloAnterior = 90;
  
  // Iniciar comunicación serial
  Serial.begin(9600);
  Serial.println("=== LAB 06 - Control de Servo con Potenciometro ===");
  Serial.println("Gira el potenciometro para mover el servo");
  Serial.println();
  Serial.println("Valor ADC | Angulo");
  Serial.println("----------|-------");
}

// ==============================================
// LOOP: Se ejecuta infinitamente
// ==============================================
void loop() {
  // PASO 1: Leer el valor del potenciómetro
  // analogRead() devuelve un número entre 0 y 1023
  int valorPot = analogRead(PIN_POT);
  
  // PASO 2: Convertir ese valor a un ángulo (0 a 180 grados)
  // map(valor, desde_min, desde_max, hasta_min, hasta_max)
  int angulo = map(valorPot, 0, 1023, 0, 180);
  
  // PASO 3: Solo mover el servo si el cambio es significativo
  // Esto evita vibraciones por pequeñas fluctuaciones del potenciómetro
  if (abs(angulo - anguloAnterior) >= 2) {
    
    // Mover el servo al nuevo ángulo
    miServo.write(angulo);
    
    // Actualizar la variable del ángulo anterior
    anguloAnterior = angulo;
    
    // Mostrar los valores en el Monitor Serial
    Serial.print("   ");
    Serial.print(valorPot);
    Serial.print("     |   ");
    Serial.println(angulo);
  }
  
  // Pequeña pausa para estabilizar la lectura
  delay(20);
}