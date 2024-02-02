#include <iostream>
#include <vector>

int main( ){
    int min, max, x, xmin = 10001, xmax = 0, rem;
    scanf("%d %d %d", &min, &max, &x);

    for (int i = min; i <= max; ++i) {
        int temp = i, sum = 0;
        std::vector<int> digits;
        while (temp != 0) {
            rem = temp % 10;
            digits.insert(digits.begin(), rem);
            temp /= 10;
        }
        for (auto& digit : digits) {
            sum += digit;
        }
        if (sum == x) {
            if (i < xmin) {
                xmin = i;
            }
            if (i > xmax) {
                xmax = i;
            }
        }
    }
    printf("%d\n%d", xmin, xmax);
    return 0;
}