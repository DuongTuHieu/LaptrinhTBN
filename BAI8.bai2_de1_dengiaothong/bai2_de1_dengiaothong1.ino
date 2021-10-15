// C++ code
//
int dem=0;

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  dem += 1;
  delay(1000);
  if(dem == 65){
  dem=0;
  }
  if(dem<=30){
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);  
  }
 if(dem>30&&dem<40){
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);  
 }
   if(dem>=40){
     digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH); 
   
   }
   
 }
