#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    double hyp = sqrt(pow(a, 2) + pow(b, 2));
    rep(i, 0, n) {
        int c;
        cin >> c;
        if (c <= hyp) {
            cout << "DA" << endl;
        }
        else {
            cout << "NE" << endl;
        }
    }
}