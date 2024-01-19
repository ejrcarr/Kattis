#include <iostream>
#include <algorithm>

int main() {
    double o, a, p, orange_ratio, apple_ratio, pineapple_ratio;
    scanf("%lf %lf %lf %lf %lf %lf", &o, &a, &p, &orange_ratio, &apple_ratio, &pineapple_ratio);
    
    double max_orange = o / orange_ratio;
    double max_apple = a / apple_ratio;
    double max_pineapple = p / pineapple_ratio;

    double limit = std::min({max_orange, max_apple, max_pineapple});

    double o_left = o - limit * orange_ratio;
    double a_left = a - limit * apple_ratio;
    double p_left = p - limit * pineapple_ratio;

    printf("%lf %lf %lf", o_left, a_left, p_left);
    return 0; 
}
