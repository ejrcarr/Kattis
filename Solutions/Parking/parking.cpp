#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int pay[101] = {0};
    for(int i = 0; i < 3; ++i) {
        int start, end;
        cin >> start >> end;
        for(int j = start; j < end; ++j) {
            if(pay[j] == 0) pay[j] = a;
            else if (pay[j] == a) pay[j] = b;
            else pay[j] = c;
        }
    }

    int total = 0;
    for(int minute : pay) {
        if(minute == a) total += minute;
        else if (minute == b) total += minute * 2;
        else total += minute * 3;
    }
    cout << total;
    return 0;
}