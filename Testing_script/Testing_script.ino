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
    

int x;//=analogRead(A0);
x=getIntervalofOnes();
if(x>900 ){
digitalWrite(13,HIGH);
delay(20);
digitalWrite(13,LOW);
 Serial.println(x);
 }
 
  //}

}

unsigned long getIntervalofOnes(){
  unsigned long time=millis();
  while(analogRead(A0)<100){
  }
  return (millis()-time);
}
