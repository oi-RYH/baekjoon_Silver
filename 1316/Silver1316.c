#include <stdio.h>
#include <string.h>

int main () {

    char word[101][101] = {0};
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", word[i]);
    }

    int cnt = n;
    int alphaBool[26] = {0};

    for (int i = 0; i < n; i++) {
        alphaBool[word[i][0] - 'a'] = 1;

        for (int j = 1; j < strlen(word[i]); j++) {
            if (word[i][j] == word[i][j - 1]) {
                continue;
            } else if ((word[i][j] != word[i][j - 1]) && (alphaBool[word[i][j] - 'a'] == 1)) {
                cnt--;
                break;
            } else {
                alphaBool[word[i][j] - 'a'] = 1;
            }
        }

        for (int j = 0; j < 26; j++) {
            alphaBool[j] = 0;
        }
    }

    printf("%d", cnt);

    return 0;
}