#include <iostream>

int main() {
    int climb_rate, fall_amount, height, count = 0, total = 0;
    std::cin >> climb_rate >> fall_amount >> height;

    // input is small enough for iteration otherwise math approach
    while(total < height) {
        ++count;
        total += climb_rate;
        if(total >= height) {
            std::cout << count;
            break;
        }
        total -= fall_amount;
    }
    return 0;
}
