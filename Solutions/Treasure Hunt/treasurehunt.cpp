#include <iostream>
#include <vector>
#include <string>
#include <set>

int main() {
    int n, m, i = 0, j = 0, count = 0;
    scanf("%d %d", &n, &m);
    std::vector<std::string> treasure_map(n);
    for(std::string& place : treasure_map) {
        std::cin >> place;
    }

    std::set<std::pair<int, int>> found{};
    while(true) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            printf("Out\n");
            break;
        }

        if (!found.insert({i, j}).second) { 
            printf("Lost\n");
            break;
        }

        if (treasure_map[i][j] == 'T') { 
            printf("%d\n", count);
            break;
        }

        switch (treasure_map[i][j]) {
            case 'N':
                i--;
                break;
            case 'S':
                i++;
                break;
            case 'W':
                j--;
                break;
            case 'E':
                j++;
                break;
        }
        count++; 
    }
    return 0;

}