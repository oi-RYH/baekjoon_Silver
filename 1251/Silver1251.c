// 1251
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char text[51];
char result[20825][51];
int cut[2];
int cnt;
int len;

void resultString(char *text, char (*result)[51], int *cut);
void pick(void);
int nCr();

int main () {

    scanf("%s", text);
    len = strlen(text);

    for (int i = 0; i < len - 2; i++) {
        for (int j = i + 1; j < len - 1; j++) {
            cut[0] = i;
            cut[1] = j;
            resultString(text, result, cut);
        }
    }

    pick();

    printf("%s", result[0]);

    return 0;
}
void resultString(char *text, char (*result)[51], int *cut) {

    int strcnt = 0;

    for (int i = 0; i < cut[0] + 1; i++) {
        result[cnt][strcnt] = text[cut[0] - i];
        strcnt++;
    }

    for (int i = 0; i < cut[1] - cut[0]; i++) {
        result[cnt][strcnt] = text[cut[1] - i];
        strcnt++;
    }

    for (int i = 0; i < len - 1 - cut[1]; i++) {   
        result[cnt][strcnt] = text[len - 1 - i];
        strcnt++;
    }

    cnt++;

}

void pick() {
    
    char temp[51] = {0, };
    for (int i = 0; i < nCr() - 1; i++) {
        for (int j = i + 1; j < nCr() - 1; j++) {
            if (strcmp(result[i], result[j]) > 0) {
                strcpy(temp, result[i]);	
			    strcpy(result[i], result[j]);
			    strcpy(result[j], temp);
            }
        }
    }
}

int nCr() {

    int C[20825] = {0, };
    C[2] = 1;
    C[3] = 3;

    for (int i = 3; i < 20825; i++) {
        C[i] = C[i - 1] + i - 1;
    }

    return C[len];
}