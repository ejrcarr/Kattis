#include <iostream>
#include <string>


int main() {
    std::string cpr_number;
    std::cin >> cpr_number;

    // -1 for hyphen
    int coefficient[11] = {4, 3, 2, 7, 6, 5, -1, 4, 3, 2, 1};
    int total = 0;
    for(int i = 0; i < cpr_number.size(); ++i) {
        if (cpr_number[i] != '-') {
            total += coefficient[i] * (cpr_number[i] - '0');
        }
    }
    std::cout << (total % 11 == 0);
    return 0;
}