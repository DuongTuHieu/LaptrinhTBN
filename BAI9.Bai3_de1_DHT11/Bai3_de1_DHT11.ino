

#include "DHT.h"  //khai bao thu vien cho DTH 

const int DHTPIN = 4;      // chan vao cua cam bien DHT11
const int DHTTYPE = DHT11;  

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  dht.begin();         
}
void loop() {
 int h = dht.readHumidity();    // do am
  float t = dht.readTemperature(); // nhiet do
  if(t >=30){
    digitalWrite(13,HIGH);
    }
  else digitalWrite(13,LOW);
    
  if(h <= 40){
    digitalWrite(11,HIGH);
    }
   else digitalWrite(11,LOW);         
}
