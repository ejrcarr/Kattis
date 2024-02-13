#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

int count(unordered_map<int, vpii>& map, vi& distance, vi& path, int vertex){
    if( path[vertex] != -1) return path[vertex];
    int ways = 0;
    for(pii& item : map[vertex]) {
        int neighbor = item.second;
        if( distance[neighbor] > distance[vertex] ) {
            ways += count(map, distance, path, neighbor);
        }
    }
    path[vertex] = ways;
    return ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int intersections, paths;
    while(cin >> intersections && intersections != 0 && cin >> paths) {
        unordered_map<int, vpii> map;
        map.reserve(intersections);
        vi distance(intersections + 1, 1e9), path(intersections + 1, -1);
        distance[2] = 0;
        path[1] = 1;
        while(paths--) {
            int a, b, weight;
            cin >> a >> b >> weight;
            map[a].emplace_back(weight, b);
            map[b].emplace_back(weight, a);
        }

        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.emplace(0, 2);
        int vertex, neighbor, weight, next_weight;
        while(!q.empty()) {
            tie(weight, vertex) = q.top(); q.pop();
            if(distance[vertex] >= weight) {
                for(pii& item : map[vertex]) {
                    tie(next_weight, neighbor) = item;
                    if(distance[neighbor] > distance[vertex] + next_weight) {
                        distance[neighbor] = distance[vertex] + next_weight;
                        q.emplace(distance[neighbor], neighbor);
                    }
                }
            }
        }
        cout << count(map, distance, path, 2) << "\n";
    }

    return 0;
}