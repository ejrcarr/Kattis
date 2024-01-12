#include <iostream>

int main() {
    int n, prev = 1, missed_number = false;
    scanf("%d", &n);
    while(n--) {
        int current;
        scanf("%d", &current);
        if(current != prev) missed_number = true;
        for(int i = prev; i < current; ++i) {
            printf("%d\n", i);
        }
        prev = current + 1;
    }
    if(!missed_number) {
        printf("good job\n");
    }
    return 0;
}