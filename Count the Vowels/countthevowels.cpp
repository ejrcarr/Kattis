#include <iostream>
#include <string>

using namespace std;

int main() {
    char a[80];
    cin.getline(a, 80);

    const string VOWELS = "aeiouAEIOU";
    int total = 0;
    for (int i = 0; a[i] != '\0'; ++i) {
        if (VOWELS.find(a[i]) != string::npos) {
            total++;
        }
    }
    cout << total;
    return 0;
}