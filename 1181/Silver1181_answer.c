#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b) { 
       //qsort 안에 함수
	char *w1 = (char*)a;
	char *w2 = (char*)b;

	long unsigned int n1 = strlen(w1);
	long unsigned int n2 = strlen(w2);
    
	if (n1 < n2) {
        return - 1;	//길이 비교
    } else if (n1 > n2) {
        return 1;
    } else {		//길이가 같으면 사전식 정렬
		return strcmp(w1, w2);
	}
}

char arr[20000][51];
int n;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}

	qsort(arr, n, sizeof(arr[0]), compare);

	for (int i = 0; i < n; i++) {
		if (strcmp(arr[i], arr[i + 1]) != 0 || i == n - 1) {	//문자가 다를 경우에만 출력
			printf("%s\n", arr[i]);
		}
	}

	return 0;
}