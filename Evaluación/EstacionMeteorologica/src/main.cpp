#include <Arduino.h>
#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

#define DHTPIN 18
#define DHTTYPE DHT22

const char* ssid = "POCO F5";
const char* password = "12345678";

unsigned long channelID = 3292157;
const char* writeAPIKey = "99NHFI8FYU3IMA5O";

WiFiClient client;

DHT dht(DHTPIN, DHTTYPE);

void setup() {

    Serial.begin(115200);
    dht.begin();

    WiFi.begin(ssid, password);

    Serial.print("Conectando a WiFi");

    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }

    Serial.println("Conectado!");

    ThingSpeak.begin(client);
}

void loop() {

    float humedad = dht.readHumidity();
    float temperatura = dht.readTemperature();

    if (isnan(humedad) || isnan(temperatura)) {
        Serial.println("Error leyendo el DHT11");
        return;
    }

    Serial.print("Temperatura: ");
    Serial.println(temperatura);

    Serial.print("Humedad: ");
    Serial.println(humedad);

    ThingSpeak.setField(1, temperatura);
    ThingSpeak.setField(2, humedad);

    int x = ThingSpeak.writeFields(channelID, writeAPIKey);

    if(x == 200){
        Serial.println("Datos enviados correctamente");
    } else {
        Serial.println("Error enviando datos");
    }

    delay(20000);
}