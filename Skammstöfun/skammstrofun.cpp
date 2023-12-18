#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string acro_builder = "";
    for(int i = 0; i < n; ++i) {
        std::string part;
        std::cin >> part;
        if(isupper(part[0])) {
            acro_builder += part[0];
        }
    }

    std::cout << acro_builder;
    return 0;
}