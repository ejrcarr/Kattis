#include <iostream>

int main() {
    int w, l;
    while(std::cin >> w >> l && w && l) {
        int n, rx = 0, ry = 0, x = 0, y = 0;
        std::cin >> n;
        while(n--) {
            char direction;
            int walk_length;
            std::cin >> direction >> walk_length;

            bool IS_VERTICAL = (direction == 'u' || direction == 'd');
            bool IS_POSITIVE = (direction == 'u' || direction == 'r');
            int delta = (IS_POSITIVE ? 1 : -1) * walk_length;;
            if(IS_VERTICAL) {
                y = std::max(std::min(y + delta, l - 1), 0);
                ry += delta;
            }
            else {
                x = std::max(std::min(x + delta, w - 1), 0);
                rx += delta;
            }
        }
        std::cout << "Robot thinks " << rx << " " << ry << "\n";
        std::cout << "Actually at " << x << " " << y << "\n\n";
    }
    return 0;
}