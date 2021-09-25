int x=0;
void setup()
{
  pinMode(2,  INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  x = digitalRead(2);
  if(x==HIGH){
    digitalWrite(13,HIGH);
  } 
  else{
    digitalWrite(13,LOW);
  }
  delay(1000);
}
