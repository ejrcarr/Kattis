#include <iostream>

int main() {
    int a, lower, greater, lower_diff = 0, greater_diff = 0;
    std::cin >> a;
    lower = a;
    greater = a;

    for (int i = 0; i < 100; ++i) {
        if (lower % 100 != 99) {
            lower--;
            lower_diff++;
        }
        if (greater % 100 != 99) {
            greater++;
            greater_diff++;
        }
    }

    if (lower_diff == greater_diff || lower_diff > greater_diff) {
        std::cout << greater;
    }
    else {
        std::cout << lower;
    }

    return 0;
}