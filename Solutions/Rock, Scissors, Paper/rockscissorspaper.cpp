#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> vs;
typedef pair<int, int> pii;

vector<pii> offsets = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

void print(vs civ) {
    for(auto row : civ) {
        cout << row << "\n";
    }
    cout << "\n";
}

bool current_lost(char current, char adjacent) {
    return (current == 'R' && adjacent == 'P') ||
           (current == 'P' && adjacent == 'S') ||
           (current == 'S' && adjacent == 'R');
}

vs solve(const vs &civ, int num_rows, int num_cols) {
    vs next_civ = civ;
    for(int i = 0; i < num_rows; ++i) {
        for(int j = 0; j < num_cols; ++j) {
            char current = civ[i][j];
            for(pii offset : offsets) {
                int x = i + offset.first, y = j + offset.second;
                if((x >= 0) && (x < num_rows) && (y >= 0) && (y < num_cols)) {
                    if (current_lost(current, civ[x][y])) { 
                        next_civ[i][j] = civ[x][y];
                    }
                }
            }
        }
    }
    return next_civ;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        int num_rows, num_cols, num_days;
        cin >> num_rows >> num_cols >> num_days;
        vs civ(num_rows);
        for(string &row : civ) cin >> row;
        while(num_days--) {
            civ = solve(civ, num_rows, num_cols);
        }
        print(civ);
    }
    return 0;
}