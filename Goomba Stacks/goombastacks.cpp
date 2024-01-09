#include <iostream>

int main() {
    int n, total = 0;
    std::cin >> n;
    while(n--) {
        int num, required;
        std::cin >> num >> required;
        total += num;
        if(total < required) {
            std::cout << "im";
            break;
        }
    }
    std::cout << "possible";
    return 0;
}