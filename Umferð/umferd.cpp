#include <iostream>
#include <string>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    double total = 0.0;
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for(auto letter: row) {
            if (letter == '.') {
                total += 1;
            }
        }
    }
    printf("%f", total / (double) (m * n));
    return 0;
}