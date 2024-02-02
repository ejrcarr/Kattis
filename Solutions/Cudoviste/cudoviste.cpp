#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    std::vector<std::string> map(n);
    for(std::string& line : map) {
        std::cin >> line;
    }

    int num_cars[5] = {0, 0, 0, 0, 0};
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < m - 1; ++j) {
            std::vector<char> spaces = {map[i][j], map[i + 1][j], map[i][j + 1], map[i + 1][j + 1]};
            if (std::find(spaces.begin(), spaces.end(), '#') != spaces.end()) { continue; }
            int car_count = 0;
            for(char& space : spaces) {
                if (space == 'X') { car_count++; }
            }
            num_cars[car_count]++;
        }
    }

    for(int& count : num_cars) {
        std::cout << count << "\n";
    }
    return 0;
}