#include <iostream>

int main() {
    int n;
    for(int i = 1; std::cin >> n; ++i) {
        int min = 1e9, max = -1e9;
        for(int i = 0; i < n; ++i) {
            int num;
            scanf("%d", &num);
            min = std::min(min, num);
            max = std::max(max, num);
        }
        printf("Case %d: %d %d %d\n", i, min, max, max-min);
    }
    return 0;
}