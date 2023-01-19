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
    char temp[50] = {0, };
    for (int i = 0; i < n; i++) {
        min = strlen(p[i]);
        for (int j = i; j < n; j++) {
            if (min > strlen(p[j])) {
                min = strlen(p[j]);
                strcpy(temp, p[i]);
                strcpy(p[i], p[j]);
                strcpy(p[j], temp);
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (!strcmp(p[i], p[i + 1])) {
            for (int j = i + 1; j < n - 1; j++) {
                strcpy(p[j], p[j + 1]);
            }
            n--;
            p[n][0] = '\0';
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <  n - 1; j++) {
            if (strlen(p[j]) == strlen(p[j + 1])) {
                for (int k = 0; p[j][k]; k++) {
                    if (p[j][k] > p[j + 1][k]) {
                        strcpy(temp, p[j + 1]);
                        strcpy(p[j + 1], p[j]);
                        strcpy(p[j], temp);
                    }
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", p[i]);
    }

    for (int i = 0; i < n; i++) {
        free(p[i]);
    }
    free(p);

    return 0;
}