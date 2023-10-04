long long step(int num, int step) {
    int res;
    res = num;
    if (step == 0) return 1;
    for (int i = 2; i <= step; i++) {
        res = res * num;
    }
    return res;
}

long long itc_bin_num(long long number) {
    long long res;
    res = 0;
    if (number >= 2) {
        for (int i = 0; number >= 2; i++) {
            if (i != 0) {
                res += (number % 2) * step(10, i);
            }
            else res += number % 2;
            if ((number / 2) < 2) res += (number / 2) * step(10, i + 1);
            number = number / 2;
        }
        return res;
    }
    return number;
}

long long binary_led(long long number){
  long long n = itc_bin_num(number);
  for (int i = 2; i <= 11; i++){
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
    pinMode(1, OUTPUT);

}
void loop() {
    int n = Serial.parseInt();
    binary_led(n);
    delay(3000);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    digitalWrite(1, LOW);
}
