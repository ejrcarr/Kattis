#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
    int n;
    while(cin >> n && n) {
        unordered_set<int> found;
        int prev = 1e9;
        for(int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            if(!(prev == 1e9)) {
                found.insert(abs(prev - num));
            }
            prev = num;
        }
        bool missing = false;
        for(int i = 1; i < n; ++i) {
            if (found.find(i) == found.end()) {
                missing = true;
                break;
            }
        }
        cout << ((missing) ? "Not jolly\n" : "Jolly\n");
    } 
    return 0;
}