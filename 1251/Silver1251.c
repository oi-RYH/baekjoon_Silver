// 1251
#include <stdio.h>
#include <string.h>

char text[55];

int main () {

    scanf("%s", text);

    int min[2] = {0, };
    char temp;

    for (int i = 0; i < 2; i++) {
        for (int j = min[i] + 1; j < strlen(text) - (2 - i); j++) {
            if (text[min[i]] > text[j]) {
                min[i] = j;
                if (text[j] == 'a') {
                    break;
                }
            }
        }
        if (i == 0) {
            min[i + 1] = min[i];
            for (int k = 0; k < (min[i] + 1) / 2; k++) {
                temp = text[k];
                text[k] = text[min[i]];
                text[min[i]] = temp;
            } 
        } else {
            for (int k = 0; k < (min[i] - min[i - 1]) / 2; k++) {
                temp = text[k + min[i - 1] + 1];
                text[k + min[i - 1] + 1] = text[min[i] - k];
                text[min[i] - k] = temp;
            } 
        }
    }

    printf("%s", text);

    return 0;
}