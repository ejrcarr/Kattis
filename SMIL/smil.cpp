#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    int n = (int)input.length();
    for(int i = 0; i < n; ++i) {
        if((i + 1 < n && (input.substr(i, 2) == ":)" || input.substr(i, 1) == ";)")) || 
            (i + 2 < n && (input.substr(i, 3) == ":-)" || input.substr(i, 3) == ";-)"))) {
            std::cout << i << "\n";
        }
    }
    return 0;
}