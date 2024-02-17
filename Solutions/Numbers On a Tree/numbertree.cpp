#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n, distance_from_maximum = 1;
    string input;
    cin >> n >> input;

    int maximum =  pow(2, n + 1);
    for(char instruction : input) {
        distance_from_maximum *= 2;
        distance_from_maximum += (instruction == 'R');
    }
    cout << maximum - distance_from_maximum;
    return 0;
}