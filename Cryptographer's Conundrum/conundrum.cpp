#include <iostream>
#include <string>

int main() {
    std::string code;
    std::cin >> code;

    int total = 0;
    for(int i = 0; i < (int)code.length(); ++i) {
        if ((i % 3 == 0 && toupper(code[i]) != 'P') ||
         (i % 3 == 1 && toupper(code[i]) != 'E') || 
         (i % 3 == 2 && toupper(code[i]) != 'R') ) {
            total++;
        }
    }
    std::cout << total;
    return 0;
}