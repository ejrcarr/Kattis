#include <iostream>

int main() {
    int n, total = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        if(num < 0) {
            total += num * -1;
        }
    }
    printf("%d", total);
    return 0;
}