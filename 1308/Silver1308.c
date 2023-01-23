// 1308
#include <stdio.h>

int main () {

    int YMD[2][3] = {0, };
    int flag[2] = {0, };
    int day[2] = {0, };
    int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int Ymonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%d %d %d", &YMD[0][0], &YMD[0][1], &YMD[0][2]);
    scanf("%d %d %d", &YMD[1][0], &YMD[1][1], &YMD[1][2]);

    for (int i = 0; i < 1; i++) {
        if ((YMD[i][0] % 4 == 0) && (YMD[i][0] % 100 != 0) && (YMD[i][0] % 400 == 0)) {
            flag[i] = 1;
        }
    }

    for (int i = 0; i < 2; i++) {
        if (flag[i]) {
            day[i] = YMD[i][0] * 364 - YMD[i][2];
            for (int j = 0; j < YMD[i][1]; j++) {
                day[i] += Ymonth[j];
            }
        } else {
            day[i] = YMD[i][0] * 365 - YMD[i][2];
            for (int j = 0; j <= YMD[i][1]; j++) {
                day[i] += month[j];
            }
        }
    }

    //242

    if ((day[1] - day[0]) < (364 * 242 + 365 * 758)) {
        printf("D-%d", day[1] - day[0]);
    } else {
        printf("gg");
    }

    return 0;
}