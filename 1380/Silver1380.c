#include <stdio.h>
#include <string.h>

int main () {

    int student_num;
    char firstName[101][61] = {""};
    char lastName[101][61] = {""};
    int check_return = 0;
    char check_alpha;
    int num_check[101] = {0};


    int scen = 0;
    while (1) {
        scanf("%d", &student_num);
        if (student_num == 0) {
            break;
        } else {
            for (int i = 0; i < student_num; i++) { // 학생 수 만큼 이름 입력받기
                scanf("%s %s", firstName[i], lastName[i]);
            }
            for (int i = 0; i < student_num * 2 - 1; i++) { // 돌려받은 학생 체크
                scanf("%d %c", &check_return, &check_alpha);
                num_check[check_return - 1]++;
            }
            for (int i = 0; i < student_num; i++) { // 프린트
                if (num_check[i] == 1) {
                    printf("%d %s %s\n", scen + 1, firstName[i], lastName[i]);
                }
                num_check[i] = 0;
            }
        }
        
        check_return = 0;
        scen++;
    }

    return 0;
}