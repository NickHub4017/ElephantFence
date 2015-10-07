int deteted_pin = 12;
int not_deteted_pin = 11;
int getdata = 10;
boolean countdata = false;
int trail_pulse = 0;
int y = 0;
int data = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);

  Serial.begin(9600);
  Serial.println("Detector started");
}

void loop() {
  //Serial.println("l");
  int count = 0;

  // put your main code here, to run repeatedly:
  int x = 0;

  if (Serial.available() > 0) {
    int x = Serial.read();
    if (x == 52) {
      y = 4;
      data = 0;
                  countdata=true;
    }
    else if (x == 53) {
      y = 5;
      data = 0;
                  countdata=true;
    }
    else if (x == 54) {
      y = 6;
      data = 0;
            countdata=true;
    }
    else if(x==97){//a
      y=0;
      countdata=false;
      data=0;
      Serial.println("#d reset");
    }

  }
  int j = analogRead(A0);
  if ((j > 1000)&&(countdata)) {
    Serial.print("#d ");
    
    Serial.println(y);
    delay(100);
  }


}

unsigned long Read() {
  //unsigned long x=  getIntervalofOnes();
  unsigned long y =  getIntervalofOnes();
  //Serial.println(y);
  //Serial.println(y);
  while (y < 500) {
    y =  getIntervalofOnes();
    //Serial.print(y);
    if (y > 550) {
      //     Serial.println(y);
      return y;
    }

  }
  return y;

}
unsigned long getIntervalofOnes() {
  unsigned long timestart = millis();
  unsigned long timeend;
  unsigned long gap;
  while (analogRead(A0) < 100) {
  }
  timeend = millis();
  gap = timeend - timestart;

  return gap;
}

