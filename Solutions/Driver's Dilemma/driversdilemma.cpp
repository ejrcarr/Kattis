#include <iostream>

int main() {
    double capacity, leak_rate, miles_to_gas_station;
    scanf("%lf %lf %lf", &capacity, &leak_rate, &miles_to_gas_station);
    int highest_speed = -1;
    double MINIMUM_DIFFERENCE = 1e-6;
    for(int i = 0; i < 6; ++i) {
        int speed;
        double mpg;
        scanf("%d %lf", &speed, &mpg);
        double hours = miles_to_gas_station / (double)speed;
        double gals_lost_from_leak = hours * leak_rate;
        double gals_lost_from_car = miles_to_gas_station / mpg;
        double total_lost = gals_lost_from_car + gals_lost_from_leak;

        // 'half a tank'
        if(total_lost + MINIMUM_DIFFERENCE < capacity / 2) {
            highest_speed = std::max(highest_speed, speed);
        }
    }
    if(highest_speed == -1) {
        printf("NO\n");
    }
    else {
        printf("YES %d", highest_speed);
    }
    return 0;
}