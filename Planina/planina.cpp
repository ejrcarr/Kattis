#include <iostream>

int main() {
    int n, start = 2;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        start += start - 1;
    }

    printf("%d", start*start);
    return 0;
}