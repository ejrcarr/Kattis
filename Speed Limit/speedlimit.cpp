#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    while(n != -1) {
        int prev = 0, total = 0;
        for(int i = 0; i < n; ++i) {
            int speed, hours;
            scanf("%d %d", &speed, &hours);
            total += speed * (hours - prev);
            prev = hours;
        }
        printf("%d miles\n", total);
        scanf("%d", &n);
    }
    return 0;
}