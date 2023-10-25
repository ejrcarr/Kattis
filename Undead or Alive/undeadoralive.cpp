#include <iostream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    if(input.find(":(") != std::string::npos && input.find(":)") != std::string::npos) {
        std::cout << "double agent\n";
    }
    else if(input.find(":(") != std::string::npos) {
        std::cout << "undead\n";
    }
    else if(input.find(":)") != std::string::npos) {
        std::cout << "alive\n";
    }
    else {
        std::cout << "machine\n";
    }
    return 0;
}