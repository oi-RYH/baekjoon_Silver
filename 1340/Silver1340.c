#include <stdio.h>
#include <string.h>

int isLeapYear(int YYYY);

int main () {

    char month[10] = {0};
    int day = 0;
    int YYYY = 0;
    int HH = 0;
    int MM = 0;

    double sec = 0;

    scanf("%s %d, %d %d:%d", month, &day, &YYYY, &HH, &MM);

    if (month[0] == 'J') {
        if (strlen(month) == 4) {
            if (month[4] == 'e') { // 6월
                sec = 151;
            } else { // 7월
                sec = 181;
            }
        }
    } else if (month[0] == 'F') { // 2월
        sec = 31;
    } else if (month[0] == 'M') {
        if (strlen(month) == 5) { // 3월
            sec = 59;
        } else { // 5월
            sec = 120;
        }
    } else if (month[0] == 'A') {
        if (strlen(month) == 5) { // 4월
            sec = 90;
        } else { // 8월
            sec = 212;
        }
    } else if (month[0] == 'S') { // 9월
        sec = 243;
    } else if (month[0] == 'O') { // 10월
        sec = 273;
    } else if (month[0] == 'N') { // 11월
        sec = 304;
    } else { // 12월
        sec = 334;
    }

    if ((isLeapYear(YYYY)) && !((sec == 31) || (sec == 0))) {
        sec += 1;
    }

    sec += (day - 1);
    sec *= (24 * 60);
    sec += HH * 60 + MM;

    if (isLeapYear(YYYY)) {
        printf("%.15lf", 100 * sec / (366 * 1440));
    } else {
        printf("%.15lf", 100 * sec / (365 * 1440));
    }

    return 0;
}

int isLeapYear(int YYYY) {

    if ((YYYY % 4 == 0) && (YYYY % 100 != 0) || (YYYY % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }

}