#include <iostream>
#include <map>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;

// {winner, loser}
pii get_results(pis first_throw, pis second_throw) {
    string one = first_throw.second, two = second_throw.second;
    if(one == two) return {-1, -1};

    bool two_wins = (one == "rock" && two == "paper") ||
        (one == "paper" && two == "scissors") ||
        (one == "scissors" && two == "rock");

    if(two_wins) {
        return {second_throw.first, first_throw.first};
    }
    else {
        return {first_throw.first, second_throw.first};
    }
}

int main() {
    int num_players, num_games;
    cout.precision(3);
    while(cin >> num_players && num_players != 0 && cin >> num_games) {
        map<int, pii> players;
        int total_games = (num_games * num_players) * ((num_players - 1) / 2.0);
        while(total_games--) {
            int player_one, player_two;
            string throw_one, throw_two;
            cin >> player_one >> throw_one >> player_two >> throw_two;
            pii results = get_results({player_one, throw_one}, {player_two, throw_two});
            if(results.first == -1) continue;
            if(players.count(results.first) == 0) players[results.first] = {0, 0}; 
            if(players.count(results.second) == 0) players[results.second] = {0, 0}; 
            players[results.first].first += 1;
            players[results.second].second += 1;
        }
        for(int i = 1; i <= num_players; ++i) {
            if(players.count(i) == 0) {
                cout << "-\n";
                continue;
            }
            pii player_results = players[i];
            float w = player_results.first, l = player_results.second;
            if(w + l == 0) cout << "0.000\n";
            printf("%.3f\n", (w/(w + l)));
        }
        cout << "\n";
    }
    return 0;
}