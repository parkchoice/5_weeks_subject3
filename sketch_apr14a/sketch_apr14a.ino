#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN); decode_results results;
void setup()
{   Serial.begin(9600);
pinMode(5, OUTPUT);

Serial.println("Enabling IRin");
irrecv.enableIRIn(); 
Serial.println("Enabled IRin");  }
void loop() {
  if (irrecv.decode(&results)) {
  Serial.println(results.value, HEX); 
  irrecv.resume(); 
} 
  if (irrecv.decode(&results)) {
  Serial.println(results.value, HEX);
  irrecv.resume(); // Receive the next value
  if (results.value == 0xFF30CF) digitalWrite(5, HIGH);  //1번 LED 켜기
  if (results.value == 0xFF18E7) digitalWrite(5, LOW);  // 2번 LED 끄기
 }
delay(100); }
