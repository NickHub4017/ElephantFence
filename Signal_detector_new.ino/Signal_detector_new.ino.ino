int inputpin=12;
int outputpin=13;
unsigned long gap;
void setup() {
  // put your setup code here, to run once:
pinMode(inputpin,INPUT);
pinMode(outputpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
int k=0;
if(Read()>18000){
  while(Read()<8500){
    k=k+1;
  }
  if(k==4){
    digitalWrite(outputpin,!digitalRead(outputpin));
  }
}

  
}
unsigned long Read(){
  //unsigned long x=  getIntervalofOnes();
  unsigned long y=  getIntervalofOnes();
//Serial.print("Read ");
  while(y<500){
  y=  getIntervalofOnes();
  //Serial.print("y -> ");
  if (y>800){
    return y;
  }
  
}

}
unsigned long getIntervalofOnes(){
  unsigned long timestart=millis();
  unsigned long timeend;
    unsigned long gap;
  while(analogRead(A0)<=250){
  }
  timeend=millis();
  gap=timeend-timestart;
  
  return gap;
}
