 int inputpin=12;
int outputpin=13;
int relaypin=9;
unsigned long gap;
void setup() {
  // put your setup code here, to run once:
pinMode(inputpin,INPUT);
pinMode(outputpin,OUTPUT);
pinMode(relaypin,OUTPUT);

Serial.begin(9600);
}

void loop() {
//  Serial.println(Read());
int k=0;
if(Read()>13000){
  while(Read()<8500){
    k=k+1;
  }
  if(k==4){
    digitalWrite(outputpin,HIGH);

    digitalWrite(relaypin,HIGH);
    delay(4000);
    digitalWrite(relaypin,LOW);
        digitalWrite(outputpin,LOW);
  }
}

  
//  unsigned long yp=Read();
  //Serial.println( yp);
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
  unsigned long timestart=millis();
  unsigned long timeend;
    unsigned long gap;
  while(analogRead(A0)<100){
  }
  timeend=millis();
  gap=timeend-timestart;
  
  return gap;
}
