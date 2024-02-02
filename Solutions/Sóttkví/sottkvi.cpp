#include <iostream>

int main() {
    int n, k, d, total = 0;
    scanf("%d %d %d", &n, &k, &d);
    for(int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        total += ((d - num) + k >= 14);
    }
    printf("%d", total);
    return 0;
}