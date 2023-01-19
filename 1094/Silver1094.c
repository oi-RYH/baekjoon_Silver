// 1094
#include <stdio.h>

int main () {

    int num;
    int cnt = 0;
    scanf("%d", &num);

    while (num > 0) {
        if (num & 1) {
            cnt++;
        }
        num = num >> 1;
    }

    printf("%d", cnt);

    return 0;
}