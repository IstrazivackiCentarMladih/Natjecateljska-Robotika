
void singleWave (int pin, float duration){
  digitalWrite(pin, LOW);
  unsigned int half_period = (unsigned int) (duration/2.);
  delayMicroseconds(half_period);
  digitalWrite(pin, HIGH);
  delayMicroseconds(half_period);
  digitalWrite(pin, LOW); //opcionalno vracanje u pocetno stanje
}

void playTone (float frequencyHz, float durationMillis, int pin){
  float n = frequencyHz*durationMillis/1000.;
  float singleDuration = durationMillis/n*1e3;
  int i=0;
  for (i=0; i<n; i++){
     singleWave(pin, singleDuration);
  }
  
}

int piezzo_pin = 13;
int count = 0;
int max_count = 1;

void setup() {
  pinMode(piezzo_pin, OUTPUT);
}

void loop() {
  if (count < max_count){ //nije nuzno, ogranicio sam broj ponavljanja
    playTone(200, 10000, piezzo_pin);
    count++;
  }
 }
