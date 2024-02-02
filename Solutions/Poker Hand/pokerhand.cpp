#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<char, int> freq;
    int max = -1e9;
    char card[3];
    for(int i = 0; i < 5; ++i) {
        scanf("%2s", card);
        max = std::max(max, ++freq[card[0]]);
    }
    printf("%d", max);
    return 0;
}