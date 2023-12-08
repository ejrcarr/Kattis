#include <iostream>
#include <string>

int main() {
    std::string first, second, third, fourth;
    std::getline(std::cin, first);
    std::getline(std::cin, second);

    third = first.substr(0, first.find("|"));
    fourth = second.substr(0, second.find("|"));
    first.erase(0, first.find("|") + 1);
    second.erase(0, second.find("|") + 1);

    std::cout << third + fourth << " " << first + second;
    return 0;
}