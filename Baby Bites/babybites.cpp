#include <iostream>
#include <string>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n + 1; ++i) {
        std::string maybe;
        std::cin >> maybe;
        if (maybe == "mumble") { continue; }
        if (stoi(maybe) != i) {
            printf("something is fishy");
            return 0;
        }
    }
    printf("makes sense");
    return 0;
}