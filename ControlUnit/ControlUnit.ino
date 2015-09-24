int ls_check_send = 3;
int ls_not_check_send = 4;
int inp0_send = 5;
int inp1_send = 6;
int get_detect_ok = 7;
int get_detect_not_ok = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(ls_check_send, OUTPUT);
  pinMode(ls_not_check_send, OUTPUT);
  pinMode(inp0_send, OUTPUT);
  pinMode(inp1_send, OUTPUT);
  pinMode(get_detect_ok, INPUT);
  pinMode(get_detect_not_ok, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);

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
    digitalWrite(ls_not_check_send, LOW);
    digitalWrite(ls_check_send, HIGH);
    if (x == 52) {
      digitalWrite(inp0_send, LOW);
      digitalWrite(inp1_send, HIGH);
    }
    else if (x == 53) {

      digitalWrite(inp0_send, HIGH);
      digitalWrite(inp1_send, LOW);

    }
    else if (x == 54) {

      digitalWrite(inp0_send, HIGH);
      digitalWrite(inp1_send, HIGH);
    }
    digitalWrite(13, LOW);
    while ((digitalRead(get_detect_ok) == LOW) && (digitalRead(get_detect_not_ok) == LOW)) {
      digitalWrite(13, HIGH);
    }
    digitalWrite(13, LOW);
    if (digitalRead(get_detect_ok) == HIGH) {
    }
    else if (digitalRead(get_detect_ok) == HIGH) {
    }
    digitalWrite(ls_not_check_send, HIGH);
    digitalWrite(ls_check_send, LOW);
  }
  else {
    digitalWrite(ls_not_check_send, HIGH);
    digitalWrite(ls_check_send, LOW);
  }

}
