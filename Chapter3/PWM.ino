/*
*/

void setup() 
{
	pinMode(3, OUTPUT);
	pinMode(5, OUTPUT); 
	pinMode(6, OUTPUT); 
	pinMode(9, OUTPUT); 
	pinMode(10, OUTPUT); 

}
void loop() 
{
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(3, fadeValue);         
    delay(30);                            
  } 

  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    analogWrite(3, fadeValue);         
    delay(30);                            
  } 
}
