#include <iostream>
#include <cmath>

typedef long long ll;

int main() {
    ll p, a, b, c, d, n;
    scanf("%lld %lld %lld %lld %lld %lld", &p, &a, &b, &c, &d, &n);

    double current_max = -1e9;
    double decline = 0.00;
    for(int i = 1; i <= n; ++i) {
        double price = p * (sin(a * i + b) + cos(c * i + d) + 2);
        current_max = std::max(current_max, price);
        if (current_max - price > decline) {
            decline = current_max - price;
        }
    }
    printf("%lf", decline);
    return 0;
}