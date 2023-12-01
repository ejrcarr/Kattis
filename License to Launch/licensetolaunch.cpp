#include <iostream>

int main() {
    int n, min = 1e9, index = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        if (num < min) {
            min = num;
            index = i;
        }
    }
    printf("%d", index);
    return 0;
}