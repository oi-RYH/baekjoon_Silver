// 1181
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    char **p = NULL;
    int n;

    scanf("%d", &n);

    p = (char **)malloc(sizeof(char *) * n);

    for (int i = 0; i < n; i++) {
        p[i] = (char *)malloc(sizeof(char) * 50);
        scanf("%s", p[i]);
    }

    unsigned long min;
    char temp;
    for (int i = 0; i < n; i++) {
        min = strlen(p[i]);
        for (int j = i; j < n; j++) {
            if (min > strlen(p[j])) {
                int k = 0;
                while (p[i][k]) {
                    temp = p[i][k];
                    p[i][k] = p[j][k];
                    p[j][k] = temp;
                    k++;
                    min = strlen(p[j]);
                }
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", p[i]);
    }

    return 0;
}