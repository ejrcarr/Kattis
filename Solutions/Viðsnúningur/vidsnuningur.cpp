#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string a;
    cin >> a;
    reverse(a.begin(), a.end());
    cout << a << '\n';
    return 0;
}