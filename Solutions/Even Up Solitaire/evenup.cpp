#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    stack<int> cards;
    while(n--) {
        int card;
        cin >> card;
        if(!cards.empty() && !((cards.top() + card) % 2)) {
            cards.pop();
            continue;
        }
        cards.push(card);
    }

    cout << cards.size();
    return 0;
}