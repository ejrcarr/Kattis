#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string code, guess;
    cin >> n >> code >> guess;

    int code_freq[26] = {}, guess_freq[26] = {};
    int in_place = 0, wrong_position = 0;
    for(int i = 0; i < (int)code.length(); ++i) {
        if(code[i] == guess[i]) {
            ++in_place;
            continue;
        }
        code_freq[code[i] - 'A']++;
        guess_freq[guess[i] - 'A']++;
    }


    for(int i = 0; i < (int)guess.length(); ++i) {
        int index = guess[i] - 'A';
        if(code_freq[index] > 0 && guess_freq[index] > 0) {
            --code_freq[index];
            --guess_freq[index];
            ++wrong_position;
        }
    }

    cout << in_place << " " << wrong_position;
    return 0;
}