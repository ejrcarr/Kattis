#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int id, days;
        scanf("%d %d", &id, &days);
        int gauss = (days * (days + 1)) / 2;
        printf("%d %d\n", id, gauss + days);
    }
    return 0;
}