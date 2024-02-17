#include <iostream>
#include <vector>

using namespace std;

void handle_height(int height, int& current_min, int& current_height, int& result) {
    if(current_height > height) {
        current_min = min(current_min, height);
    }
    if(current_height <= height) {
        result = max(result, current_height - current_min);
        current_min = height;
        current_height = height;
    }
}

int main() {
    int n, l, current_min, result = -1e9;
    cin >> n >> l;
    current_min = l;
    vector<int> heights = {l};
    for(int r = 0; r < n - 1; ++r) {
        int num;
        cin >> num;
        heights.push_back(num);
        handle_height(num, current_min, l, result);
    }

    l = heights[(int)heights.size() -1];
    for(int r = n - 1; r >= 0; --r) {
        handle_height(heights[r], current_min, l, result);
    }

    cout << result;

    return 0;
}