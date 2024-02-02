#include <iostream>

int main() {
    int participants, budget, num_hotels, weeks, minimum = 1e9;
    scanf("%d %d %d %d", &participants, &budget, &num_hotels, &weeks);
    while(num_hotels--) {
        int cost_per_person;
        scanf("%d", &cost_per_person);
        for(int i = 0; i < weeks; ++i) {
            int available_beds;
            scanf("%d", &available_beds);
            int cost = cost_per_person * participants;
            if(available_beds < participants || cost > budget) continue;
            minimum = std::min(minimum, cost);
        }
    }
    if(minimum == 1e9) printf("stay home\n");
    else printf("%d", minimum);
    return 0;
}