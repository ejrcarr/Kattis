#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::unordered_set<std::string> found;

    std::string sentence;
    std::getline(std::cin, sentence);

    bool duplicate_found = false;
    while (sentence.find(" ") != std::string::npos) {
        std::string word = sentence.substr(0, sentence.find(" "));
        if(found.find(word) != found.end()) {
            duplicate_found = true;
        }
        found.insert(word);
        sentence.erase(0, sentence.find(" ") + 1);
    }
    if (!duplicate_found && found.find(sentence) != found.end()) {
        duplicate_found = true;
    }
    std::cout << (duplicate_found ? "no" : "yes");
    return 0;
}