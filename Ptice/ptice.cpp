#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::string answers;
    std::cin >> n >> answers;

    std::vector<std::string> names = {"Adrian", "Bruno", "Goran"};
    std::vector<std::string> patterns = {"ABCABCABCABC", "BABCBABCBABC", "CCAABBCCAABB"};
    std::vector<int> scores(3, 0);

    for (int i = 0; i < answers.length(); ++i) {
        for (int j = 0; j < 3; ++j) {
            if (answers[i] == patterns[j][i % 12]) {
                scores[j]++;
            }
        }
    }

    int maxScore = *std::max_element(scores.begin(), scores.end());
    std::cout << maxScore << std::endl;

    for (int i = 0; i < 3; ++i) {
        if (scores[i] == maxScore) {
            std::cout << names[i] << std::endl;
        }
    }

    return 0;
}
