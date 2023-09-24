#include <iostream>
#include <vector>

int main() {
    int num_tea, num_toppings;
    scanf("%d", &num_tea);
    std::vector<int> tea(num_tea);
    for(int& type : tea) scanf("%d", &type);

    scanf("%d", &num_toppings);
    std::vector<int> toppings(num_toppings);
    for(int& topping : toppings) scanf("%d", &topping);

    int minimum = 1e9;
    for(int i = 0; i < num_tea; ++i) {
        int num_following;
        scanf("%d", &num_following);
        while(num_following--) {
            int top;
            scanf("%d", &top);
            minimum = std::min(tea[i] + toppings[top - 1], minimum);
        }
    }

    long long money;
    scanf("%lld", &money);
    printf("%lld", ((((money / minimum) - 1) > 0) ? ((money / minimum) - 1) : 0 ));
    return 0;
}