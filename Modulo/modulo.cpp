#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    bool found[42] = {};
    rep(i, 0, 10)
    {
        int a;
        cin >> a;
        found[a % 42] = true;
    }

    int count = 0;
    trav(item, found)
    {
        if (item)
        {
            count += 1;
        }
    }
    cout << count;
}