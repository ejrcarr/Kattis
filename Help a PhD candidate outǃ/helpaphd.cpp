#include <iostream>
#include <string>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        std::string addition;
        std::cin >> addition;
        if (addition == "P=NP") {
            printf("skipped\n");
            continue;
        }
        int first = stoi(addition.substr(0, addition.find("+")));
        addition.erase(0, addition.find("+") + 1);
        int second = stoi(addition);
        printf("%d\n", first + second);
    }
    return 0;
}