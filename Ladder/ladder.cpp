#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define trav(a, x) for(auto &a : x)
typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;

int main() {
    ll a, b;
    cin >> a >> b;
    cout << static_cast<ll>(a / sin(b * M_PI / 180)) + 1 << "\n";
    return 0;
}