#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int without, profit, cost;
        scanf("%d %d %d", &without, &profit, &cost);
        if (without == (profit - cost)) {
            printf("does not matter\n");
        }
        else if (without > (profit - cost)) {
            printf("do not advertise\n");
        }
        else {
            printf("advertise\n");
        }
    }

    return 0;
}