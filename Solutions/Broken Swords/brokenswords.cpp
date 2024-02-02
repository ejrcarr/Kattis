#include <iostream>

int main() {
    int n, left_total = 0, right_total = 0;
    char sword[5];
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i) {
        scanf("%4s", sword);
        left_total += 2 - ((sword[0] - '0') + (sword[1] - '0'));
        right_total += 2 - ((sword[2] - '0') + (sword[3] - '0'));
    }

    int swords_made = std::min(left_total, right_total) / 2;
    printf("%d %d %d", swords_made, left_total - swords_made * 2, right_total - swords_made * 2);
    return 0;
}