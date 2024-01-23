#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define trav(a, x) for(auto &a : x)
typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;

int main() {
    ll n;
    cin >> n;
    string a;
    rep(i, 0, n) {
        cin >> a;
        if (i % 2 == 0) {
            cout << a << "\n";
        }
    }
    return 0;
}