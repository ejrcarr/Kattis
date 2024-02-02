#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<string> all_boards;

bool is_winner(const vector<string>& board, char player) {
    for(int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Rows
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { // Columns
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

string board_to_string(const vector<string>& board) {
    string board_str;
    for (const auto& row : board) {
        board_str += row;
    }
    return board_str;
}

void generate_valid_boards(vector<string> board, bool is_x_turn) {
    if(is_winner(board, 'X') || is_winner(board, 'O')) {
        return;
    }
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (board[x][y] == '.') {
                board[x][y] = (is_x_turn ? 'X' : 'O');
                string board_str = board_to_string(board);
                if (all_boards.find(board_str) == all_boards.end()) {
                    all_boards.insert(board_str);
                    generate_valid_boards(board, !is_x_turn);
                }
                board[x][y] = '.';
            }
        }
    }
}

int main() {
    vector<string> default_board = {"...", "...", "..."};
    string default_string = board_to_string(default_board);
    all_boards.insert(default_string);
    generate_valid_boards(default_board, true);

    int n;
    cin >> n;
    while(n--) {
        vector<string> board(3);
        for(int i = 2; i >= 0; --i) {
            string line;
            cin >> line;
            board[i] = line;
        }
        string board_str = board_to_string(board);
        if(all_boards.find(board_str) == all_boards.end()) {
            cout << "no\n";
        }
        else {
            cout << "yes\n";
        }
    }
    return 0;
}