#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<char, int> dominant = {
        {'A', 11}, 
        {'K', 4}, 
        {'Q', 3}, 
        {'J', 20}, 
        {'T', 10},
        {'9', 14},
        {'8', 0},   
        {'7', 0},   
    };
    std::unordered_map<char, int> not_dominant = {
        {'A', 11}, 
        {'K', 4}, 
        {'Q', 3}, 
        {'J', 2}, 
        {'T', 10},
        {'9', 0},
        {'8', 0},   
        {'7', 0},   
    };
    int num_hands, total = 0;
    char suit;
    std::cin >> num_hands >> suit;

    for (int i = 0; i < (num_hands * 4); ++i) {
        std::string card;
        std::cin >> card;
        if (card[1] == suit) {
            total += dominant.at(card[0]);
        }
        else {
            total += not_dominant.at(card[0]);
        }
    }

    std::cout << total << '\n';
    return 0;
}