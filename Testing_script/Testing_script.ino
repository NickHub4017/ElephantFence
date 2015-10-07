//unsigned long time;
void setup() {

 pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  
Serial.begin(9600);
}

void loop() {

      digitalWrite(13,LOW);
      //unsigned long t=millis();
//  int x=getIntervalofOnes();
 
  //if(x>0){
    

int x=Read();
if(x>400){
 Serial.println(x);
}
 /*
//x=getIntervalofOnes();
if(x>900 ){
digitalWrite(13,HIGH);
delay(20);
digitalWrite(13,LOW);
 Serial.println(x);
 }
 */
  //}

}

unsigned long Read(){
  //unsigned long x=  getIntervalofOnes();
  unsigned long y=  getIntervalofOnes();
  //Serial.println(y);
  //Serial.println(y);
  while(y<500){
  y=  getIntervalofOnes();
  //Serial.print(y);
  if (y>550){
 //     Serial.println(y);
    return y;
  }
  
}
return y;

}

unsigned long getIntervalofOnes(){
  unsigned long time=millis();
  while(analogRead(A0)<100){
  }
  return (millis()-time);
}
