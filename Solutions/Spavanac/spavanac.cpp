#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    cin >> a >> b;
    
    int minutes_after = b - 45;
    if (minutes_after < 0) {
        minutes_after += 60;
        a -= 1;
        if (a < 0) {
            a += 24;
        }
    }
    cout << a << " " << minutes_after;
    return 0;
}