#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string word;
    std::cin >> word;

    std::unordered_set<char> no_dupes(word.begin(), word.end());

    std::cout << (word.size() == no_dupes.size());
    return 0;
}