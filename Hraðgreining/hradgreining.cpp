#include <string>
#include <iostream>
#include <map>

using namespace std;

int main() {
    string a;
    cin >> a;
    cout << (a.find("COV") != string::npos ?  "Veikur!" : "Ekki veikur!" );
    return 0;
}