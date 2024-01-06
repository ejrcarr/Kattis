#include <iostream>

int main() {
    int cases, ticket_cap;
    while(std::cin >> cases >> ticket_cap && 
            cases != 0 && 
            ticket_cap != 0) {

        double max_ratio = -1e9;
        std::pair<int, int> tickets_to_price{-1, -1};
        for(int i = 0; i < cases; ++i) {
            double tickets, price;
            std::cin >> tickets >> price;
            double current_ratio = tickets / price;
            if(tickets <= ticket_cap &&
                (current_ratio > max_ratio ||
                (current_ratio == max_ratio && tickets > tickets_to_price.first))) {
                max_ratio = current_ratio;
                tickets_to_price = {tickets, price};
            }
        }
        if(tickets_to_price.first != -1) {
            std::cout << "Buy " << tickets_to_price.first << " tickets for $" << tickets_to_price.second << "\n";
        }
        else {
            std::cout << "No suitable tickets offered\n";
        }
    }
    return 0;
}