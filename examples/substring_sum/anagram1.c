#include <stdio.h>
#include <string.h>

int solve(char *str, int strl) {
    int i, ret=0;
    int map[256];
    for (i=0; i<256; i++) {
        map[i] = 0;
    }
    for (i=0; i<strl/2; i++) {
        map[str[i]]++;
    }
    for (i=strl/2; i<strl; i++) {
        if (map[str[i]]>0) map[str[i]]--;
    }
    for (i=0; i<256; i++) {
        ret+=map[i];
    }
    return ret;
}

int main() {
    int i, tests, length;
    char str[10000];
    scanf("%d", &tests);
    for (i=0; i<tests; i++) {
        scanf("%s",str);
        length = strlen(str);
        if (length & 1 == 1) printf("-1\n");
        else {
            printf("%d\n", solve(str, length));
        }
    }
    return 0;
}
