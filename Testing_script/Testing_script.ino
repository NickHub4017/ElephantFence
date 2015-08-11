unsigned long time;
void setup() {
  // put your setup code here, to run once:
 pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
      digitalWrite(13,LOW);
  int x=analogRead(A0);
  if(x>180){
    digitalWrite(13,HIGH);
  delay(100);
        digitalWrite(13,HIGH);
Serial.println(x);
  } 

}
