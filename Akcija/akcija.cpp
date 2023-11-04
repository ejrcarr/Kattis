#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define trav(a, x) for(auto &a : x)
typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;

int main() {
    ll n;
    cin >> n;

    vi nums;
    ll temp;
    rep(i, 0, n) {
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    ll remainder = n % 3;
    ll a, total = 0;
    for(int i = n - 1; i > remainder; i -= 3) {
        total += nums[i];
        total += nums[i - 1];
    }

    rep(i, 0, remainder) {
        total += nums[i];
    }
    cout << total << "\n";
    return 0;    
}