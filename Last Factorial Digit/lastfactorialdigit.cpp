#include <iostream>

int fac(int num) {
    if(num <= 1) {
        return num;
    }
    return num * fac(num - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        printf("%d\n", fac(num) % 10);
    }
    return 0;
}