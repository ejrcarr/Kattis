#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> map;
    map.push_back("*");
    int x = 0, y = 0;
    int startx = 0, starty = 0;
    string s;

    while(cin >> s) {
        if(s == "down") {
            y++;
            if(y >= map.size()) {
                string temp(map[0].size(), ' ');
                map.push_back(temp);
            }
        }
        if(s == "up") {
            y--;
            if(y < 0) {
                starty++;
                y++;
                string temp(map[0].size(), ' ');
                map.insert(map.begin(), temp);
            }
        }
        if(s == "left") {
            x--;
            if(x < 0) {
                startx++;
                x++;
                for(auto& i : map) {
                    i.insert(i.begin(), ' ');
                }
            }
        }
        if(s == "right") {
            x++;
            if(x >= map[0].size()) {
                for(auto& i : map) {
                    i.push_back(' ');
                }
            }
        }
        map[y][x] = '*';
    }

    map[y][x] = 'E';
    map[starty][startx] = 'S';

    for(auto& i : map) {
        i.insert(i.begin(), '#');
        i.push_back('#');
    }
    string temp(map[0].size(), '#');
    map.insert(map.begin(), temp);
    map.push_back(temp);

    for(auto str : map) {
        cout << str << endl;
    }
}