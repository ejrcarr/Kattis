#include <iostream>

int main() {
    int g, t, n;
    scanf("%d %d %d", &g, &t, &n);
    int leftover = (g - t) * 0.9;
    int total = 0;
    for(int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        total += num;
    }
    printf("%d", leftover - total);
    return 0;
}