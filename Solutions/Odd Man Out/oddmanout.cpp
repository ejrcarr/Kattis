#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        int unique = 0;
        for(int j = 0; j < m; ++j) {
            int num;
            std::cin >> num;
            unique ^= num;
        }
        std::cout << "Case #" << i + 1 << ": " << unique << "\n";
    }
    return 0;
}