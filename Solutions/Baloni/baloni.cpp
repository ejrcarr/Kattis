#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> height_to_count;
    while(n--) {
        int height;
        cin >> height;
        // we will pop this one with the higher one 
        if(height_to_count[height + 1]) height_to_count[height + 1]--;
        height_to_count[height]++;
    }

    int count = 0;
    for(auto item : height_to_count) {
        count += item.second;
    }
    cout << count;

    return 0;
}