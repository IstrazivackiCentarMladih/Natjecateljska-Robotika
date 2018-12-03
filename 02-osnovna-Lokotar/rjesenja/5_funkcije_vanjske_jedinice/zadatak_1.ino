
void singleWave (int pin, float duration){
  digitalWrite(pin, LOW);
  unsigned int half_period = (unsigned int) (duration/2.);
  delayMicroseconds(half_period);
  digitalWrite(pin, HIGH);
  delayMicroseconds(half_period);
  digitalWrite(pin, LOW); //opcionalno vracanje u pocetno stanje
}

int led_pin = 7;
int count = 0;
int max_count = 100;

void setup() {
  pinMode(led_pin, OUTPUT);
}

void loop() {
  if (count < max_count){ //nije nuzno, ogranicio sam broj ponavljanja
    singleWave(led_pin, 2000000);
    count++;
  }
 }
