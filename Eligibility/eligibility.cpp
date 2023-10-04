#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::string name, date, birthdate;
        int courses;
        std::cin >> name >> date >> birthdate >> courses;
        if (stoi(date.substr(0, 4)) >= 2010 ||
            stoi(birthdate.substr(0, 4)) >= 1991) {
                std::cout << name << " eligible\n";
        }
        else if (courses < 41) {
            std::cout << name << " coach petitions\n";
        }
        else {
            std::cout << name << " ineligible\n";
        }
    }
    return 0;
}