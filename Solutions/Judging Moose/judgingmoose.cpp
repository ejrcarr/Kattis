#include <iostream>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if(a == b && a == 0) {
        printf("Not a moose");
    }
    else if(a == b) {
        printf("Even %d", a + b);
    }
    else if (a != b) {
        printf("Odd %d", std::max(a, b) * 2);
    }

    return 0;
}