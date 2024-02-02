#include <iostream>
#include <string>

int main() {
    std::string key, code;
    std::getline(std::cin, key);
    std::cin >> code;
    for(int i = 0; i < code.size(); i += 3) {
        std::string sub = code.substr(i, 3);
        std::cout << key[stoi(sub) - 1];
    }
    return 0;
}