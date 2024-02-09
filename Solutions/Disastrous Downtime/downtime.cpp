#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int main() {
    int num_requests, concurrency;
    cin >> num_requests >> concurrency;

    int servers = -1e9;
    deque<int> requests;
    while(num_requests--) {
        int request;
        cin >> request;
        while(!requests.empty() && (requests[0] + 1000) <= request) {
            requests.pop_front();
        }
        requests.push_back(request);
        servers = max(servers, (int)ceil((double)requests.size() / concurrency));
    }
    cout << servers;
    return 0;
}