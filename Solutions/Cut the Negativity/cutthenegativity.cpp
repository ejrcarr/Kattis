#include <iostream>
#include <map>
#include <vector>

int main() {
    int n, total = 0;
    std::cin >> n;
    std::map<int, std::vector<std::pair<int, int> > > adj;
    
    for(int i = 1; i < n + 1; ++i) {
        std::vector<std::pair<int, int> > neighbors;
        for(int j = 1; j < n + 1; ++j) {
            int num;
            std::cin >> num;
            if (num != -1) {
                std::pair<int, int> connection = std::make_pair(j, num);
                neighbors.push_back(connection);
                total++;
            }
        }
        adj[i] = neighbors;
    }

    std::cout << total << "\n";
    for (auto entry : adj) {
        for (auto vertex : entry.second) {
            printf("%d %d %d\n", entry.first, vertex.first, vertex.second);
        }
    }

    return 0;
}