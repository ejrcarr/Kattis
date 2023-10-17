#include <iostream>
#include <string>

int main() {
    std::string name;
    std::getline(std::cin, name);
    std::cout << "Thank you, " << name << ", and farewell!";
    return 0;
}