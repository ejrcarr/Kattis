#include <iostream>
#include <string>

int main() {
    std::string name;
    std::getline(std::cin, name);

    int a, b, ab;
    scanf("%d %d %d", &a, &b, &ab);
    printf("%s", ((ab < 0) ? "JEDI" : ((a - b) > 0 ? "VEIT EKKI" : "SITH")));
    return 0;
}