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
    int a, b;
    while (true)
    {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        if (a + b == 13)
        {
            cout << "Never speak again." << endl;
        }
        else if (a > b)
        {
            cout << "To the convention." << endl;
        }
        else if (a < b)
        {
            cout << "Left beehind." << endl;
        }
        else
        {
            cout << "Undecided." << endl;
        }
    }
}