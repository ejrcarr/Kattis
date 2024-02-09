#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, count = 1;
    cin >> n;
    vector<int> path;
    while(n--) {
        int num;
        cin >> num;
        if(path.empty()) path.push_back(num);
        else if(!path.empty() && *(--path.end()) < num) {
            path.push_back(num);
            ++count;
        }
    }
    cout << count << "\n";
    for(auto num : path) cout << num << " ";
    return 0;
}