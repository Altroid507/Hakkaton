long long itc_bin_num(long long number) {
    if (number > 4095) return 0;
    if (number < 0) return 0;
    long long res = 0;
    long long base = 1;
    while (number > 0) {
      int d = number % 2;
      res = d * base + res;
      base = base * 10;
      number = number / 2;
    }
    return res;
}

long long binary_led(long long number){
  long long n = itc_bin_num(number);
  for (int i = 2; i <= 13; i++){
    if (n % 10 == 1) digitalWrite(i, HIGH);
    n = n / 10;
  }
}

void setup() {
    Serial.begin(9600);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);

}
void loop() {
    int n = Serial.parseInt();
    binary_led(n);
    delay(1500);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
}
