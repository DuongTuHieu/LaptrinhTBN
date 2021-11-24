// Định ngĩa các chân điều khiển động cơ
#define in1 3
#define in2 4
#define in3 5
#define in4 6

//định nghĩa các chân led
#define led1 8
#define led2 9
#define led3 10
#define led4 11

#include "DHT.h"//khai báo thư viện DHT
#define DHTTYPE DHT11 //Định nghĩa loại DHT( Chọn DHT11)
#define DHTPIN 7 // Khai báo chân DHT11
DHT dht(DHTPIN, DHTTYPE);

char bluetoothByte ; //khai báo biến nhận bluetooth
int timer = 0; // tạo 1 biến đếm

void setup() {
  pinMode(in1, OUTPUT); // khai báo chân điều khiển động cơ
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(led1, OUTPUT); // khai báo chân led
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  // khai báo các chân in1,in2,in3,in4 của mạch điều khiển động cơ và chân 7 là mạch DHT và các chân 8 , 9, 10, 11 điều khiển led
  Serial.begin(9600);
  dht.begin();
}
void loop() {


  // Nếu nhận được giá trị
  if (Serial.available() > 0) {
    //đọc dữ liệu gửi về
    bluetoothByte = Serial.read();
    Serial.println(bluetoothByte);

    if (bluetoothByte == 'a') //khi app inventor gửi kí tự 'a' về module bluetooth hc-05 thì tín hiệu này sẽ được arduino tiếp nhận và cho xe chạy tiến
     ditien();
     
    
    else if (bluetoothByte == 'e')//khi app inventor gửi kí tự 'e' về module bluetooth hc-05 thì tín hiệu này sẽ được arduino tiếp nhận và cho xe dừng lại
      dunglai();
    else if (bluetoothByte == 'b')//khi app inventor gửi kí tự 'b' về module bluetooth hc-05 thì tín hiệu này sẽ được arduino tiếp nhận và cho xe chạy lùi
      dilui();
    else if (bluetoothByte == 'c')//khi app inventor gửi kí tự 'c' về module bluetooth hc-05 thì tín hiệu này sẽ được arduino tiếp nhận và cho xe quay qua trái
      quaytrai();
    else if (bluetoothByte == 'd')//khi app inventor gửi kí tự 'd' về module bluetooth hc-05 thì tín hiệu này sẽ được arduino tiếp nhận và cho xe quay qua phải
    {
      quayphai();
    }
    else if (bluetoothByte == 'f') //khi app inventor gửi kí tự 'f' về module bluetooth hc-05 thì tín hiệu này sẽ được arduino tiếp nhận và cho LED sáng
      ledsang();
    else if (bluetoothByte == 'g') //khi app inventor gửi kí tự 'g' về module bluetooth hc-05 thì tín hiệu này sẽ được arduino tiếp nhận và cho LED tắt
      ledtat();

  }
  nhietdo_doam();
delay(1);
}
// Phần điều khiển động cơ
void nhietdo_doam()
{
  timer =  timer + 1;
  if (timer > 500) //
  {
    byte h = dht.readHumidity(); //đọc dữ liệu độ ẩm
    byte t = dht.readTemperature(); // đọc dữ liệu nhiệt độ
    Serial.print((int)h); // gửi dữ liệu độ ẩm lên Serial để truyền qua bluetooth lên APP INVENTOR
    Serial.print(" %"); // gửi ký tự % lên lên Serial để truyền qua bluetooth lên APP INVENTOR
    Serial.print("l"); // gửi ký tự l lên Serial để lên Serial để truyền qua bluetooth lên APP INVENTOR ( ký tự l được xem như là ký tự tách các các biến với nhau khi gửi lên, ở đây là tách 2 biến nhiệt độ với độ ẩm)
    Serial.print((int)t); // gửi dữ liệu nhiệt độ lên Serial để truyền qua bluetooth lên APP INVENTOR
    Serial.println(" độ C"); //gửi ký tự "độ C" lên lên Serial để truyền qua bluetooth lên APP INVENTOR
    Serial.print("l");
    timer = 0;
  }
}
void dunglai() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  // đoạn code này mình cho các chân ở mức thấp thì cả 4 động cơ đều dừng
}
void dilui() {
  digitalWrite(in1, HIGH);    //đây là chân in1 nhận tín hiệu mức cao cùng vs chân in3 để xe chạy tiến
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);

}
void ditien() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);    //ngược lại với chân tiến thì chân in2 và in4 ở mức cao thì sẽ đi lùi
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
}
void quaytrai() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);    // động cơ bên trái sẽ quay ngược về sau  và động cơ bên phải tiến thì sẽ quay qua trái
   digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
}
void quayphai() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);   // động cơ bên phải sẽ quay ngược về sau và động cơ bên trái tiến thì sẽ quay qua trái
  digitalWrite(in4, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);

}

void ledsang () {

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH); // toàn bộ LED sáng
  digitalWrite(led4, HIGH);
}
void ledtat () {

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW); // toàn bộ LED tắt
  digitalWrite(led4, LOW);
}
