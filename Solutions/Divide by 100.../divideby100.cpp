#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    string n, m;
    cin >> n >> m;

    m.erase(0, 1);
    while(*(--n.end()) == '0' && m != "") {
        n = n.substr(0, (int)n.size() - 1);
        m = m.substr(0, (int)m.size() - 1);
    }

    ll decimal_places = m.length();
    if(decimal_places > (ll)n.length()) {
        cout << "0.";
        for(int i = 0; i < decimal_places - (ll)n.length(); ++i) {
            cout << "0";
        }
        cout << n;
    }
    else if(decimal_places == (ll)n.length()) {
        cout << "0." << n;
    }
    else {
        ll left = (ll)n.length() - decimal_places;
        cout << n.substr(0, left);
        if(n.substr(left) != "") cout << "." << n.substr(left);
    }
    return 0;
}