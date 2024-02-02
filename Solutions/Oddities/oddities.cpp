#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        printf("%d is %s\n", num, (num % 2) ? "odd" : "even");
    }
    return 0;
}