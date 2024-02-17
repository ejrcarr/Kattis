#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    while(cin >> n && n) {
        int one = 0, two = 0;
        for(int i = 0; i < n; ++i) {
            string operation;
            int num;
            cin >> operation >> num;
            if(operation == "DROP") {
                two += num;
                cout << "DROP 2 " << num << "\n";
            }
            else {
                if(one == 0 && two) {
                    one = two;
                    two = 0;
                    cout << "MOVE 2->1 " << one << "\n";
                    one -= num;
                    cout << "TAKE 1 " << num << "\n";
                }
                else if(one && two) {
                    if(one < num) {
                        int remaining = num - one;
                        cout << "TAKE 1 " << one << "\n";

                        one = two;
                        two = 0;
                        cout << "MOVE 2->1 " << one << "\n";

                        one -= remaining;
                        cout << "TAKE 1 " << remaining << "\n";
                    }
                    else if(one >= num) {
                        one -= num;
                        cout << "TAKE 1 " << num << "\n";
                    }
                }
                else if(one && two == 0) {
                    one -= num;
                    cout << "TAKE 1 " << num << "\n";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}