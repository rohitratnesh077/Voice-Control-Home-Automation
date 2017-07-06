
String voice;
int
brightness=2,
led1 = 2, //Connect LED 1 To Pin #2
led2 = 3, //Connect LED 2 To Pin #3
led3 = 4, //Connect LED 3 To Pin #4
led4 = 5, //Connect LED 4 To Pin #5
led5 = 6; //Connect LED 5 To Pin #6 
void dimlight(String v){
        analogWrite(led4,v.toInt());
        delay(100);
        Serial.println(v);
  }
  void bright(){
     while(1){
        analogWrite(led4,255);
        if (voice.length() > 0)
        break;
      }
  }
  /*boolean isValidNumber(String str){
   for(byte i=0;i<str.length();i++)
   {
      if(isDigit(str.charAt(i)))
          return true;
        }
   return false;
}*/ 
void allon(){
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     analogWrite(led4, 255);
     digitalWrite(led5, HIGH);
}
void alloff(){
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     analogWrite(led4, LOW);
     digitalWrite(led5, LOW);
}
//-----------------------------------------------------------------------// 
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}
//-----------------------------------------------------------------------// 
void loop() {

  while (Serial.available()){ 

    char  c; //Check if there is an available byte to read    
  delay(10); //Delay added to make thing stable
  c=Serial.read();
  if (c == '#') {break;}
  else if (c == ':')
    break;
    voice += c;  
  }
 if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//   
  //----------Control Multiple Pins/ LEDs----------// 
       if(voice == "ALL ON") {allon();}  //Turn Off All Pins (Call Function)
  else if(voice == "ALL OF"){alloff();} //Turn On  All Pins (Call Function)
 
  //----------Turn On One-By-One----------//
  else if(voice == "TV ON") {digitalWrite(led1, HIGH);}
  else if(voice == "FAN ON") {digitalWrite(led2, HIGH);}
  else if(voice == "COMPUTER ON") {digitalWrite(led3, HIGH);}
  else if(voice == "BEDROOM LIGHTS ON") {digitalWrite(led5, HIGH);}
  else if(voice == "LIGHTS ON") {analogWrite(led4,255);}
  
  
  //----------Turn Off One-By-One----------//
  else if(voice == "TV OF"||voice=="TV OFF") {digitalWrite(led1, LOW);}
  else if(voice == "FAN OF"||voice=="FAN OFF") {digitalWrite(led2, LOW);}
  else if(voice == "COMPUTER OF"||voice=="COMPUTER OFF") {digitalWrite(led3, LOW);}
  else if(voice == "BEDROOM LIGHTS OF"||voice == "BEDROOM LIGHTS OFF") {digitalWrite(led5, LOW);}
  else if(voice == "LIGHTS OF"||voice == "LIGHTS OFF") {analogWrite(led4, LOW);}
  
   else if (voice == "PROXIMITY"){analogWrite(led4,LOW);}
      else if(voice.toInt()>=0 && voice.toInt()<=255)
   {
    if(voice.toInt()>0){
        analogWrite(led4,voice.toInt());delay(100);
      }
      else{
        analogWrite(led4,0);
        }
      }
//-----------------------------------------------------------------------// 
  }
        voice="";
}
