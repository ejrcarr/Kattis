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
    ll a, b, c;
    cin >> a >> b >> c;
    cout << (a + b == c ? "correct!" : "wrong!");
    return 0;
}