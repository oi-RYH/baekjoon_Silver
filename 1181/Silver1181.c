// 1181
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare (const void* first, const void* second) {
    
    char *firstP = (char *)first;
    char *secondP = (char *)second;

    long unsigned int firstLen = strlen(firstP);
    long unsigned int secondLen = strlen(secondP);

    if (firstLen > secondLen) {
        return 1;
    } else if (firstLen < secondLen) {
        return -1;
    } else {
        return strcmp(firstP, secondP);
    }
}

int main () {

    char p[200000][51] = {0, };
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", p[i]);
    }

    qsort(p, n, sizeof(p[0]), compare);
    
    for (int i = 0; i < n; i++) {
        if ((strcmp(p[i], p[i + 1]) != 0 || i == n - 1)) {
            printf("%s\n", p[i]);
        }
    }

    return 0;
}