int ls_check_send = 3;
int ls_not_check_send = 4;
int inp0_send = 5;
int inp1_send = 6;
int get_detect_ok = 7;
int get_detect_not_ok = 8;
int send_trail_status = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(ls_check_send, OUTPUT);
  pinMode(ls_not_check_send, OUTPUT);
  pinMode(inp0_send, OUTPUT);
  pinMode(inp1_send, OUTPUT);
  pinMode(get_detect_ok, INPUT);
  pinMode(get_detect_not_ok, INPUT);
    pinMode(send_trail_status, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
delay(1000);
  Serial.println("control ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ls_not_check_send, LOW);
  digitalWrite(ls_check_send, LOW);
  digitalWrite(inp0_send, LOW);
  digitalWrite(inp1_send, LOW);
  digitalWrite(ls_not_check_send, LOW);
  digitalWrite(ls_check_send, LOW);
  if (Serial.available() > 0) {
    int x = Serial.read();
    x=x-48;
    digitalWrite(ls_not_check_send, LOW);
    digitalWrite(ls_check_send, HIGH);
    Serial.print(x);
        Serial.println(" ack");
    if (x == 4) {
      digitalWrite(inp0_send, LOW);
      digitalWrite(inp1_send, HIGH);
    }
    else if (x == 5) {

      digitalWrite(inp0_send, HIGH);
      digitalWrite(inp1_send, LOW);

    }
    else if (x == 6) {

      digitalWrite(inp0_send, HIGH);
      digitalWrite(inp1_send, HIGH);
    }
    digitalWrite(13, LOW);
    int count_fail = 0;
    int count_sucess = 0;
    while (analogRead(A0)<= 100) {
      digitalWrite(13, HIGH);
    }

    digitalWrite(ls_not_check_send, HIGH);
    digitalWrite(ls_check_send, LOW);
    
    while (analogRead(A0)> 100) {

      if (digitalRead(get_detect_ok) == HIGH) {
        count_sucess++;
      }
      if (digitalRead(get_detect_not_ok) == HIGH) {
        count_fail++;
      }
    }
    

    digitalWrite(13, LOW);

    digitalWrite(ls_not_check_send, HIGH);
    digitalWrite(ls_check_send, LOW);
    
    
    if (count_sucess >= count_fail) {
      Serial.print(x);
      Serial.println (" done");

    }
    else {
      Serial.print(x);
      Serial.println(" fail");
            
    }
  }
  else {
    digitalWrite(ls_not_check_send, HIGH);
    digitalWrite(ls_check_send, LOW);
  }

}
