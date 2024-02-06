#include <iostream>

using namespace std;

int main() {
    int start_time, end_time, n;
    cin >> start_time >> end_time >> n;

    int walk_times[n + 1];
    int ride_times[n];
    int arrival_times[n];
    for(auto& walk : walk_times) cin >> walk;
    for(auto& ride : ride_times) cin >> ride;
    for(auto& arrival : arrival_times) cin >> arrival;

    int total = start_time;
    for(int i = 0; i < n; ++i) {
        total += walk_times[i];
        if(total < arrival_times[i]) total += arrival_times[i] - total;
        total += ride_times[i];
    }
    total += walk_times[n];
    
    if (total > end_time) cout << "no";
    else cout << "yes";

    return 0;
}