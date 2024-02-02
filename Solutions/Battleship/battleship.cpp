#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count_ships(const vector<string>& map) {
    int count = 0;
    for(const string &row : map) {
        for (const char &letter : row) {
            if(letter == '#') {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        int w, h, num_shots;
        cin >> w >> h >> num_shots;
        vector<string> first_map(h), second_map(h);
        for(string &row: first_map) cin >> row;
        for(string &row: second_map) cin >> row;

        vector<pair<int, int>> shots(num_shots);
        for(auto& shot: shots) cin >> shot.first >> shot.second;

        int player_ships[2] = {count_ships(second_map), count_ships(first_map)}; // second to first (false, true) -> (0, 1)
        bool ones_turn = true, already_won = false;

        for(int i = 0; i < num_shots; ++i) {
            int x = shots[i].first, y = shots[i].second;
            vector<string>& current_map = ones_turn ? second_map : first_map;

			if (already_won) break;
			if (current_map[h - y - 1][x] == '#') {
				current_map[h - y - 1][x] = '_';
                player_ships[!ones_turn]--;
				if (player_ships[!ones_turn] == 0) {
					ones_turn = !ones_turn;
					already_won = ones_turn;
				}
			} else {
				ones_turn = !ones_turn;
				if (ones_turn && !(player_ships[0] && player_ships[1])) {
                    already_won = true;
                }
			}
        }

        if(player_ships[1] > 0 && player_ships[0] <= 0) {
            cout << "player one wins\n";
        }
        else if(player_ships[1] <= 0 && player_ships[0] > 0) {
            cout << "player two wins\n";
        }
        else {
            cout << "draw\n";
        }
    }
    return 0;
}
