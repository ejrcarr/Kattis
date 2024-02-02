#include <iostream>

int main() {
    int n, x;
    std::cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        int uses;
        std::cin >> uses;
        x -= uses;
    }

    std::cout << ((x < 0) ? "Neibb" : "Jebb"); 
    return 0;
}