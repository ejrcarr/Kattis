#include <iostream>
#include <string>

int main() {
    int capacity, num_events, num_rejections = 0;
    scanf("%d %d", &capacity, &num_events);
    for(int i = 0; i < num_events; ++i) {
        std::string type;
        int num_people;
        std::cin >> type >> num_people;
        if (type == "enter") {
            if (capacity - num_people < 0) {
                num_rejections += 1;
            }
            else {
                capacity -= num_people;
            }
        }
        else {
            capacity += num_people;
        }
    }
    printf("%d", num_rejections);
    return 0;
}