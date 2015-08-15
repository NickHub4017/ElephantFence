//unsigned long time;
void setup() {

 pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  
Serial.begin(9600);
}

void loop() {

      digitalWrite(13,LOW);
      //unsigned long t=millis();
  int x=getIntervalofOnes();
 
  if(x>300){
    

 //Serial.println(x);
 
  }

}

unsigned long getIntervalofOnes(){
  unsigned long time=millis();
  while(analogRead(A0)<=250){
  }
  return (millis()-time);
}
