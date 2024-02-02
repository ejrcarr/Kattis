#include <iostream>

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        long long number;
        int order, base, remainder = 0, ssd = 0;
        scanf("%d %d %lld", &order, &base, &number);

        while(number > 0) {
            remainder = number % base;
            number = number / base;
            ssd += remainder * remainder;
        }
        printf("%d %d\n", order, ssd);
    }

    return 0;
}