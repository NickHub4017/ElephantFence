int signalout=12;
void setup() {
  // put your setup code here, to run once:
  pinMode(signalout,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}

public void sendNormal(){
  int i=0;
  for (i=0;i<20;i++){
    
    if((i%2)==0){
      sendOne();
    }
    else{
      sendZero();
    }
    
  }
}

public void sendOne(){
  digitalWrite(signalout,HIGH);
  delay(3);
  digitalWrite(signalout,LOW);
   delay(997);
}

public void sendZero(){
  digitalWrite(signalout,LOW);
  delay(3);
  digitalWrite(signalout,LOW);
   delay(997);
}
