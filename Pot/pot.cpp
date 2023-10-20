#include <iostream>
#include <math.h>

int main() {
    int n, total = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        total += pow(num / 10, num % 10);
    }
    printf("%d", total);
    return 0;
}