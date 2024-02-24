#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int freq[26] = { 0 };
        string input;
        getline(cin >> ws, input);
        for(char letter : input) {
            if(!isalpha(letter)) continue;
            freq[tolower(letter) - 'a']++;
        }
        string missing = "";
        for(int i = 0; i < 26; ++i) {
            if (freq[i] == 0) {
                missing += 'a' + i;
            }
        }
        if(missing != "") cout << "missing " << missing << "\n";
        else cout << "pangram" << "\n";
    }
    return 0;
}