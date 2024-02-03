#include <iostream>

using namespace std;

int main() {
    int current, target;
    cin >> current >> target;

    if ((target - current) > 180) {
        cout << (target - current - 360);
    } else if ((target - current) > -180) {
        cout << (target - current);
    } else {
        cout << (target - current + 360);
    }
    return 0;
}