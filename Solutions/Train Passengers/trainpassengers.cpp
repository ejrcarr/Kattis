#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Stop {
    ll left;
    ll entered;
    ll stayed;
};

typedef vector<Stop> vS;

int main() {
    long long capacity;
    int num_stations;
    cin >> capacity >> num_stations;

    vS stops;
    while(num_stations--) {
        Stop stop;
        cin >> stop.left >> stop.entered >> stop.stayed;
        stops.push_back(stop);
    }

    bool impossible = false;
    int active_passengers = 0;
    for(Stop stop : stops) {
        if(active_passengers < stop.left) {
            impossible = true;
            break;
        }
        active_passengers -= stop.left;
        if(active_passengers + stop.entered > capacity) {
            impossible = true;
            break;
        }
        active_passengers += stop.entered;
        if(stop.stayed && active_passengers != capacity) {
            impossible = true;
            break;
        }
    }

    Stop last_stop = *(--stops.end());
    if(active_passengers || last_stop.entered != 0 || last_stop.stayed != 0) {
        impossible = true;
    }

    cout << (impossible ? "impossible" : "possible");

    return 0;
}