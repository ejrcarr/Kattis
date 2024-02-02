#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

bool are_diagonal(pii start, pii end) {
    return abs(start.first - end.first) == abs(start.second - end.second);
}

vector<pii> get_diagonals(pii start) {
    vector<pii> diagonals;
    int x = start.first, y = start.second;
    while(x < 8 && y < 8) {
        diagonals.push_back({x, y});
        ++x;
        ++y;
    }
    x = start.first, y = start.second;
    while(x >= 0 && y >= 0) {
        diagonals.push_back({x, y});
        --x;
        --y;
    }
    x = start.first, y = start.second;
    while(x >= 0 && y < 8) {
        diagonals.push_back({x, y});
        --x;
        ++y;
    }
    x = start.first, y = start.second;
    while(x < 8 && y >= 0) {
        diagonals.push_back({x, y});
        ++x;
        --y;
    }
    return diagonals;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        char start_col, end_col;
        int start_row, end_row;
        cin >> start_col >> start_row >> end_col >> end_row;
        pii start = {start_col - 'A', start_row - 1};
        pii end = {end_col - 'A', end_row - 1};

        int board[8][8];
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) board[i][j] = 0;
        }

        // if they are on different colors
        bool IMPOSSIBLE = (start.first % 2 == start.second % 2) != (end.first % 2 == end.second % 2);

        if(IMPOSSIBLE) {
            cout << "Impossible\n";
            continue;
        }

        if(start == end) {
            cout << "0 " << start_col << " " << start_row << "\n";
            continue;
        }

        if(are_diagonal(start, end)) {
            cout << "1 " << start_col << " " << start_row << " " << end_col << " " << end_row << "\n";
            continue;
        }

        vector<pii> diagonals = get_diagonals(start);
        for(auto diagonal : diagonals) {
            if(are_diagonal(diagonal, end)) {
                cout << "2 " << start_col << " " << start_row << " " << (char)(diagonal.first + 'A') << " " << diagonal.second + 1 << " " << end_col << " " << end_row << "\n";
                break;
            }
        }

    }
    return 0;
}