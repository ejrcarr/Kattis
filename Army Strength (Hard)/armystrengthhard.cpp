#include <iostream>

int main() {
    int rounds;
    scanf("%d", &rounds);

    for(int i = 0; i < rounds; ++i) {
        int god, god_max = 0, mecha, mecha_max = 0;
        scanf("%d %d", &god, &mecha);
        for (int j = 0; j < god; ++j) {
            int num;
            scanf("%d", &num);
            if (num > god_max) {
                god_max = num;
            }
        }
        for (int j = 0; j < mecha; ++j) {
            int num;
            scanf("%d", &num);
            if (num > mecha_max) {
                mecha_max = num;
            }
        }
        printf("%s\n", ((god_max >= mecha_max) ? "Godzilla" : "MechaGodzilla"));
    }
   
    return 0;
}