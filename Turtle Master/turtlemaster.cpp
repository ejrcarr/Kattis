#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> map;
    for(int i = 0; i < 8; ++i) {
        string row;
        cin >> row;
        map.insert(map.begin(), row);
    }
    string directions;
    cin >> directions;

    pair<int, int> direction_offsets[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    int direction = 0;

    pair<int, int> position = {0, 0};
    for(char &move : directions) {
        if(move == 'R') {
            direction++;
            if(direction >= 4) {
                direction = 0;
            }
        }
        else if (move == 'L') {
            direction--;
            if(direction < 0) {
                direction = 3;
            }
        }
        else if (move == 'F') {
            pair<int, int> offset = direction_offsets[direction];
            pair<int, int> new_pos = {position.first + offset.first, position.second + offset.second};
            bool OUT_OF_BOUNDS = new_pos.first < 0 || new_pos.first >= 8 ||  new_pos.second < 0 || new_pos.second >= 8;
            bool FACING_CASTLE = map[new_pos.second][new_pos.first] == 'C' || map[new_pos.second][new_pos.first] == 'I';
            if(OUT_OF_BOUNDS || FACING_CASTLE) {
                cout << "Bug!";
                return 0;
            }
            map[position.second][position.first] = '.';
            position = new_pos;
        }
        else {
            pair<int, int> offset = direction_offsets[direction];
            pair<int, int> new_pos = {position.first + offset.first, position.second + offset.second};
            bool OUT_OF_BOUNDS = new_pos.first < 0 || new_pos.first >= 8 ||  new_pos.second < 0 || new_pos.second >= 8;
            bool NOT_FACING_ICE = map[new_pos.second][new_pos.first] != 'I';
            if(OUT_OF_BOUNDS || NOT_FACING_ICE) {
                cout << "Bug!";
                return 0;
            }
            map[new_pos.second][new_pos.first] = '.';
        }
    }
    cout << (map[position.second][position.first] == 'D' ? "Diamond!" : "Bug!");
    return 0;
}