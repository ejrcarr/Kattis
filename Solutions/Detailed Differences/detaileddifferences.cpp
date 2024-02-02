#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string one, two;
        std::cin >> one >> two;
        std:: cout << one << "\n" << two << "\n";
        for(int j = 0; j < one.size(); ++j) {
            std::cout << ((one[j] != two[j]) ? "*" : ".");
        }
        std::cout << "\n\n";
    }
    return 0;
}