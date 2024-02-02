#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d:\n", n);
    for(int i = 2; i <= (int)(n / 2.0 + .5); ++i) {
        for(int j = i - 1; j < i + 1; ++j) {
            if (n % (j + i) == 0 || (n - i) % (j + i) == 0) {
                printf("%d,%d\n", i, j);
            }
        }
    }
    return 0;
}