#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<char, int> lookup = {{'.', 20}, {'O', 10}, {'\\', 25}, {'/', 25}, {'A', 35}, {'^', 5}, {'v', 22}};
    int n, m, total = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        std::string row;
        std::cin >> row;
        for(auto letter : row) {
            total += lookup.at(letter);
        }
    }
    printf("%d", total);
    return 0;
}