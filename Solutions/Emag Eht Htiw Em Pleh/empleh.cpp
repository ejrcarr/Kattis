#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct Piece {
    char piece;
    pii position;
};

vvs build_chessboard() {
    vvs chessboard;
    string black_square = ":::", white_square = "...";
    bool is_white = true;
    for(int i = 0; i < 8; ++i) {
        vs row;
        for(int j = 0; j < 8; ++j) {
            row.push_back(is_white ? white_square : black_square);
            is_white = !is_white;
        }
        chessboard.push_back(row);
        is_white = !is_white;
    }
    return chessboard;
}

Piece get_piece_from_string(string piece_info, bool is_white) {
    Piece piece;
    piece.piece = (is_white ? 'P' : 'p');
    if((int)piece_info.length() == 3) {
        piece.piece = (is_white ? piece_info[0] : tolower(piece_info[0]));
        piece_info.erase(0, 1);
    }
    piece.position = {(int)(piece_info[1] - '0') - 1, piece_info[0] - 'a'};
    // reverse board
    piece.position = {7 - piece.position.first, piece.position.second};
    return piece;
}

vector<Piece> get_pieces(string moves, bool is_white) {
    vector<Piece> pieces;
    int index;
    Piece piece;
    while(moves.find(",") != std::string::npos) {
        index = moves.find(",");
        string sub = moves.substr(0, index);
        piece = get_piece_from_string(sub, is_white);
        pieces.push_back(piece);
        moves.erase(0, index + 1);
    }
    if(moves != "") {
        piece = get_piece_from_string(moves, is_white);
        pieces.push_back(piece);
    }
    return pieces;
}

int main() {
    string white_moves, black_moves;
    getline(cin >> ws, white_moves);
    getline(cin >> ws, black_moves);

    white_moves = white_moves.erase(0, 7);
    black_moves = black_moves.erase(0, 7);

    vvs chessboard = build_chessboard();

    vector<Piece> all_pieces;
    vector<Piece> white_pieces = get_pieces(white_moves, true);
    vector<Piece> black_pieces = get_pieces(black_moves, false);
    all_pieces.insert(all_pieces.end(), white_pieces.begin(), white_pieces.end());
    all_pieces.insert(all_pieces.end(), black_pieces.begin(), black_pieces.end());

    for(Piece piece : all_pieces) {
        chessboard[piece.position.first][piece.position.second][1] = piece.piece;
    }
    
    for(auto row : chessboard) {
        std::cout << "+---+---+---+---+---+---+---+---+\n";
        for(auto col : row) {
            std::cout << "|" << col;
        }
        std::cout << "|\n";
    }
    std::cout << "+---+---+---+---+---+---+---+---+\n";
    return 0;
}