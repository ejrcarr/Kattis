#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>

int main() {
    unsigned long long n;
    int t;
    scanf("%llu %d", &n, &t);

    std::vector<unsigned long long> A(n), temp(3);
    for(unsigned long long& number : A) scanf("%llu", &number);

    switch(t) {
        case 1: {
            printf("7\n");
            break;
        }
        case 2: {
            if(A[0] == A[1]) printf("Equal\n");
            else if (A[0] > A[1]) printf("Bigger\n");
            else printf("Smaller\n");
            break;
        }
        case 3: {
            temp = {A[0], A[1], A[2]};
            std::sort(temp.begin(), temp.end());
            printf("%llu\n", temp[1]);
            break;
        }
        case 4: {
            printf("%llu\n", std::accumulate(A.begin(), A.end(), 0ULL));
            break;
        }
        case 5: {
            unsigned long long result = 0;
            for(unsigned long long& number : A) {
                if(number % 2 == 0) result += number;
            }
            printf("%llu\n", result);
            break;
        }
        case 6: {
            for(unsigned long long number : A) {
                char character = (number % 26) + 'a';
                printf("%c", character);
            }
            printf("\n");
            break;
        }
        case 7: {
            unsigned long long current_index = 0;
            std::unordered_set<unsigned long long> found{};
            while(true) {
                if(found.find(current_index) != found.end()) {
                    printf("Cyclic\n");
                    break;
                }
                if(A[current_index] >= n) {
                    printf("Out\n");
                    break;
                }
                if(A[current_index] == n - 1) {
                    printf("Done\n");
                    break;
                }
                found.insert(current_index);
                current_index = A[current_index];
            }
            break;
        }
    }
    return 0;
}
