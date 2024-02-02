#include <iostream>
#include <cmath>

int turn_dial_clockwise_two_turns() {
    return 2 * 360;
}

int stop_at_first_number(int starting_pos, int first_num) {
    int distance = (starting_pos - first_num + 40) % 40;
    return distance * 9; 
}

int turn_dial_counter_clockwise() {
    return 360;
}

int continue_counter_clockwise_until_second_num(int first_num, int second_num) {
    int distance = (second_num - first_num + 40) % 40;
    return distance * 9; 
}

int turn_clockwise_until_third_num(int second_num, int third_num) {
    int distance = (second_num - third_num + 40) % 40;
    return distance * 9;
}

int main() {
    int a, b, c, d;
    while (scanf("%d %d %d %d", &a, &b, &c, &d) == 4 && (a || b || c || d)) {
        int total_degrees = turn_dial_clockwise_two_turns() +
                            stop_at_first_number(a, b) +
                            turn_dial_counter_clockwise() +
                            continue_counter_clockwise_until_second_num(b, c) +
                            turn_clockwise_until_third_num(c, d);
        printf("%d\n", total_degrees);
    }
    return 0;
}
