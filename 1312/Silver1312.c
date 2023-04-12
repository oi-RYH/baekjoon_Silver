#include <stdio.h>

int main () {

    int A, B, n;
    scanf("%d %d %d", &A, &B, &n);

    int mod = A % B;

    for (int i = 0; i < n - 1; i++) {
        mod *= 10;
        mod = mod % B;
    }

    mod *= 10;
    mod = mod / B;

    printf("%d", mod);

    return 0;
}