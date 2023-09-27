int test = 0;

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

void setup() {
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
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(1, HIGH);
}