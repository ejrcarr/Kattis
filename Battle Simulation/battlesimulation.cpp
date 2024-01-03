#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;
    int input_size = input.length();
    for(int i = 0; i < input_size; ++i) {
        if(i + 2 < input_size && 
           input[i] != input[i + 1] && 
           input[i] != input[i + 2] && 
           input[i + 1] != input[i + 2]) {
                std::cout << "C";
                i += 2;
                continue;
        }
        switch(input[i]) {
            case 'R': std::cout << "S"; break;
            case 'B': std::cout << "K"; break;
            case 'L': std::cout << "H"; break;
        }
    }
    return 0;
}