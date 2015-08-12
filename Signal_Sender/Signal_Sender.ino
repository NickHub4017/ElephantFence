int signalout=12;
int debugpin=13;
int lststate=HIGH;
void setup() {
  // put your setup code here, to run once:
  pinMode(signalout,OUTPUT);
    pinMode(debugpin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(debugpin,lststate);
  if(lststate==HIGH){
  lststate=LOW;
}
else{
lststate=HIGH;
}
  
  
  sendNormal();
  int nodeid[5]={1,1,0,1,1};
  sendNodeID(nodeid);

}

void sendNormal(){
  int i=0;
  for (i=0;i<10;i++){
      sendOne();    
  }
}

void sendNodeID(int x[]){
  int i=0;
  for (i=0;i<5;i++){
    if(x[i]==0){
       sendZero();
    }
    else{
      sendOne();
    }
  }
  
}

void sendOne(){
  digitalWrite(signalout,HIGH);
  delay(50);
  digitalWrite(signalout,LOW);
   delay(950);
}

void sendZero(){
  digitalWrite(signalout,LOW);
  delay(50);
  digitalWrite(signalout,LOW);
   delay(950);
}
