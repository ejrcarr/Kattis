#include <iostream>

int main() {
    int current_player, n, MAX_SECONDS = 210, current_seconds = 0; // 3 min 30 seconds
    scanf("%d\n%d\n", &current_player, &n);
    while(n--) {
        int seconds;
        char type;
        scanf("%d %c", &seconds, &type);
        current_seconds += seconds;
        if(current_seconds >= MAX_SECONDS) {
            printf("%d\n", current_player);
            break;
        }
        if(type == 'T') {
            current_player = ((current_player + 1 > 8) ? 1 : current_player + 1);
        }
    }
    return 0;
}

// WWWBBB
// WWWWBB