#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef unordered_set<int> usi;

int main() {
    int num_movies, num_horrors, similarities;
    cin >> num_movies >> num_horrors >> similarities;

    queue<int> q;
    vi horror_rating(num_movies, 1e9);
    for(int i = 0; i < num_horrors; ++i) {
        int id;
        cin >> id;
        q.push(id);
        horror_rating[id] = 0;
    }

    vector<vi> adjacency_list(num_movies);
    while(similarities--) {
        int a, b;
        cin >> a >> b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }

    while(!q.empty()) {
        int current_id = q.front(); q.pop();
        for(int neighbor : adjacency_list[current_id]) {
            if(horror_rating[neighbor] > horror_rating[current_id] + 1) {
                horror_rating[neighbor] = horror_rating[current_id] + 1;
                q.push(neighbor);
            }
        }
    }

    int current_max = *max_element(horror_rating.begin(), horror_rating.begin() + num_movies);
    for(int i = 0; i < num_movies; ++i) {
        if(horror_rating[i] == current_max) {
            cout << i;
            break;
        }
    }
    return 0;
}