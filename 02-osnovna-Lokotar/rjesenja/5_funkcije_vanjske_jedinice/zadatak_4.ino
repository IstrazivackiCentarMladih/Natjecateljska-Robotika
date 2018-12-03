
int trig_pin = 13;
int echo_pin = 12;


unsigned int ultrasonicTime(int triggerPin, int dataPin){
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

unsigned int distance_cm(){
  unsigned int duration = ultrasonicTime(trig_pin, echo_pin);
  unsigned int distance = (duration/2.)/29.1;
  return distance;
}

int count = 0;
int max_count = 10;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  
}


void loop() {
 if (count < max_count){ //nije nuzno, ogranicio sam broj ponavljanja
    unsigned int distance = distance_cm();
    Serial.print(distance);
    count++;
  }

}
