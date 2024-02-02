#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long double total = 0;
    for (int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        total += (a * b);
    }
    cout.precision(100000);
    cout << total;
    return 0;
}