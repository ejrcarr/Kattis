#include <iostream>
#include <string>

int main() {
    int size;
    scanf("%d", &size);
    printf("+");
    for(int i = 0; i < size; ++i) {
        printf("-");
    }
    printf("+\n");
    for(int i = 0; i < size; ++i) {
       printf("|");
        for(int j = 0; j < size; ++j) {
            printf(" ");
        }
        printf("|\n");
    }
    printf("+");
    for(int i = 0; i < size; ++i) {
        printf("-");
    }
    printf("+\n");
    return 0;
}