#include <iostream>
#include <string>

int main() {
    std::string word;
    std::cin >> word;
    std::cout << ((word.find("ss") != std::string::npos) ? "hiss" : "no hiss");
    return 0;
}