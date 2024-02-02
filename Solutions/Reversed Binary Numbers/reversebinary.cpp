#include <math.h>
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

vi convertToBinary(int num)
{
    int remain;
    vi bin;

    while (num != 0)
    {
        remain = num % 2;
        num /= 2;
        bin.push_back(remain);
    }

    return bin;
}

int main()
{
    int a;
    cin >> a;

    vi binary = convertToBinary(a);
    int sum = 0;
    rep(i, 0, sz(binary))
    {
        sum += binary[i] * pow(2.0, (double)(sz(binary) - 1 - i));
    }
    cout << sum;
}