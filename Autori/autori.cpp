#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    cin >> a;
    cout << a[0];
    for(int i = 0; i < a.size(); ++i) {
        if (a[i] == '-') {
            cout << a[i + 1];
        }
    }
    return 0;
}