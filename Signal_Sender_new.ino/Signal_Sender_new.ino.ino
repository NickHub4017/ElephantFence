int signalout = 8;
int debugpin = 13;
int lststate = HIGH;
int is_check_pin=11;
int is_not_check_pin=10;
void setup() {
  // put your setup code here, to run once:
  pinMode(signalout, OUTPUT);
  pinMode(debugpin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(debugpin, lststate);
  if (lststate == HIGH) {
    lststate = LOW;
  }
  else {
    lststate = HIGH;
  }
  
  if(digitalRead(is_check_pin)==HIGH){

  sendNormal();
  
  sendPreamble();
  int nodeid = 4;
  sendNodeID(nodeid);
  senPostable();
  sendTrail();
  
}
else if(digitalRead(is_not_check_pin)==HIGH){
  sendPreamble();  
}
  
/*  sendPreamble();
  nodeid = 6;
  sendNodeID(nodeid);
  senPostable();
  sendTrail();
*/
}
void sendTrail(){
  int i=0;
  
  for (i = 0; i < 9; i++) {
    sendOne();
  }
}

void sendNormal() {
  int i = 0;
  for (i = 0; i < 10; i++) {
    sendOne();
  }
}
void sendPreamble() {
  int i = 0;
  for (i = 0; i < 15; i++) {
    sendZero();
  }

}

void senPostable() {
  int i = 0;
  for (i = 0; i < 10; i++) {
    sendZero();
  }

}


void sendNodeID(int x) {
  int i = 0;
  
  for (i = 0; i <=x; i++) {
          sendOne();
  }

}

void sendOne() {
  digitalWrite(signalout, HIGH);
  delay(50);
  digitalWrite(signalout, LOW);
  delay(950);
}

void sendZero() {
  digitalWrite(signalout, LOW);
  delay(50);
  digitalWrite(signalout, LOW);
  delay(950);
}

