#include <iostream>

int main() {
    double n; 
    scanf("%lf", &n);
    printf("%d", (int)(n * 1000 * (5280.0/4854.0) + .5));
    return 0;
}