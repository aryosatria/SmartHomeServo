#define BLYNK_PRINT Serial // definisi serial pada blynk


// setting 
#include <ESP8266WiFi.h> // file untuk modul wifi
#include <BlynkSimpleEsp8266.h> // file untuk blynk
#include <Servo.h>

char auth[] = "yxHmB-1iegScYV_WqKXTLrbhddh9xPDx"; // token yang dikirim dari blynk ke email masing - masing
char ssid[] = "Petra";
char pass[] = "satria2004";

Servo gerak_servo;

BLYNK_WRITE(V1)
{
  gerak_servo.write(param.asInt());
  // Fungsi Blynk untuk mengatur nilai servo dengan pin virtual
}

void setup()
{
  // Debug console
  Serial.begin(9600); // memulai serial monitor dengan baudrate 9600

  Blynk.begin(auth, ssid, pass); // menjalankan blynk sesuai token, wifi, dan passwordnya

  gerak_servo.attach(2); //setting pin gpio 2 ke servo, D4 = 2
}

void loop()
{
  Blynk.run(); // memulai blynk 
}
