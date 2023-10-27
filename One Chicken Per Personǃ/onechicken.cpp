#include <iostream>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) {
        printf("Dr. Chaz needs %d more piece%s of chicken!\n", a - b, (a - b == 1 ? "" : "s"));
    }
    else {
        printf("Dr. Chaz will have %d piece%s of chicken left over!\n", b - a, (b - a == 1 ? "" : "s"));
    }
    return 0;
}