#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;

    bool found = false;
    for(int i = 0; i < n; ++i) {
        int num_dishes;
        std::string place;
        std::cin >> num_dishes;
        std::getline(std::cin >> std::ws, place);

        std::unordered_set<std::string> items{};
        while(num_dishes--) {
            std::string dish;
            std::getline(std::cin >> std::ws, dish);
            items.insert(dish);
        }
        bool HAS_PEA_SOUP = items.find("pea soup") != items.end();
        bool HAS_PANCAKES = items.find("pancakes") != items.end();
        if (HAS_PEA_SOUP && HAS_PANCAKES) {
            found = true;
            std::cout << place << "\n";
            break;
        }
    }
    !found && std::cout << "Anywhere is fine I guess\n";
    return 0;
}