#include <iostream>

typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);
    for(int i = 0; i < n; ++i) {
        ll current_pop, growth_factor, annual_food, count;
        scanf("%lld %lld %lld", &current_pop, &growth_factor, &annual_food);
        for(count = 0; current_pop <= annual_food; ++count) {
            current_pop *= growth_factor;
        }
        printf("%lld\n", count);
    }
    return 0;
}