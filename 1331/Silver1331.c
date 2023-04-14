#include <stdio.h>
#include <math.h>

int main () {

    int chessBoard[6][6] = {0};
    char road[36][2] = {0};
    int cnt = 0;

    for (int i = 0; i < 36; i++) {
        scanf("%s", road[i]);
        road[i][0] -= 'A';
        road[i][1] -= '1';
    }

    chessBoard[road[0][0]][road[0][1]] = 1;
    for (int i = 1; i < 36; i++) {
        if (chessBoard[road[i][0]][road[i][1]] == 0) {
            chessBoard[road[i][0]][road[i][1]]++;

            if ((pow(road[i][0] - road[i - 1][0], 2) + pow(road[i][1] - road[i - 1][1], 2)) == 5) {
                cnt++;
                continue;
            } else {
                printf("Invalid");
                return 0;
            }

        } else {
            printf("Invalid");
            return 0;
        }
    }

    if ((cnt == 35) && ((pow(road[0][0] - road[35][0], 2) + pow(road[0][1] - road[35][1], 2)) == 5)) {
        printf("Valid");
    } else {
        printf("Invalid");
    }

    return 0;
}