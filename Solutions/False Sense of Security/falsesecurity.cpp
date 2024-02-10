#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, string> lookup = {
        {'A', ".-"},
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."},
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-..-"},
        {'Y', "-.--"},
        {'Z', "--.."},
        {'_', "..--"},
        {',', ".-.-"},
        {'.', "---."},
        {'?', "----"},
    };

    unordered_map<string, char> opposite;

    for(auto look : lookup) opposite[look.second] = look.first;

    string input;
    while(cin >> input && input != "") {
        string numbers = "";
        string new_one = "";
        for(auto letter : input) {
            new_one += lookup[letter];
            numbers += to_string(lookup[letter].length());
        }

        string out = "";
        for(int i = numbers.length() - 1; i >= 0; --i) {
            char num = numbers[i];
            int current = num - '0';
            string temp = new_one.substr(0, current);
            new_one.erase(0, current);
            out += opposite[temp];
        }
        cout << out << "\n";
    }

    return 0;
}