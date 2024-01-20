#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef vector<string> vs;
typedef pair<int, int> pii;

vs do_connect(vs image) {
    unordered_map<char, pii> symbol_to_position;
    unordered_set<char> found_symbols;
    for(int i = 0; i < (int)image.size(); ++i) {
        for(int j = 0; j < (int)image[i].length(); ++j) {
            if(image[i][j] != '.') {
                symbol_to_position[image[i][j]] = {i, j};
                found_symbols.insert(image[i][j]);
            }
        }
    }

    string order = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < (int)order.length() - 1; ++i) {
        if(found_symbols.find(order[i + 1]) == found_symbols.end()) {
            break;
        }
        pii first_position = symbol_to_position[order[i]];
        pii second_position = symbol_to_position[order[i + 1]];
        int row_index = first_position.first, col_index = first_position.second;

        if(first_position.second == second_position.second) {
            // up
            if(first_position.first < second_position.first) {
                while(row_index + 1 < (int)image.size() && image[row_index + 1][col_index] != order[i + 1]) {
                    char symbol = image[row_index + 1][col_index];
                    ++row_index;
                    if(symbol == '.') {
                        image[row_index][col_index] = '|';
                    }
                    else if (symbol == '-') {
                        image[row_index][col_index] = '+';
                    }
                }
            }
            // down
            else {
                while(row_index - 1 >= 0 && image[row_index - 1][col_index] != order[i + 1]) {
                    char symbol = image[row_index - 1][col_index];
                    --row_index;
                    if(symbol == '.') {
                        image[row_index][col_index] = '|';
                    }
                    else if (symbol == '-') {
                        image[row_index][col_index] = '+';
                    }
                }
            }
        }

        if(first_position.first == second_position.first) {
            // left
            if(first_position.second > second_position.second) {
                while(col_index - 1 >= 0 && image[row_index][col_index - 1] != order[i + 1]) {
                    char symbol = image[row_index][col_index - 1];
                    --col_index;
                    if(symbol == '.') {
                        image[row_index][col_index] = '-';
                    }
                    else if (symbol == '|') {
                        image[row_index][col_index] = '+';
                    }
                }
            }
            // right
            else {
                while(col_index + 1 < (int)image[row_index].length() && image[row_index][col_index + 1] != order[i + 1]) {
                    char symbol = image[row_index][col_index + 1];
                    ++col_index;
                    if(symbol == '.') {
                        image[row_index][col_index] = '-';
                    }
                    else if (symbol == '|') {
                        image[row_index][col_index] = '+';
                    }
                }
            }
        }
    }

    for(string row : image) {
        std::cout << row << "\n";
    }
    std::cout << "\n";

    return image;
}

int main() {
    vs image; 
    string line;
    while (getline(cin, line)) { 
        if(line == "") {
            do_connect(image);
            image.clear(); 
        } else {
            image.push_back(line);
        }
    }
    do_connect(image);

    return 0;
}
