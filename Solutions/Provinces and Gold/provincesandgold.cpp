#include <iostream>

int main() {
    int g, s, c, total;
    scanf("%d %d %d", &g, &s, &c);

    total = (g * 3 + s * 2 + c * 1);
    if (total >= 8) {
        std::cout << "Province or Gold";
    }
    else if (total >= 6) {
        std::cout << "Duchy or Gold";
    }
    else if (total >= 5) {
        std::cout << "Duchy or Silver";
    }
    else if (total >= 3) {
        std::cout << "Estate or Silver";
    }
    else if (total >= 2) {
        std::cout << "Estate or Copper";
    }
    else {
        std::cout << "Copper";
    }
    return 0;
}