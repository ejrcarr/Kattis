#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        string card_number;
        cin >> card_number;
        reverse(card_number.begin(), card_number.end());

        int total_sum = 0;
        bool is_second = false;

        for (char digit_char : card_number) {
            int digit = digit_char - '0';
            if (is_second) {
                digit = digit * 2;
                if (digit > 9) {
                    digit = (digit / 10) + (digit % 10);
                }
            }
            total_sum += digit;
            is_second = !is_second;
        }

        cout << (total_sum % 10 == 0 ? "PASS" : "FAIL") << "\n";
    }

    return 0;
}
