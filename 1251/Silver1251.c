// 1251
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {

    char text[51];
    scanf("%s", text);

    char result[51];
    memset(result, 'z', 51);
    char temp[51] = {0, };

    int len = strlen(text);
    for (int i = 1; i < len - 1; i++) {
        for (int j = i + 1; j < len ; j++) {
            int k;
            for (k = 0; k < i; k++) {
                temp[k] = text[i - 1 - k];
            }
            for (k = i; k < j; k++) {
                temp[k] = text[j - 1 - (k - i)];
            }
            for (k = j; k < len; k++) {
                temp[k] = text[len - 1 - (k - j)];
            }
            temp[k] = '\0';
            if (strcmp(temp, result) < 0) {
                strcpy(result, temp);
            }
        }
    }

    printf("%s", result);


    return 0;
}