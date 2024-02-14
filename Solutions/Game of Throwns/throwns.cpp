#include <iostream>
#include <string>
#include <stack>

using namespace std;

void handle_change(int num_students, int places, int& start) {
    places %= num_students;
    if(places < 0) {
        places += num_students;
    }
    start = (start + places) % num_students; 
}

int main() {
    int num_students, n, start = 0;
    stack<int> instructions;
    cin >> num_students >> n;
    for(int i = 0; i < n; ++i) {
        string command;
        int num_positions;
        cin >> command;
        if(command == "undo") {
            cin >> num_positions;
            for(int j = 0; j < num_positions; ++j) {
                if(instructions.empty()) continue;
                int instruction = instructions.top(); instructions.pop();
                instruction *= -1;
                handle_change(num_students, instruction, start);
            }
        }
        else {
            int places;
            places = stoi(command);
            handle_change(num_students, places, start);
            instructions.push(places);
        }
    }
    cout << start;
    return 0;
}