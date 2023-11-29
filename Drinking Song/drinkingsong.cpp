#include <iostream>
#include <string>

int main() {
    int n;
    std::string beverage;
    std::cin >> n >> beverage;
    const char* c_beverage = beverage.c_str();
    for(int i = n; i > 0; --i) {
        if(i > 2) {
            printf("%d bottles of %s on the wall, %d bottles of %s.\nTake one down, pass it around, %d bottles of %s on the wall.\n\n", i, c_beverage, i, c_beverage, i - 1, c_beverage);
        }
        else if (i == 2) {
            printf("2 bottles of %s on the wall, 2 bottles of %s.\nTake one down, pass it around, 1 bottle of %s on the wall.\n\n", c_beverage, c_beverage, c_beverage);
        }
        else if(i == 1) {
            printf("1 bottle of %s on the wall, 1 bottle of %s.\nTake it down, pass it around, no more bottles of %s.\n\n", c_beverage, c_beverage, c_beverage);
        }
    }
    return 0;
}