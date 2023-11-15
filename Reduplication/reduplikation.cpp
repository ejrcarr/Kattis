#include <iostream>
#include <string>

int main() {
    std::string word;
    int times;
    std::cin >> word >> times;
    for(int i = 0; i < times; ++i) {
        std::cout << word;
    }
    return 0;
}