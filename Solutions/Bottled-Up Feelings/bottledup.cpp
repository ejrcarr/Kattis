#include <iostream>

int main() {
    int volume, large, small;
    std::cin >> volume >> large >> small;
    for(int i = volume / large + .5; i >= 0; --i) {
        int difference = volume - (large * i);
        if(difference >= 0 && difference % small == 0) {
            std::cout << i << " " << difference / small;
            return 0;
        }
    }
    std::cout << "Impossible";
    return 0;
}