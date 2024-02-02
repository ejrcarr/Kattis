#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, count = 0;
    std::string type;
    std::cin >> n >> type;

    std::vector<int> cards(n), builder(n);
    for(int i = 0; i < n; ++i) {
        cards[i] = i;
        builder[i] = i;
    }

    if(type == "out") {
        do {
            std::vector<int> first_half{builder.begin(), builder.end() - std::floor((n / 2.0))};
            std::vector<int> second_half{builder.begin() + std::ceil((n / 2.0)), builder.end()};

            builder = {};
            for(int i = 0; i < (int)first_half.size(); ++i) {
                builder.push_back(first_half[i]);
                if(i < (int)second_half.size()) builder.push_back(second_half[i]);
            }
            ++count;
        }
        while(builder != cards);
    } else {
        do {
            // first half of the deck must have one more
            std::vector<int> first_half{builder.begin(), builder.end() - std::ceil((n / 2.0))};
            std::vector<int> second_half{builder.begin() + std::floor((n / 2.0)), builder.end()};

            builder = {};
            for(int i = 0; i < (int)second_half.size(); ++i) {
                builder.push_back(second_half[i]);
                if(i < (int)first_half.size()) builder.push_back(first_half[i]);
            }
            ++count;
        }
        while(builder != cards);
    }

    std::cout << count;

    return 0;
}