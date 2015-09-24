int signalout = 8;
int debugpin = 13;
int lststate = HIGH;
int is_check_pin = 11;
int is_not_check_pin = 10;
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
  // put your main code here, to run repeatedly:
  digitalWrite(is_check_pin, LOW);
  digitalWrite(is_not_check_pin, LOW);

  digitalWrite(idno_in1, LOW);
  digitalWrite(idno_in2, LOW);
  digitalWrite(trail_notify, LOW);



  if (digitalRead(is_check_pin) == HIGH && digitalRead(is_not_check_pin) == LOW) {
    Serial.println("check");
    int nodeid = 0;
    while ((digitalRead(idno_in1) == LOW) && (digitalRead(idno_in2) == LOW)) {
          Serial.print("w ");
    }

    if ((digitalRead(idno_in1) == LOW) && (digitalRead(idno_in2) == HIGH)) { ///1--> node 4
      nodeid = 4;
          Serial.print("4 ");
    }
    else if ((digitalRead(idno_in1) == HIGH) && (digitalRead(idno_in2) == LOW)) { ///2 --> node 5
      nodeid = 5;
          Serial.print("5 ");
    }
    else if ((digitalRead(idno_in1) == HIGH) && (digitalRead(idno_in2) == HIGH)) { ///3 --> node 6
      nodeid = 6;
          Serial.print("6 ");
    }
    Serial.print("normal@id ");
    sendNormal();
        Serial.print("preamble ");
    sendPreamble();
        Serial.print("sendid ");
    sendNodeID(nodeid);
        Serial.print("postable ");
    senPostable();
        Serial.print("trail ");
        digitalWrite(trail_notify, HIGH);
    sendTrail();
      digitalWrite(trail_notify, LOW);
    Serial.println("Done");
  }

  else if (digitalRead(is_not_check_pin) == HIGH) {
        Serial.println("not check");
    digitalWrite(debugpin, HIGH);
    sendNormal();
    digitalWrite(debugpin, LOW);
  }





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

