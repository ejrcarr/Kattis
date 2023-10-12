#include <iostream>
#include <string>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    std::string s = "";
    for(int i = 0; i < n; ++i) {
        std::string line;
        std::cin >> line;
        for(char letter : line) {
            if (letter != '.') {
                s += letter;
            }
        }
    }
    std::cout << s;
    return 0;
}