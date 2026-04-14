#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_W 128
#define OLED_H 64
#define OLED_ADDR 0x3C

Adafruit_BMP085 bmp;
Adafruit_SSD1306 display(OLED_W, OLED_H, &Wire, -1);

const float PRESION_MAR = 1013.25;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("ERROR OLED");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(10, 25);
  display.println("Iniciando BMP280...");
  display.display();

  delay(2000);

  // BMP180
  if (!bmp.begin()) {
    Serial.println("ERROR BMP");
    while (true);
  }

  Serial.println("Temp\tPresion\tAltitud");
}

void loop() {
  // 🔥 LECTURAS CORRECTAS
  float temp = bmp.readTemperature();         // °C
  float presion = bmp.readPressure() / 100.0; // hPa
  float altitud = bmp.readAltitude(PRESION_MAR);

  // ── OLED ─────────────────────────
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(25, 0);
  display.println("-- BMP280 --");

  // ✅ TEMPERATURA (CORRECTA)
  display.setTextSize(2);
  display.setCursor(0, 15);
  display.print(temp, 1);
  display.println(" C");

  // ✅ PRESION
  display.setTextSize(1);
  display.setCursor(0, 40);
  display.print("P: ");
  display.print(presion, 1);
  display.println(" hPa");

  // ✅ ALTITUD
  display.setCursor(0, 55);
  display.print("Alt: ");
  display.print(altitud, 0);
  display.println(" m");

  display.display();

  // ── SERIAL ───────────────────────
  Serial.print(temp);
  Serial.print("\t");
  Serial.print(presion);
  Serial.print("\t");
  Serial.println(altitud);

  delay(1000);
}