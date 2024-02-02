#include <vector>
#include <iostream>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define trav(a, x) for(auto &a : x)
typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;

int main() {
    int a, b;
    cin >> a >> b;
    cout << ((a / b) + 2022) << "\n";
    return 0;
}