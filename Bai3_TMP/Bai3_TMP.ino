
void setup()
{
  Serial.begin(96000);
}

void loop()
{
  //Doc gia tri cam bien
  int giatri = analogRead(A0);
  int nhietDo = map(giatri,20,358,-40,125);
  //Serial.print(nhietDo);
  if(nhietDo>37) digitalWrite(10,HIGH);
  else digitalWrite(10,LOW);
  
  delay(1000);
}
