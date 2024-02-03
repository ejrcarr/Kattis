#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int i = 1;
    string name, tonality;
    unordered_map<string, string> alternate = {{"A#", "Bb"}, {"Bb", "A#"}, {"C#", "Db"}, {"Db", "C#"}, {"D#", "Eb"}, {"Eb", "D#"}, {"F#", "Gb"}, {"Gb", "F#"}, {"G#", "Ab"}, {"Ab", "G#"}};
    while(cin >> name >> tonality) {
        cout << "Case " << i << ": " <<((alternate.count(name) != 0) ? alternate[name] + " " + tonality : "UNIQUE") << "\n";
        i++;
    }
    return 0;
}