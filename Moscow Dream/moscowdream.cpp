#include <iostream>

int main() {
    int a, b, c, n; 
    scanf("%d %d %d %d", &a, &b, &c, &n);
    printf(((a >= 1) && (b >= 1) && (c >= 1) && (a + b + c >= n) && (n >= 3)) ? "YES" : "NO");
    return 0;
}