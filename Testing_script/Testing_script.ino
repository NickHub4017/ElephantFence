//unsigned long time;
void setup() {

 pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  
Serial.begin(9600);
}

void loop() {

      digitalWrite(13,LOW);
      unsigned long t=millis();
  int x=analogRead(A0);
  Serial.println(x);
  /*if(x>300){
    while(x>300){
      x=analogRead(A0);
    }


  }
*/
}
