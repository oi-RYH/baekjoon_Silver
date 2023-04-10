// 1308
#include <stdio.h>

int isLeapYear(int year);

int main() {

    int start[3];
    int finish[3];

    int startSum = 0;
    int finishSum = 0;

    scanf("%d %d %d", &start[0], &start[1], &start[2]);
    scanf("%d %d %d", &finish[0], &finish[1], &finish[2]);



    for (int i = 0; i < start[0]; i++) { // 연도 일수 덧셈
        if (isLeapYear(i)) {
            startSum += 366;
        } else {
            startSum += 365;
        }
    }

    for (int i = 1; i < start[1]; i++) { // 월 일수 덧셈
        if ((i == 4) || (i == 6) || (i == 9) || (i == 11)) {
            startSum += 30;
        } else if (i == 2) {
            if (isLeapYear(start[0])) {
                startSum += 29;
            } else {
                startSum += 28;
            }
        } else {
            startSum += 31;
        }
    }
    
    startSum += start[2]; // 일 덧셈
    


    for (int i = 0; i < finish[0]; i++) { // 연도 일수 덧셈
        if (isLeapYear(i)) {
            finishSum += 366;
        } else {
            finishSum += 365;
        }
    }

    for (int i = 1; i < finish[1]; i ++) { // 월 일수 덧셈
        if ((i == 4) || (i == 6) || (i == 9) || (i == 11)) {
            finishSum += 30;
        } else if (i == 2) {
            if (isLeapYear(finish[0])) {
                finishSum += 29;
            } else {
                finishSum += 28;
            }
        } else {
            finishSum += 31;
        }
    }
    
    finishSum += finish[2]; // 일 덧셈
    

    printf("D-%d", finishSum - startSum);


    return 0;
}

int isLeapYear(int year) { // 윤년이면 1, 아니면 0 리턴 

    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}