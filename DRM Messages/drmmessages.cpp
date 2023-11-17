#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<char, int> get_alphabet_map() {
    std::unordered_map<char, int> alphabet;
    for(int i = 'A'; i < 'A' + 26; ++i) {
        alphabet[(char)i] = i - 65;
    }
    return alphabet;
}

std::unordered_map<int, char> get_reverse_map(std::unordered_map<char, int> alpha) {
    std::unordered_map<int, char> ahpla;
    for(auto& i : alpha) {
        ahpla[i.second] = i.first;
    }
    return ahpla;
}

std::string rotate_string(std::unordered_map<char, int> alpha, std::string original) {
    std::unordered_map<int, char> reverse = get_reverse_map(alpha);
    int total = 0;
    for(char& letter : original) {
        total += alpha.at(letter);
    }
    std::string builder{};
    for(char& letter : original) {
        builder += reverse.at((alpha.at(letter) + total) % 26);
    }
    return builder;
}

std::string merge(std::unordered_map<char, int> alpha, std::string first, std::string second) {
    std::unordered_map<int, char> reverse = get_reverse_map(alpha);
    std::string builder{};
    for(int i = 0; i < (int)first.length(); ++i) {
        builder += reverse.at((alpha.at(first[i]) + alpha.at(second[i])) % 26);
    }
    return builder;
}

int main() {
    std::string input;
    std::cin >> input;

    std::string first_half = input.substr(0, input.length() / 2);
    std::string second_half = input.substr(input.length() / 2);

    std::unordered_map<char, int> alpha = get_alphabet_map();
    std::cout << merge(alpha, rotate_string(alpha, first_half), rotate_string(alpha, second_half));

    return 0;
}