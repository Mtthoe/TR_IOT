#include <arduino.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

Servo servo1, servo2, servo3;

char auth[] = "hSc_kp5C9EbzPrD54niWg1Ve8ouhAhPy";
char ssid[] = "JOCHAA";
char pass[] = "puriMedb325";

BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); 
  servo1.write(s0);
  Blynk.virtualWrite(V3, s0);
}
BLYNK_WRITE(V1)
{
  int s1 = param.asInt(); 
  servo2.write(s1);
  Blynk.virtualWrite(V4, s1);
}
BLYNK_WRITE(V2)
{
  int s2 = param.asInt(); 
  servo3.write(s2);
  Blynk.virtualWrite(V5, s2);
}

void setup()
{
  Serial.begin(115200);
  servo1.setPeriodHertz(50);
  servo2.setPeriodHertz(50);
  servo3.setPeriodHertz(50);
  servo1.attach(13, 500, 2400);
  servo2.attach(12, 500, 2400);
  servo3.attach(14, 500, 2400);
  Blynk.begin(auth, ssid, pass);
  delay(2000); // Splash screen delay
}

void loop() 
{
  Blynk.run();
}
