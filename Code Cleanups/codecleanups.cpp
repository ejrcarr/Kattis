#include <iostream>
#include <vector>

int main() {
    int n, MAX_DIRTINESS = 20, count = 1, dirtiness = 0, prev_day = 0;
    std::cin >> n;

    std::vector<int> dirt_days;
    dirt_days.reserve(n);

    while(n--) {
        int day;
        std::cin >> day;

        int days_passed = (day - prev_day);
        dirtiness += days_passed * dirt_days.size();
        dirt_days.push_back(day);

        if(dirtiness >= MAX_DIRTINESS) {
            dirt_days.clear();
            dirt_days.push_back(day);
            dirtiness = 0;
            ++count;
        }

        prev_day = day;
    }
    std::cout << count;
    return 0;
}