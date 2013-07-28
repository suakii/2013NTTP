/-
 7 Segment
*-
byte digitFor7Segment[10][7] = {
        //2, 3, 4, 5, 6, 7, 8 - 아두이노의 IO Port와 segment 연결
        //9 pin for dot        
        {1, 1, 1, 1, 1, 1, 0},//0
        {0, 0, 1, 1, 0, 0, 0},//1
        {1, 1, 0, 1, 1, 0, 1},//2
        {0, 1, 1, 1, 1, 0, 1},//3
        {0, 0, 1, 1, 0, 1, 1},//4
        {0, 1, 1, 0, 1, 1, 1},//5
        {1, 1, 1, 0, 1, 1, 1},//6
        {0, 0, 1, 1, 1, 0, 0},//7
        {1, 1, 1, 1, 1, 1, 1},//8
        {0, 1, 1, 1, 1, 1, 1}//9
        };
void setup()
{
  byte pinNum = 2;
  for (pinNum = 2; pinNum<=9; pinNum++)
    pinMode(pinNum, OUTPUT);//출력 설정
}
void writeNum(byte digit) 
{
   byte pinNum = 2;
  for (byte segPinCount = 0; segPinCount < 7; segPinCount++) {
    digitalWrite(pinNum, digitFor7Segment[digit][segPinCount]);//digit으로 넘어오는 숫자를 씀
    pinNum++;
  } 
}
void offSegment() {//모두 끄기
   byte pinNum = 2;
  for (byte segPinCount = 0; segPinCount < 7; segPinCount++) {
    digitalWrite(pinNum, 0);
    pinNum++;
  }
}
void loop() 
{
  for (byte count = 0; count < 10; count++) {
    delay(1000);//???
    writeNum(count);
  }
  delay(1000);
  
  offSegment();
  delay(500);
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  delay(500);
  
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  delay(500);
 
}