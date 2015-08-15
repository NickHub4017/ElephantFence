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
//11011
unsigned long x=  getIntervalofOnes();
//Serial.print("Read ");
Serial.println(x);
int id=0;
if(x>18000){//1000000000000000000001 ---Firstone=noramal pulse's last bit middle zeros=preamble last one=frist bit of node id
  unsigned long p=getIntervalofOnes();
  while(p<9000){
    //Serial.println(p);
    id=id+1;
    p=getIntervalofOnes();
  }
  if(id==4){
  digitalWrite(outpin,!digitalRead(outpin));
}
  Serial.println(id);
}

  
}

unsigned long getIntervalofOnes(){
  unsigned long time=millis();
  while(analogRead(A0)<=250){
  }
  return (millis()-time);
}
