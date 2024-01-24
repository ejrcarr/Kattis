#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    int guess;
    string result;
    bitset<11> guesses;
    guesses.set();
    while(cin >> guess && guess != 0 && getline(cin >> ws, result)) {
        if (result == "too high") {
            for(int i = guess; i <= 10; ++i) guesses[i] = 0;
        }
        else if (result == "too low") {
            for(int i = 0; i <= guess; ++i) guesses[i] = 0;
        }
        else {
            cout << (guesses[guess] ? "Stan may be honest\n" : "Stan is dishonest\n");
            guesses.set();
        }
    }
    return 0;
}