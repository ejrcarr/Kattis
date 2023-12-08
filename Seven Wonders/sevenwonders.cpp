#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int tcg[3] = {0, 0, 0};
    int n = 3;
    std::string cards;
    std::cin >> cards;
    for(char& letter : cards) {
        switch (letter) {
            case 'T':
                tcg[0]++;
                break;
            case 'C':
                tcg[1]++;
                break;
            case 'G':
                tcg[2]++;
                break;
        }
    }

    std::cout << tcg[0]* tcg[0] + tcg[1]* tcg[1] + tcg[2]* tcg[2] + *std::min_element(tcg, tcg + n) * 7;
    return 0;
}