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
if(x>18000){//1000000000000000000001 ---Firstone=noramal pulse's last bit middle zeros=preamble last one=frist bit of node id
  int x1=  getIntervalofOnes();
  //Serial.println(x1);
  if((x1>900)&&(x1<1100)){//1
  int x2=  getIntervalofOnes();
    Serial.println(x2);
    if((x2>1800)&&(x2<2200)){//01
    int x3=  getIntervalofOnes();
      if((x3>900)&&(x3<1100)){//1
      Serial.println("Found");
      digitalWrite(outputpin,!digitalRead(outputpin));
        }
    }
  }
  
}
  
  ////Serial.println(  getRead());
  // put your main code here, to run repeatedly:
  ////Serial.println(getIntervalofOnes());
  /*
gap=getIntervalofOnes();
if(gap>900){
  if(gap<1100){
  //Serial.println(1);
  }
  else{
    int y=0;
    y=(gap/1000);
    for (;y!=1;y--){
      //Serial.print(0);
    }
  //Serial.println(1);  
  }
}
  
*/
}

int getRead(){
  gap=getIntervalofOnes()+100;
  if(gap>900){
    return (gap/1000);
  }
  
}
unsigned long getIntervalofOnes(){
  unsigned long time=millis();
  while(analogRead(A0)<=250){
  }
  return int(millis()-time);
}
