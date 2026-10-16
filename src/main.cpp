#include <Arduino.h>

#define LORA_RX 16  // Conectado al TXD del LoRa
#define LORA_TX 17  // Conectado al RXD del LoRa
#define LORA_AUX 15 // Conectado al AUX del LoRa

void setup() {
  // Inicializa el monitor serie de la PC
  Serial.begin(115200);
  
  // Inicializa el puerto Serial2 para el LoRa (9600 baudios por defecto)
  Serial2.begin(9600, SERIAL_8N1, LORA_RX, LORA_TX);
  
  // Configura el pin AUX como entrada
  pinMode(LORA_AUX, INPUT);
  
  Serial.println("--- RECEPTOR LORA E220 INICIADO ---");
}

void loop() {
  // Verifica si hay datos disponibles viniendo del LoRa
  if (Serial2.available() > 0) {
    // Lee la cadena de texto hasta encontrar un salto de línea
    String mensajeRecibido = Serial2.readStringUntil('\n');
    
    // Muestra el mensaje en el monitor de la PC
    Serial.print("Recibido: ");
    Serial.println(mensajeRecibido);
  }
}