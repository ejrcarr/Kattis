#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int beats;
        double seconds;
        scanf("%d %lf", &beats, &seconds);
        double BPM = (60.0 * beats) / seconds;
        double difference = 60 / seconds;
        printf("%lf %lf %lf\n", BPM - difference, BPM, BPM + difference);
    }
    return 0;
}