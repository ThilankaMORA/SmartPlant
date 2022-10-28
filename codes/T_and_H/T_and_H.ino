#include <dht.h>

dht T_and_H;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:



  int val = T_and_H.read11(7);
  Serial.print("\n Tem = ");
  Serial.print(T_and_H.temperature);
  Serial.print("C");
  Serial.print("   Humi = ");
  Serial.print(T_and_H.humidity);
  Serial.print("%");
  delay(1000);

  









  

}
