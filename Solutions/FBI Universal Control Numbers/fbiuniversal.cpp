#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<char, char> numerical_value = {
        {'0', 0},
        {'O', 0},
        {'Q', 0},
        {'1', 1},
        {'I', 1},
        {'2', 2},
        {'Z', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'S', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'B', 8},
        {'9', 9},
        {'A', 10},
        {'C', 11},
        {'G', 11},
        {'D', 12},
        {'E', 13},
        {'F', 14},
        {'H', 15},
        {'J', 16},
        {'K', 17},
        {'L', 18},
        {'M', 19},
        {'N', 20},
        {'P', 21},
        {'R', 22},
        {'T', 23},
        {'V', 24},
        {'U', 24},
        {'Y', 24},
        {'W', 25},
        {'X', 26},
    };
unordered_map<int, char> character_value;

int check_digit_coefficients[8] = {2, 4, 5, 7, 8, 10, 11, 13};

long long get_base_10(string num) {
    int exp = 0;
    long long total = 0;
    for(int i = (int)num.length() - 1; i >= 0; --i) {
        total += pow(27, exp) * numerical_value[num[i]];
        ++exp;
    }
    return total;
}

char get_check_digit(string num) {
    long long total = 0;
    for(int i = 0; i < (int)num.length(); ++i) {
        total += check_digit_coefficients[i] * numerical_value[num[i]];
    }
    return character_value[total % 27];
}

int main() {
    string valid_symbols = "0123456789ACDEFHJKLMNPRTVWX";
    for(auto entry : numerical_value) {
        if(valid_symbols.find(entry.first) != string::npos) {
            character_value[entry.second] = entry.first;
        }
    }

    int cases;
    cin >> cases;
    while(cases--) {
        int case_num;
        string num;
        cin >> case_num >> num;

        char check_digit;
        check_digit = *(--num.end());
        num = num.substr(0, 8);
        cout << case_num << " ";
        if(get_check_digit(num) == check_digit) {
            cout << get_base_10(num) << "\n";
        }
        else {
            cout << "Invalid\n";
        }
    }
    return 0;
}