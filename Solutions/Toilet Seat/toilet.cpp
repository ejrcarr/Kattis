#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    int up = 0, down = 0, left = (input[0] != input[1]);

    if(input.substr(0, 2) == "UU") {
        down += 1;
    }
    else if(input.substr(0, 2) == "DD") {
        up += 1;
    }
    else if (input.substr(0, 2) == "UD") {
        up += 2;
        down += 1;
    }
    else {
        up += 1;
        down += 2;
    }
    
    for(int i = 2; i < (int)input.length(); ++i) {
        up += (input[i] == 'U' ? 0 : 2);
        down += (input[i] == 'D' ? 0 : 2);
        if (input[i - 1] != input[i]) {
            ++left;
        }
    }
    cout << up << "\n" << down << "\n" << left;
    return 0;
}