#include <iostream>

int main() {
    int n, total = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        total += num;
    }
    for (int i = 0; i < n - 1; ++i) {
        int num;
        scanf("%d", &num);
        total -= num;
    }
    printf("%d", total);
    return 0;
}