#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int m, prev = 0, index = 0;
        scanf("%d", &m);
        for(int j = 0; j < m; ++j) {
            int num;
            scanf("%d", &num);
            if (prev + 1 != num) {
                index = j;
            }
            prev = num;
        }
        printf("%d\n", index);
    }
    return 0;
}