#include <iostream>
#include <string>

int main() {
    int w_count = 0, b_count = 0;
    std::string stones;
    std::cin >> stones;
    for(char& stone : stones) {
        if (stone == 'W') {
            w_count++;
        }
        else {
            b_count++;
        }
    }
    std::cout << (w_count == b_count);
    return 0;
}