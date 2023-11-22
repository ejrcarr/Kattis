#include <iostream>

int main() {
    int n, min = 1e9, index = 0, max_temp;
    scanf("%d", &n);

    int days[n];
    for(int& day : days) scanf("%d", &day);

    for(int i = 0; i < n - 2; ++i) {
        max_temp = std::max(days[i], days[i + 2]);
        if(min > max_temp) {
            min = max_temp;
            index = i;
        }
    }

    printf("%d %d", index + 1, min);
    return 0;
}