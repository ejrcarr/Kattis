#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    double amount;
    string current_unit, _, target_unit;
    cin >> amount >> current_unit >> _ >> target_unit;
    
    int lookup[8] = {1, 1000, 12, 3, 22, 10, 8, 3};
    unordered_map<string, int> get_index = {
        {"thou", 0}, {"th", 0},
        {"inch", 1}, {"in", 1},
        {"foot", 2}, {"ft", 2},
        {"yard", 3}, {"yd", 3},
        {"chain", 4}, {"ch", 4},
        {"furlong", 5}, {"fur", 5},
        {"mile", 6}, {"mi", 6},
        {"league", 7}, {"lea", 7}
    };

    int first = get_index[current_unit];
    int second = get_index[target_unit];
    
    double total = amount;
    if (first < second) {
        for (int i = first; i < second; ++i) {
            total /= lookup[i + 1];
        }
    } else if (first > second) {
        for (int i = first; i > second; --i) {
            total *= lookup[i];
        }
    }

    cout.precision(10);
    cout << total;
    return 0;
}
