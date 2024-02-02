#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    cin >> a;

    int ks = 0, bs = 0;
    for(char& letter : a) {
        if (letter == 'k') {
            ks++;
        }
        else if (letter == 'b') {
            bs++;
        }
    }

    if (ks == bs) {
        cout << (ks == 0 ? "none" : "boki");
    }
    else if (ks > bs) {
        cout << "kiki";
    }
    else {
        cout << "boba";
    }
    
    return 0;
}