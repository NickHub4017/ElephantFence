//unsigned long time;
void setup() {

 pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  
Serial.begin(9600);
}

void loop() {

      digitalWrite(13,LOW);
  int x=analogRead(A0);
  if(x>250){
    digitalWrite(13,HIGH);

        digitalWrite(13,HIGH);
Serial.println(x);
  } 

}
