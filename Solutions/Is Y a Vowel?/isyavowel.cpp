#include <iostream>
#include <string>

using namespace std;

int main() {
    string input, vowels("aeiou");
    cin >> input;
    int num_vowels = 0, ys = 0;
    for(auto letter : input) {
        ys += (letter == 'y');
        num_vowels += (vowels.find(letter) != string::npos);
    }
    cout << num_vowels << " " << (num_vowels + ys);
    return 0;
}