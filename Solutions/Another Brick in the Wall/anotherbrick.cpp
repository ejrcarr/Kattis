#include <iostream>

int main() {
    int h, w, n, total = 0, temp_total = 0;
    std::cin >> h >> w >> n;
    while(n--) {
        int num;
        std::cin >> num;
        if (temp_total + num < w) {
            temp_total += num;
            total += num;
        }
        else if(temp_total + num == w) {
            total += num;
            temp_total = 0;
        }
        else {
            std::cout << "NO\n";
            return 0;
        }

        if(total >= w * h) break;
    }
    std::cout << "YES\n";
    return 0;
}