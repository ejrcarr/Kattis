#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> food(365, false);
    while(n--) {
        int start, end;
        cin >> start >> end;
        for(int i = start; i <= end; ++i) {
            food[i - 1] = true;
        }
    }
    cout << count(food.begin(), food.end(), true);
    return 0;
}