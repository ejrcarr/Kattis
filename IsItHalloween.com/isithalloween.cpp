#include <iostream>
#include <string>

int main() {
    std::string date;
    std::getline(std::cin, date);
    printf("%s", (date == "OCT 31" || date == "DEC 25") ? "yup" : "nope");
    return 0;
}