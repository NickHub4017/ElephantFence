int signalout = 8;
int debugpin = 13;
int lststate = HIGH;
int is_check_pin = 3;
int is_not_check_pin = 5;
int idno_in1 = 6;
int idno_in2 = 7;
int trail_notify = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode(signalout, OUTPUT);
  pinMode(debugpin, OUTPUT);
  pinMode(is_check_pin, INPUT);
  pinMode(is_not_check_pin, INPUT);
  pinMode(idno_in1, INPUT);
  pinMode(idno_in2, INPUT);
  pinMode(trail_notify, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    Serial.print("normal@id ");
    sendNormal();
        Serial.print("preamble ");
    sendPreamble();
        Serial.print("sendid ");
    sendNodeID(4);
        Serial.print("postable ");
    senPostable();
        Serial.print("trail ");
        digitalWrite(trail_notify, HIGH);
    sendTrail();
      digitalWrite(trail_notify, LOW);
    Serial.println("Done");
  

}
void sendTrail() {
  
  int i = 0;

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

