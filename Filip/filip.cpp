#include <iostream>

int reversed(int num) {
    int remainder, new_num = 0;
    while (num != 0) {
        remainder = num % 10;
        new_num = new_num * 10 + remainder;
        num /= 10;
    }
    return new_num;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", std::max(reversed(a), reversed(b)));
    return 0;
}