#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, last = 0;
    cin >> n;
    
    vector<string> words(n);
    vector<int> together[n];
    for(string& word : words) cin >> word;
    for(int i = 0; i < (n - 1); ++i) {
        cin >> a >> b;
        --a; --b;
        together[a].push_back(b);
        last = a;
    }

    stack<int> explore;
    explore.push(last);
    while(!explore.empty()) {
        int current_index = explore.top(); explore.pop();
        cout << words[current_index];
        for (int i = (int) together[current_index].size() - 1; i >= 0; --i) {
            explore.push(together[current_index][i]);
        }
    }

    return 0;
}