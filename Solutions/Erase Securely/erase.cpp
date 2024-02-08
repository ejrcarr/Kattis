#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string first, second;
    cin >> n >> first >> second;
    if(n & 1) {
        for(int i = 0; i < (int)first.length(); ++i) {
            first[i] = ((first[i] == '0') ? '1' : '0');
        }
    }
    cout << ((first == second) ? "Deletion succeeded" : "Deletion failed");
    return 0;
}