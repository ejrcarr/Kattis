#include <iostream>
#include <string>

typedef long long ll;

ll find_digits(ll n) {
    if(n < 10) { return 1; }

    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

ll find_solution(ll decimal, ll i) {
    ll digits = find_digits(decimal);
    if (decimal == digits) return i;
    return find_solution(digits, i + 1);
}

int main() {
    std::string n;
    while (std::cin >> n && n != "END") {
        if (n == "1") { printf("1\n"); continue; };
        printf("%lld\n", find_solution(n.length(), 2));
    }
    return 0;
}
