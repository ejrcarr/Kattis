#include <iostream>
#include <vector>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& x : a)
typedef long long ll;
typedef vector<int> vi;

int main() {
    ll a, b;
    while (cin >> a >> b) {
         cout << abs(a - b) << "\n";
    }
}