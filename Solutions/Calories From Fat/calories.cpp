#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

vector<float> calculate_calories(const string& line, const int* calories_per_gram) {
    istringstream sin(line);
    string types[5];
    sin >> types[0] >> types[1] >> types[2] >> types[3] >> types[4];

    vector<int> missed_indices;
    float numbers[5] = {0, 0, 0, 0, 0};
    float percent_total = 0;
    float temp_total = 0;
    vector<float> total_calories(5, 0);

    for (int i = 0; i < 5; ++i) {
        char type = types[i].back();
        float number = stof(types[i].substr(0, types[i].length() - 1));
        numbers[i] = number;

        if (type == '%') {
            percent_total += number;
            missed_indices.push_back(i);
        } else if (type == 'g') {
            total_calories[i] = calories_per_gram[i] * number;
            temp_total += calories_per_gram[i] * number;
        } else {
            total_calories[i] = number;
            temp_total += number;
        }
    }

    temp_total /= (1 - percent_total / 100.0);
    for (int index : missed_indices) {
        float number = numbers[index];
        total_calories[index] = temp_total * (number / 100.0);
    }

    return total_calories;
}

int main() {
    int calories_per_gram[5] = {9, 4, 4, 4, 7};
    string line;

    while (true) {
        getline(cin, line);
        if (line == "-") break;
        vector<float> total_calories = calculate_calories(line, calories_per_gram);
        while (true) {
            getline(cin, line);
            if (line == "-") break;
            vector<float> current_calories = calculate_calories(line, calories_per_gram);
            for (int i = 0; i < 5; ++i) {
                total_calories[i] += current_calories[i];
            }
        }
        cout << round(100 * total_calories[0] / accumulate(total_calories.begin(), total_calories.end(), 0.0f)) << "%" << endl;
    }

    return 0;
}
