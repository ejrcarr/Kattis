#include <iostream>

int main() {
    int mosquitoes, pupae, larvae, eggs, larvae_sr, pupae_sr, n, temp;
    while(scanf("%d %d %d %d %d %d %d", &mosquitoes, &pupae, &larvae, &eggs, &larvae_sr, &pupae_sr, &n) == 7) {
       for(int i = 0; i < n; ++i){
            temp = pupae;
            pupae = larvae / larvae_sr;
            larvae = mosquitoes * eggs;
            mosquitoes = temp / pupae_sr;
        }
        printf("%d\n", mosquitoes);
    }
    return 0;
}