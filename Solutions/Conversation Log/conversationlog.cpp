#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream> 
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, int> freq;
    unordered_map<string, unordered_set<string>> word_to_names;
    unordered_set<string> all_names;
    string line, name, word;

    int cases;
    cin >> cases;
    cin.ignore();
    while(cases--) {
        getline(cin, line);
        istringstream ss(line);
        ss >> name;
        all_names.insert(name);
        while (ss >> word) {
            freq[word]++;
            word_to_names[word].insert(name);
        }
    }

    vector<string> keys_to_remove;
    for (auto pair : word_to_names) {
        if (pair.second.size() != all_names.size()) {
            keys_to_remove.push_back(pair.first);
        }
    }

    for (string key : keys_to_remove) {
        freq.erase(key);
        word_to_names.erase(key);
    }

    if (freq.empty()) {
        cout << "ALL CLEAR\n";
        return 0;
    }

    vector<pair<int, string>> freq_words;
    for (auto it : freq) {
        freq_words.emplace_back(-it.second, it.first);
    }

    sort(freq_words.begin(), freq_words.end());

    for (auto it : freq_words) {
        cout << it.second << endl;
    }

    return 0;
}
