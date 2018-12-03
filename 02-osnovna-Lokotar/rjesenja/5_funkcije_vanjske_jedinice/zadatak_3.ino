

unsigned int ultrasocinTime(int triggerPin, int dataPin){
   int repetition = 5, i=0;
   unsigned long sum_duration = 0;
   
   for (i=0; i<repetition; i++){
      digitalWrite(triggerPin, LOW);
      delayMicroseconds(2);
      digitalWrite(triggerPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(triggerPin, LOW);
      sum_duration+= pulseIn(dataPin, HIGH);
      delay(65);
   }
   return (unsigned int) (sum_duration/repetition);
}




int trig_pin = 8;
int echo_pin = 7;
int count = 0;
int max_count = 10;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  
}


void loop() {
 if (count < max_count){ //nije nuzno, ogranicio sam broj ponavljanja
    unsigned int duration = ultrasocinTime( trig_pin, echo_pin);
    Serial.print(duration);
    count++;
  }

}
