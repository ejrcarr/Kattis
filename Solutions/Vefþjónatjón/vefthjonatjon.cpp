#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int parts[3] = {0, 0, 0};

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            std::string letter;
            std::cin >> letter;
            parts[j] += letter == "J";
        }
    }

    std::cout << std::min(std::min(parts[0], parts[1]), parts[2]);
    return 0;
}