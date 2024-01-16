#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int w, n, area = 0, piece_w, piece_l;
    std::cin >> w >> n;
    while(n--) {
        std::cin >> piece_w >> piece_l;
        area += piece_w * piece_l;
    }
    std::cout << area / w;
    return 0;
}