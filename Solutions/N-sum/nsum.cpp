#include <iostream>

using namespace std;

int main() {
    int n, total = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        total += b;
    }

    cout << total;
    return 0;
}