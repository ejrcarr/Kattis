#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> items(n);
    for(int& item : items) cin >> item;
    sort(items.begin(), items.end());
    while(items.size() >= 2 && *(--items.end()) + *(items.end() - 2) > x) {
        items.pop_back();
    }
    cout << items.size();
    return 0;
}