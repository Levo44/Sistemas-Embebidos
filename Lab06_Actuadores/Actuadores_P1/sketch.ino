// ==============================================
// LABORATORIO 06 - CONTROL DE MOTOR DC CON L298N
// ==============================================

// DEFINICIÓN DE PINES
const int ENA = 10;   // Pin PWM para controlar VELOCIDAD
const int IN1 = 8;    // Pin para dirección (bit 1)
const int IN2 = 9;    // Pin para dirección (bit 2)

// ==============================================
// FUNCIONES DE CONTROL DEL MOTOR
// ==============================================

// Función 1: Girar hacia ADELANTE
// Parámetro velocidad: 0 = detenido, 255 = máxima velocidad
void motorAdelante(int velocidad) {
  digitalWrite(IN1, HIGH);   // Dirección: ADELANTE
  digitalWrite(IN2, LOW);    // Dirección: ADELANTE
  analogWrite(ENA, velocidad); // Aplica la velocidad
}

// Función 2: Girar hacia ATRÁS
void motorAtras(int velocidad) {
  digitalWrite(IN1, LOW);    // Dirección: ATRÁS
  digitalWrite(IN2, HIGH);   // Dirección: ATRÁS
  analogWrite(ENA, velocidad);
}

// Función 3: FRENO electromagnético (detención brusca)
void motorFreno() {
  digitalWrite(IN1, HIGH);   // Ambas salidas en HIGH
  digitalWrite(IN2, HIGH);   // = cortocircuito que frena el motor
  analogWrite(ENA, 255);     // Máxima potencia para frenar más fuerte
}

// Función 4: RUEDA LIBRE (se detiene por inercia)
void motorLibre() {
  analogWrite(ENA, 0);       // Apaga la salida del driver
  // No importa el estado de IN1/IN2 porque ENA=0 desactiva el motor
}

// ==============================================
// SETUP: Se ejecuta UNA SOLA vez al inicio
// ==============================================
void setup() {
  // Configurar los pines como SALIDA
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  // Iniciar comunicación serial para ver mensajes
  Serial.begin(9600);
  Serial.println("=== LAB 06 - Control Motor DC ===");
}

// ==============================================
// LOOP: Se ejecuta infinitamente (una y otra vez)
// ==============================================
void loop() {
  // --- PRUEBA 1: Adelante con velocidad creciente ---
  Serial.println(">> ADELANTE: velocidad creciente...");
  for (int velocidad = 100; velocidad <= 255; velocidad += 10) {
    motorAdelante(velocidad);
    Serial.print("   Velocidad: ");
    Serial.println(velocidad);
    delay(300);  // Espera 300ms para ver el cambio
  }
  
  // --- PRUEBA 2: Rueda libre (se detiene gradualmente) ---
  motorLibre();
  Serial.println(">> RUEDA LIBRE (detención por inercia)");
  delay(500);
  
  // --- PRUEBA 3: Atrás a velocidad media ---
  Serial.println(">> ATRAS: velocidad media (180)");
  motorAtras(180);
  delay(2000);
  
  // --- PRUEBA 4: Freno electromagnético ---
  motorFreno();
  Serial.println(">> FRENO ELECTROMAGNETICO (detención brusca)");
  delay(500);
  
  // Pequeña pausa antes de repetir todo
  delay(1000);
}