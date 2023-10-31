#include <iostream>
#include <string>
#include <vector>
#include <queue>

int main() {
    std::priority_queue<char, std::vector<char>, std::greater<char> > letters;
    std::string word1, word2;
    std::cin >> word1 >> word2;
    for(auto letter : word1 + word2) {
        letters.push(letter);
    }
    while (!letters.empty() ) {
        std::cout << letters.top();
        letters.pop();
    }
    return 0;
}