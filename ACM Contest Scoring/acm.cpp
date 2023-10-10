#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int n, points = 0, solved = 0;
    std::string problem, is_correct;

    std::unordered_map<std::string, int> found;

    while(std::cin >> n && n != -1) {
        std::cin >> problem >> is_correct;
        if(is_correct == "right") {
            if(found.find(problem) != found.end()) {
                points += found[problem] * 20 + n;
            }
            else {
                points += n;
            }
            solved++;
        }
        else {
            if(found.find(problem) != found.end()) {
                found[problem]++;
            }
            else {
                found[problem] = 1;
            }
        }
    }

    printf("%d %d", solved, points);

    return 0;
}