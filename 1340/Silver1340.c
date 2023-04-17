#include <stdio.h>
#include <string.h>

int nowMonth(char *month);

int main () {

    char month[10] = {0};
    int year, day, hour, min;

    int nowYear = 365;

    scanf("%s %d, %d %d:%d", month, &day, &year, &hour, &min);

    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
        nowYear = 366;
    }

    int monthNum = nowMonth(month);
    double allMin = 0;
    int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (monthNum == 1) {
        allMin += day - 1;
    } else {
        allMin += day - 1;
        for (int i = 0; i < monthNum - 1; i++) {
            allMin += mon[i];
        }
        if ((monthNum > 2) && (nowYear == 366)) {
            allMin += 1;
        }
    }

    allMin *= (24 * 60);
    allMin += (hour * 60) + (min);
    
    printf("%.15lf", allMin / (nowYear * 24 * 60) * 100);

    return 0;
}

int nowMonth(char *month) {
    if (strcmp(month, "January") == 0) {
        return 1;
    } else if (strcmp(month, "February") == 0) {
        return 2;
    } else if (strcmp(month, "March") == 0) {
        return 3;
    } else if (strcmp(month, "April") == 0) {
        return 4;
    } else if (strcmp(month, "May") == 0) {
        return 5;
    } else if (strcmp(month, "June") == 0) {
        return 6;
    } else if (strcmp(month, "July") == 0) {
        return 7;
    } else if (strcmp(month, "August") == 0) {
        return 8;
    } else if (strcmp(month, "September") == 0) {
        return 9;
    } else if (strcmp(month, "October") == 0) {
        return 10;
    } else if (strcmp(month, "November") == 0) {
        return 11;
    } else {
        return 12;
    }
} 