#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    std::unordered_set<std::string> found;
    int freq[4] = {13, 13, 13, 13};
    if((int)input.length() < 3) {
        std::cout << "GRESKA\n";
        return 0;
    }
    for(int i = 0; i < (int)input.length(); i += 3) {
        std::string card = input.substr(i, 3);
        if(found.find(card) != found.end()) {
            std::cout << "GRESKA\n";
            return 0;
        }
        if(card[0] == 'P') --freq[0];
        if(card[0] == 'K') --freq[1];
        if(card[0] == 'H') --freq[2];
        if(card[0] == 'T') --freq[3];
        found.insert(card);
    }

    for(auto num : freq) {
        std::cout << num << " ";
    }

    return 0;
}