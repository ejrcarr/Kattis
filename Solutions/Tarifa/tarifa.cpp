#include <iostream>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    int total = x;
    for (int i = 0; i < n; i++) {
        int temp = x;
        int p;
        cin >> p;
        total += (temp - p);
    }
    cout << total;
    return 0;
}