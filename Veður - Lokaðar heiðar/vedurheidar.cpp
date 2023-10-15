#include <iostream>
#include <string>

int main() {
    int v, n;
    std::cin >> v>> n;
    for(int i = 0; i < n; ++i) {
        std::string s;
        int k;
        std::cin >> s >> k;
        std::cout << s << " " << (v > k ? "lokud" : "opin") << "\n";
    }
    return 0;
}