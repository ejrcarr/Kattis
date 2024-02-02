#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int num = 1, prev = 1, non_native = 0;
        while (num != 0) {
            std::cin >> num;
            if (prev * 2 < num) {
                non_native += num - prev * 2;
            }
            prev = num;
        }
        printf("%d\n", non_native);
    }
    return 0;
}