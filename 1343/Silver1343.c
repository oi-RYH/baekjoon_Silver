#include <stdio.h>
#include <string.h>

int main () {

    char board[51] = {0, };
    char boardCopy[51] = {0, };
    int len = 0;
    int cnt;
    int Xnum[25] = {0, };
    char *token = NULL;

    scanf("%s", board);
    strcpy(boardCopy, board);
    token = strtok(boardCopy, ".");

    for (int i = 0; token != NULL; i++) {
        Xnum[i] = strlen(token);
        token = strtok(NULL, ".");
        len += Xnum[i];
        cnt = i;
        if (Xnum[i] % 2) {
            printf("-1");
            return 0;
        }
    }

    for (int i = 0; i < strlen(board); i++) {
        if (((board[i + 2] == '.') || (board[i + 2] == NULL)) && (board[i] != '.')) {
            printf("BB");
            i += 1;
        } else if (board[i] == '.') {
            printf(".");
        } else if ((board[i] == 'X') && (board[i + 1] == 'X') && (board[i + 2] == 'X') && (board[i + 3] == 'X')) {
            printf("AAAA");
            i += 3;
        } else {
            break;
        }
    }
    

    return 0;
}