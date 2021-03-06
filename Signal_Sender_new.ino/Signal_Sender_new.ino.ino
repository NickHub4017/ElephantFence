int signalout = 8;
int debugpin = 13;
int lststate = HIGH;
int is_check_pin = 3;
int is_not_check_pin = 5;
int trailrelay = 7;
int trail_notify = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode(signalout, OUTPUT);
  pinMode(debugpin, OUTPUT);
  pinMode(is_check_pin, INPUT);
  pinMode(trailrelay, OUTPUT);
  pinMode(trail_notify, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("#s online");
}

void loop() {
  // put your main code here, to run repeatedly:



  if (Serial.available() > 0) {
    Serial.println("#s check");
    int nodeid = Serial.read();
    nodeid = nodeid - 48;
    Serial.print("#s ");
    Serial.print(nodeid);
        Serial.println(" ack");
    Serial.println("#s normal");
    sendNormal();
    Serial.println("#s preamble ");
    sendPreamble();
    Serial.println("#s sendid ");
    sendNodeID(nodeid);
    Serial.println("#s postable ");
    senPostable();
    sendOne();
     Serial.print("#s ");
    Serial.print(nodeid);
    Serial.println(" trail ");
    sendTrail();
        Serial.print("#s ");
    Serial.print(nodeid);
    Serial.println(" end_trail ");
    Serial.println("#s End");
  }

  else {
    //Serial.println("#s not_check");
    sendOne();

  }





}
void sendTrail() {
digitalWrite(trailrelay,HIGH);
  int i = 0;

  for (i = 0; i < 8; i++) {
    sendZero();
  }
  digitalWrite(trailrelay,LOW);

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

  for (i = 0; i <= x; i++) {
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

