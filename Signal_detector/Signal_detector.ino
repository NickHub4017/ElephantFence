int inputpin=12;
unsigned long gap;
void setup() {
  // put your setup code here, to run once:
pinMode(inputpin,INPUT);
Serial.begin(9600);
}

void loop() {
/*
unsigned long x=  getIntervalofOnes();
if((x>18000)&&(x<21000)){
}
  */
  //Serial.println(  getRead());
  // put your main code here, to run repeatedly:
gap=getIntervalofOnes();
if(gap>900){
  if(gap<1100){
  Serial.println(1);
  }
  else{
    int y=0;
    y=(gap/1000);
    for (;y!=0;y--){
      Serial.print(0);
    }
  Serial.println(1);  
  }
}
  

}

int getRead(){
  gap=getIntervalofOnes()+100;
  if(gap>900){
    return (gap/1000);
  }
  
}
unsigned long getIntervalofOnes(){
  unsigned long time=millis();
  //Serial.print(millis());
    //Serial.print(" ---> ");
  while(analogRead(A0)<=190){
  }
    //Serial.println(millis());
  return (millis()-time);
}
