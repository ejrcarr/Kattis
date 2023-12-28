#include <iostream>
#include <unordered_map>

int main() {
    int n;
    scanf("%d", &n);
    std::unordered_map<int, int> val_to_index;
    for(int i = 0; i < n - 1; ++i) {
        int position;
        scanf("%d", &position);
        val_to_index[position] = i + 2;
    }
    printf("1 ");
    for(int i = 0; i < n - 1; ++i) { printf("%d ", val_to_index[i]); };
    return 0;
}