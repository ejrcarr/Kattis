#include <iostream>
#include <string>

int get_contiguous_problem_amt(std::string old) {
    std::string new_string = "";
    int first = stoi(old.substr(old.find("-") + 1));
    int last = stoi(old.substr(0, old.find("-")));

    return first - last + 1;
}

int count_problems(std::string n) {
    if (n.find("-") == std::string::npos) return 1;
    return get_contiguous_problem_amt(n);
}

int main() {
    std::string n;
    std::cin >> n;

    int total = 0;
    
    while (n.find(";") != std::string::npos) {
        std::string newset = n.substr(0, n.find(";"));
        total += count_problems(newset);
        n.erase(0, n.find(";") + 1);
    }

    total += count_problems(n);

    std::cout << total;
    return 0;
}