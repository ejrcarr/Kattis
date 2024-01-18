#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<vs> vvs;

bool white_compare_pieces(string piece_one, string piece_two) 
{ 
    if((int)piece_one.length() == 3 && (int)piece_two.length() == 3) {
        piece_one.erase(0, 1);
        piece_two.erase(0, 1);
    }
    if(piece_one[1] == piece_two[1]) {
        return piece_one[0] < piece_two[0];
    }

    return piece_one[1] < piece_two[1]; 
} 

bool black_compare_pieces(string piece_one, string piece_two) 
{ 
    if((int)piece_one.length() == 3 && (int)piece_two.length() == 3) {
        piece_one.erase(0, 1);
        piece_two.erase(0, 1);
    }
    if(piece_one[1] == piece_two[1]) {
        return piece_one[0] < piece_two[0];
    }

    return piece_one[1] > piece_two[1]; 
} 

int main() {
    int num_rows = 8;
    string _, row;
    vs white_pieces[6], black_pieces[6];
    unordered_map<char, int> piece_to_index = {{'K', 0}, {'Q',1}, {'R', 2}, {'B', 3}, {'N', 4}, {'P', 5}};
    getline(cin >> ws, _);
    for(int i = num_rows; i > 0; --i) {
        getline(cin >> ws, row);
        getline(cin >> ws, _);
        row = row.substr(1);
        int temp_col = 0;
        while(row.find("|") != string::npos) {
            int index = row.find("|");
            string square = row.substr(0, index);
            row.erase(0, index + 1);
            char piece = toupper(square[1]);
            if(piece == '.' || piece == ':') {
                ++temp_col;
                continue;
            }

            bool is_white = piece == square[1];
            int ord = 'a' + temp_col;
            string column(1, char(ord));
            string row_str = to_string(i);

            string piece_info = (piece != 'P') ? (piece + column + row_str) :  (column + row_str);
            if(is_white) {
                white_pieces[piece_to_index[piece]].push_back(piece_info);
            }
            else {
                black_pieces[piece_to_index[piece]].push_back(piece_info);
            }

            ++temp_col;
        }
    }

    for(vs& pieces : white_pieces) {
        sort(pieces.begin(), pieces.end(), white_compare_pieces);
    }
    for(vs& pieces : black_pieces) {
        sort(pieces.begin(), pieces.end(), black_compare_pieces);
    }

    std::cout << "White: ";

    string pieces_builder;
    for(vs pieces : white_pieces) {
        for(string piece : pieces) {
            pieces_builder += piece + ",";
        }
    }
    if(pieces_builder != "") pieces_builder.erase(pieces_builder.length() - 1, 1);
    std::cout << pieces_builder << "\n";

    std::cout << "Black: ";
    pieces_builder = "";
    for(vs pieces : black_pieces) {
        for(string piece : pieces) {
            pieces_builder += piece + ",";
        }
    }
    if(pieces_builder != "") pieces_builder.erase(pieces_builder.length() - 1, 1);
    std::cout << pieces_builder << "\n";
    return 0;
}