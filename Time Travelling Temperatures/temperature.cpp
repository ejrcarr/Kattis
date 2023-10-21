#include <iostream>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if(x == 0 && y == 1) {
        printf("ALL GOOD");
    }
    else if (y == 1) {
        printf("IMPOSSIBLE");
    }
    else {
        printf("%lf", x / (1.0 - y));
    }
    return 0;
}