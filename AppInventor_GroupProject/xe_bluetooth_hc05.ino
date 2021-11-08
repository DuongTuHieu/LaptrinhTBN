// Định ngĩa các chân điều khiển động cơ
#define in1 3
#define in2 4
#define in3 5
#define in4 6
char bluetoothByte ; //khai báo biến nhận bluetooth
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // khai báo các chân in1,in2,in3,in4 của mạch điều khiển động cơ

  Serial.begin(9600);
}
void loop() {
  // Nếu nhận được giá trị
  if (Serial.available() > 0) {
    //đọc dữ liệu gửi về
    bluetoothByte = Serial.read();
    Serial.println(bluetoothByte);
  }
  if (bluetoothByte == 'a') //khi app inventor gửi kí tự 'a' về module bluetooth hc-05 thì tín hiệu này sẽ được arduino tiếp nhận và cho xe chạy tiến 
    dithang();
  else if (bluetoothByte == 'e')//khi app inventor gửi kí tự 'e' về module bluetooth hc-05 thì tín hiệu này sẽ được arduino tiếp nhận và cho xe dừng lại 
    dunglai();
  else if (bluetoothByte == 'b')//khi app inventor gửi kí tự 'b' về module bluetooth hc-05 thì tín hiệu này sẽ được arduino tiếp nhận và cho xe chạy lùi 
    lui();
  else if (bluetoothByte == 'c')//khi app inventor gửi kí tự 'c' về module bluetooth hc-05 thì tín hiệu này sẽ được arduino tiếp nhận và cho xe quay qua trái 
    quaytrai();
  else if (bluetoothByte == 'd')//khi app inventor gửi kí tự 'd' về module bluetooth hc-05 thì tín hiệu này sẽ được arduino tiếp nhận và cho xe quay qua phải 
  {
    quayphai();

  }

}
// Phần điều khiển động cơ, mình viết như thế này...MAX dễ hiểu luôn:
void dunglai() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  // đoạn code này mình cho các chân ở mức thấp thì cả 4 động cơ đều dừng
}
void dithang() {
  digitalWrite(in1, HIGH);    //đây là chân in1 nhận tín hiệu mức cao cùng vs chân in3 để xe chạy tiến 
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
}
void lui() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);    //ngược lại với chân tiến thì chân in2 và in4 ở mức cao thì sẽ đi lùi 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void quaytrai() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);   
  digitalWrite(in4, HIGH);    // động cơ bên trái sẽ quay ngược về sau  và động cơ bên phải tiến thì sẽ quay qua trái 
}
void quayphai() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);   // động cơ bên phải sẽ quay ngược về sau và động cơ bên trái tiến thì sẽ quay qua trái 
  digitalWrite(in4, LOW);
}
