int signalout = 8;
int debugpin = 13;
int lststate = HIGH;
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


  sendNormal();
 /* sendPreamble();
  int nodeid = 5;
  sendNodeID(nodeid);
  senPostable();
*/
}

void sendNormal() {
  int i = 0;
  for (i = 0; i < 10; i++) {
    sendOne();
  }
}
void sendPreamble() {
  int i = 0;
  for (i = 0; i < 20; i++) {
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
  for (i = 0; i < x; i++) {
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

