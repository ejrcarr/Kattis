#include <iostream>
#include <string>

int main() {
    std::string action;
    double average_cost = 0, total_shares = 0;
    while(std::cin >> action) {
        if (action == "buy") {
            double shares, crowns_per_share;
            std::cin >> shares >> crowns_per_share;
            average_cost = (average_cost * total_shares + crowns_per_share * shares) / (total_shares + shares);
            total_shares += shares;
        } else if (action == "split") {
            double split_factor;
            std::cin >> split_factor;
            total_shares *= split_factor;
            average_cost /= split_factor;
        } else if (action == "merge") {
            int merge_factor;
            std::cin >> merge_factor;
            total_shares = (int) total_shares / merge_factor;
            average_cost *= merge_factor;
        } else if (action == "sell") {
            double shares, _;
            std::cin >> shares >> _; 
            total_shares -= shares;
        } else if (action == "die") {
            double crowns_per_share;
            std::cin >> crowns_per_share;
            double profit = (crowns_per_share - average_cost) * total_shares;
            double tax = profit > 0 ? profit * 0.30 : 0; 
            std::cout.precision(10);
            std::cout << std::fixed << (total_shares * crowns_per_share) - tax << std::endl;
            break;
        }
    }
    return 0;
}
