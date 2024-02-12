#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> original, aux;
    for(int i = 0; i < (2 * n); ++i) {
        int sock;
        cin >> sock;
        original.emplace_back(sock);
    }

    int count = 0;
    while(!original.empty()) {
        if(!aux.empty() && aux.front() == original.front()) {
            aux.pop_front();
            original.pop_front();
        }
        else {
            aux.emplace_front(original.front());
            original.pop_front();
        }
        ++count;
    }
    if(!aux.empty()) {
        cout << "impossible";
    }
    else {
        cout << count;
    }
    return 0;
}