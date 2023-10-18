#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define trav(a, x) for(auto &a : x)
typedef long long ll;
typedef vector<string> vs;
typedef vector<ll> vi;

int main() {
    ll guests;
    cin >> guests;
    
    map<ll, vi> people;
    ll person;
    rep(i, 0, guests) {
        cin >> person;
        people[person].push_back(i);
        
    }
    
    ll ans = guests;
    for(auto i : people) {
        for(ll j = 1; j < i.second.size(); j++) {
            ans = min(ans, ll(i.second[j] - i.second[j-1]));
        }
    }

    cout << ans << endl;
    return 0;    
}