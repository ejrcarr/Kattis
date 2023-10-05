#include <iostream>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a > c) {
        std::swap(a, c);
    }
    if(b > c) {
        std::swap(b, a);
    }
    if(a > b) {
        std::swap(a, b);
    }

    if(b - a == c - b) {
        printf("%d", c + (c - b));
    }
    else if(b - a > c - b) {
        printf("%d", a + (c - b));
    }
    else {
        printf("%d", b + (b - a));
    }

    return 0;
}