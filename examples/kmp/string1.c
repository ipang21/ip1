#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *kmp_search(const char *text, const char *pattern)
{
    int *T;
    int i, j;
    const char *result = NULL;
 
    if (pattern[0] == '\0')
        return text;
 
    /* Construct the lookup table */
    T = (int*) malloc((strlen(pattern)+1) * sizeof(int) );
    T[0] = -1;
    for (i=0; pattern[i] != '\0'; i++) {
        T[i+1] = T[i] + 1;
        while (T[i+1] > 0 && pattern[i] != pattern[T[i+1]-1])
            T[i+1] = T[T[i+1]-1] + 1;
    }
 
    /* Perform the search */
    for (i=j=0; text[i] != '\0'; ) {
        if (j < 0 || text[i] == pattern[j]) {
            ++i, ++j;
            if (pattern[j] == '\0') {
                result = text+i-j;
                break;
            }
        }
        else j = T[j];
    }
 
    free(T);
    return result;
}

void searchPat(char *str, char *pat) {
	int i,j;
	for (i=0; str[i]!='\0'; i++) {
		for (j=0; pat[j]!='\0'; j++) {
			if (str[i+j] != pat[j])
				break;
		}
		if (j == strlen(pat))
			printf("Pattern at %d\n",i);
	}
}

int main() {
	char *str1, *pat;
	scanf("%s",str1);
	scanf("%s",pat);
	printf("Got: str1=%s, pat=%s\n",str1,pat);
	//printf("Result: %s\n", kmp_search(str1, pat));
	searchPat(str1, pat);
	return 0;
}