#include <iostream>

int main() {
    int cases;
    std::cin >> cases;
    for(int i = 1; i <= cases; ++i) {
        std::string s, t;
        std::cin >> s >> t;

        int differences = 0;
        int zero_one = 0;
        int one_zero = 0;
        int question_one = 0;

        for(int j = 0; j < (int)s.size(); ++j) {
            differences += (s[j] != t[j]);
            zero_one += (s[j] == '0' && t[j] == '1');
            one_zero += (s[j] == '1' && t[j] == '0');
            question_one += (s[j] == '?' && t[j] == '1');
        }

        // swaps are limited by the number where 1 & 0 and 0 & 1 are the same
        int swaps = std::min(zero_one, one_zero);

        // after swaps, we could just turn any 0 into 1 where T is 1
        int moves = differences - swaps;

        // if S has too many 1s then it's impossible to convert
        if(one_zero > zero_one + question_one) moves = -1;

        std::cout << "Case " << i << ": " << moves << "\n";
    }
}
