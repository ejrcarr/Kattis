#include <string>
#include <iostream>

using namespace std;

int main() {
    int cups[] = {1, 0, 0};
    string a;
    cin >> a;
    int final = 1;
    for (int i = 0; i < a.size(); i++) {
        int firstPlace;
        int secondPlace;
        if (a[i] == 'A') {
            firstPlace = 0;
            secondPlace = 1;
        }
        else if (a[i] == 'B') {
            firstPlace = 1;
            secondPlace = 2;
        }
        else {
            firstPlace = 0;
            secondPlace = 2;
        }
        int temp = cups[firstPlace];
        cups[firstPlace] = cups[secondPlace];
        cups[secondPlace] = temp;
        
        if (cups[firstPlace] == 1) {
            final = firstPlace + 1;
        }
        else if (cups[secondPlace] == 1) {
            final = secondPlace + 1;
        }
    }
    cout << final;
    return 0;
}