#include <iostream>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        int sum_of_scores, difference;
        cin >> sum_of_scores >> difference;
        if(difference > sum_of_scores) {
            cout << "impossible\n";
            continue;
        }

        bool found = false;
        for(int i = sum_of_scores - difference; i >= 0; --i) {
            int large = i + difference;
            int small = i;
            if(large + small == sum_of_scores) {
                found = true;
                cout << large << " " << small << "\n";
                break;
            }
        }
        if (found) continue;
        else cout << "impossible\n";
    }
    return 0;
}