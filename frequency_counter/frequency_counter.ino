//http://electronicdesign.com/content/content/62021/61517-fig-1.jpg
//http://makezine.com/2009/07/28/frequency-counter-library-for-ardui/
//http://interface.khm.de/index.php/lab/interfaces-advanced/arduino-frequency-counter-library/

#include <FreqCounter.h>

void setup() {
  Serial.begin(57600);                    // connect to the serial port
  Serial.println("Frequency Counter");
}

long int frq;
void loop() {

 FreqCounter::f_comp= 8;             // Set compensation to 12
 FreqCounter::start(100);            // Start counting with gatetime of 100ms
 while (FreqCounter::f_ready == 0)         // wait until counter ready
 
 frq=FreqCounter::f_freq;            // read result
 Serial.println(frq);                // print result
 delay(20);
}
