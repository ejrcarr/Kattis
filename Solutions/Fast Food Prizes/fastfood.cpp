#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int get_prize_amount(std::pair<int, std::vector<int>> prizes, std::vector<int> available) {
    std::vector<int> nums{};
    for(int& prize : prizes.second) {
        nums.push_back(available[prize - 1]);
    }
    return prizes.first * *std::min_element(nums.begin(), nums.end());
}

int main() {
    int cases;
    std::cin >> cases;
    while(cases--) {
        int n, m;
        std::cin >> n >> m;
        std::set<std::pair<int, std::vector<int>> > prizes;
        std::vector<int> available(m, 0);
        for(int i = 0; i < n; ++i) {
            int k;
            std::cin >> k;
            std::vector<int> prize_types(k);
            for(auto& type : prize_types) {
                std::cin >> type;
            }
            int amount;
            std::cin >> amount;
            prizes.insert({amount, prize_types});
        }
        for(auto& prize : available) {
            std::cin >> prize;
        }
        int total = 0;
        std::set<std::pair<int, std::vector<int> > >::reverse_iterator rev_it;
        for(rev_it = prizes.rbegin(); rev_it != prizes.rend(); rev_it++) {
            total += get_prize_amount(*rev_it, available);
        }
        std::cout << total << "\n";
    }
    return 0;
}