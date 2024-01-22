#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cin >> name;
    int i = 0;
    while (i < (int)name.length()) {
        while (name[i] == name[i + 1]) {
            name.erase(i, 1);
        }
        i++;
    }
    
    std::cout << name;
    return 0;
}