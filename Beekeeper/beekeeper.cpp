#include <iostream>

int main() {
    int n;
    while(std::cin >> n && n != 0) {
        std::string max_string;
        int maximum = -1e9;
        for(int i = 0; i < n; ++i) {
            int count = 0;
            std::string career;
            std::cin >> career;
            for(int j = 0; j < (int)career.length() - 1; ++j) {
                std::string next_two = career.substr(j, 2);
                if(next_two == "aa" ||
                    next_two == "ee" ||
                    next_two == "ii" ||
                    next_two == "oo" ||
                    next_two == "uu" ||
                    next_two == "yy") {
                        ++count;
                }
            }
            if(count > maximum) {
                maximum = count;
                max_string = career;
            }
        }
        std::cout << max_string << "\n";
    }
    return 0;
}