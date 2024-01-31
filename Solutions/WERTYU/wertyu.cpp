#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<string> vs;

string get_new_key(string key) {
    if (key == " ") return key;

    vector<vs> keyboard = {
        {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "BackSp"},
        {"Tab", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "\\"},
        {"A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "Enter"},
        {"Z", "X", "C", "V", "B", "N", "M", ",", ".", "/"}
    };

    for(vs key_row : keyboard) {
        auto it = find(key_row.begin(), key_row.end(), key);
        if(it != key_row.end()) {
            int index = distance(key_row.begin(), it);
            if(index - 1 >= 0) return key_row[index - 1];
            break;
        }
    }
    return "";
}

int main() {
    string input;
    while(getline(cin >> ws, input)) {
        for(char letter : input) {
            string key(1, letter);
            cout << get_new_key(key);
        }
        cout << "\n";
    }
    return 0;
}