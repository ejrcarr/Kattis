#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <map>

int operate(int first, int second, char operate) {
    switch(operate) {
        case '*':
            return first * second;
        case '/':
            return first / second;
        case '+':
            return first + second;
        case '-':
            return first - second;
    }
    return -1;
}

std::unordered_set<std::string> found;

void find_fours(std::string fours) {
    if (fours.size() >= 13) {
        found.insert(fours);
        return;
    }
    find_fours(fours + " * 4");
    find_fours(fours + " / 4");
    find_fours(fours + " + 4");
    find_fours(fours + " - 4");
}

std::string solve_operation_in_four(std::string four, char op) {
    int pos = four.find(" " + std::string(1, op) + " ");

    int left_pos = pos, right_pos = pos + 2;
    while (left_pos > 0 && four[left_pos - 1] != ' ') {
        left_pos--;
    }
    while (right_pos < four.size() && four[right_pos + 1] != ' ') {
        right_pos++;
    }

    std::string sub = four.substr(left_pos, right_pos - left_pos);
    int left = stoi(four.substr(left_pos, pos - left_pos));
    int right = stoi(four.substr(pos + 2, pos - right_pos));
    four.replace(left_pos, right_pos - left_pos + 1, std::to_string(operate(left, right, op)));

    return four;
}

int evaluate(std::string four) {  
    bool OPERATION_FOUND = true;

    while (OPERATION_FOUND) {
        bool MULTIPLICATION_FOUND = four.find(" * ") != std::string::npos;
        bool DIVISION_FOUND = four.find(" / ") != std::string::npos;
        bool ADDITION_FOUND = four.find(" + ") != std::string::npos;
        bool SUBTRACTION_FOUND = four.find(" - ") != std::string::npos;

        bool MULTIPLICATION_COMES_FIRST = (MULTIPLICATION_FOUND && DIVISION_FOUND) && (four.find(" * ") < four.find(" / "));
        bool DIVISION_COMES_FIRST = (MULTIPLICATION_FOUND && DIVISION_FOUND) && (four.find(" * ") > four.find(" / "));

        bool ADDITION_COMES_FIRST = (ADDITION_FOUND && SUBTRACTION_FOUND) && (four.find(" + ") < four.find(" - "));
        bool SUBTRACTION_COMES_FIRST = (ADDITION_FOUND && SUBTRACTION_FOUND) && (four.find(" + ") > four.find(" - "));
        while ((MULTIPLICATION_FOUND && !DIVISION_FOUND) || (MULTIPLICATION_COMES_FIRST)) {
            four = solve_operation_in_four(four, '*');

            MULTIPLICATION_FOUND = four.find(" * ") != std::string::npos;
            DIVISION_FOUND = four.find(" / ") != std::string::npos;
            MULTIPLICATION_COMES_FIRST = (MULTIPLICATION_FOUND && DIVISION_FOUND) && (four.find(" * ") < four.find(" / "));
        }
        while ((DIVISION_FOUND && !MULTIPLICATION_FOUND) || DIVISION_COMES_FIRST) {
            four = solve_operation_in_four(four, '/');

            MULTIPLICATION_FOUND = four.find(" * ") != std::string::npos;
            DIVISION_FOUND = four.find(" / ") != std::string::npos;
            DIVISION_COMES_FIRST = (MULTIPLICATION_FOUND && DIVISION_FOUND) && (four.find(" * ") > four.find(" / "));
        }
        if (!(MULTIPLICATION_FOUND || DIVISION_FOUND)) {
            while ((ADDITION_FOUND && !SUBTRACTION_FOUND) || ADDITION_COMES_FIRST) {
                four = solve_operation_in_four(four, '+');

                ADDITION_FOUND = four.find(" + ") != std::string::npos;
                SUBTRACTION_FOUND = four.find(" - ") != std::string::npos;
                ADDITION_COMES_FIRST = (ADDITION_FOUND && SUBTRACTION_FOUND) && (four.find(" + ") < four.find(" - "));
            }
            while ((SUBTRACTION_FOUND && !ADDITION_FOUND) || SUBTRACTION_COMES_FIRST) {
                four = solve_operation_in_four(four, '-');

                ADDITION_FOUND = four.find(" + ") != std::string::npos;
                SUBTRACTION_FOUND = four.find(" - ") != std::string::npos;
                SUBTRACTION_COMES_FIRST = (ADDITION_FOUND && SUBTRACTION_FOUND) && (four.find(" + ") > four.find(" - "));
            }
        }
        OPERATION_FOUND = MULTIPLICATION_FOUND || DIVISION_FOUND || ADDITION_FOUND || SUBTRACTION_FOUND;
    }
    return stoi(four);
}

std::map<int, std::string> fours;

int main() {
    find_fours("4");
    for(auto& four : found) {
        int evalation = evaluate(four);
        fours[evalation] = four;
    }

    int n;
    std::cin >> n;

    for(int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        if(fours.find(num) != fours.end()) {
            std::cout << fours.at(num) << " = " << num << '\n';
        }
        else {
            std::cout << "no solution\n";
        }
    }

    return 0;
}