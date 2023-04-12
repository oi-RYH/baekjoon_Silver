#include <stdio.h>

int main () {

    int n;
    scanf("%d", &n);

    int cnt = 1;
    while (n - cnt > 0) {
        n -= cnt;
        cnt++;
    }

    cnt += 2;

    if (cnt % 2) {
        printf("%d/%d", cnt - 1 - n, n);
    } else {
        printf("%d/%d", n, cnt - 1 - n);
    }

    return 0;
}