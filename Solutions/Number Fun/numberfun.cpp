#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        double a, b, c;
        scanf("%lf %lf %lf", &a, &b, &c);
        if ((a + b == c) || (a - b == c) || (a * b == c) || (a / b == c) ||
             (b / a == c) || (b - a == c)) {
            printf("Possible\n");
        }
        else {
            printf("Impossible\n");
        }
    }
    return 0;
}