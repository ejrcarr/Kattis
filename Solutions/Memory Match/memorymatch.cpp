#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cards, turns, count = 0;
    std::cin >> cards >> turns;

    int unique_cards = cards / 2;

    std::unordered_set<int> positions_found;
    std::unordered_set<std::string> card_type_found;
    std::unordered_map<std::string, int> freq;

    
    while(turns--) {
        int position_one, position_two;
        std::string card_one, card_two;
        std::cin >> position_one >> position_two >> card_one >> card_two;

        if(card_one == card_two) card_type_found.insert(card_one);
        if(positions_found.insert(position_one).second) ++freq[card_one];
        if(positions_found.insert(position_two).second) ++freq[card_two];
    }

    for(auto& item : freq) {
        count += (item.second == 2 && card_type_found.find(item.first) == card_type_found.end());
    }

    bool ALL_ARE_FOUND_BUT_ONE = (int)positions_found.size() == cards - 2 && (int)freq.size() == unique_cards - 1;
    bool ONE_REMAINING = (int)positions_found.size() == cards - 1;


    bool ALL_ARE_FOUND = (int)freq.size() == unique_cards;
    if(ALL_ARE_FOUND) {
        count += cards - (int)positions_found.size();
    }
    else if(ALL_ARE_FOUND_BUT_ONE || ONE_REMAINING) {
        ++count;
    }
    std::cout << count;

    return 0;
}