#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    int k, m;
    while(std::cin >> k >> m && k != 0) {
        std::unordered_set<std::string> chosen_courses{};
        bool good_to_go = true;
        for(int i = 0; i < k; ++i) {
            std::string course;
            std::cin >> course;
            chosen_courses.insert(course);
        }
        for(int i = 0; i < m; ++i) {
            int num__courses, num_required, already_have = 0;
            std::cin >> num__courses >> num_required;
            for(int j = 0; j < num__courses; ++j) {
                std::string course;
                std::cin >> course;
                if(chosen_courses.find(course) != chosen_courses.end()) {
                    already_have++;
                }
            }
            if(good_to_go && already_have < num_required) {
                good_to_go = false;
            }
        }
        std::cout << (good_to_go ? "yes\n" : "no\n");
    }
    return 0;
}