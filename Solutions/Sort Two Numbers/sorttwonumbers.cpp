#include <iostream>
#include <vector> 

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define trav(a, x) for(auto &a : x)
typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;

int main() {
    ll a, b;
    cin >> a >> b;
    if (a > b) {
        cout << b << " " << a;
    }
    else {
        cout << a << " " << b;
    }
    return 0;
}