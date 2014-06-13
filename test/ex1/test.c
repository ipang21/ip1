#include <stdio.h>
#include <string.h>

int compareNum(const void *first, const void *second) {
    int x;
	    x = *(int *) first - *(int *) second;
		    return x;
			}

			int compareStr(const void *first, const void *second) {
			    return strcmp(*(const char **)first, *(const char**) second);
				}
int cstring_cmp(const void *a, const void *b) 
{ 
    const char **ia = (const char **)a;
	    const char **ib = (const char **)b;
		printf("comparing! a=%s, b = %s\n",(char*)a, (char*)b);
				return strcmp((char *)a, (char *)b);
				/* strcmp functions works exactly as expected from
					comparison function */ 
					} 

int main() {
	char input[1000];
	char input_save[1000];
	char words[1000][11];
	char *ptr;
	int num[1000];
	int i, numC=0, wordC=0;
	scanf("%[^\n]%*c",input);
	printf("input1 is %s\n",input);
	strcpy(input_save, input);
	ptr = strtok(input," " );
	while (ptr != NULL) {
		printf("got: %s\n",ptr);
		if ((ptr[0] == '-') || ((ptr[0]-'0' <= 9))) {
			num[numC] = atoi(ptr);
			numC++;
		}
		else {
			strcpy(words[wordC], ptr);
			wordC++;
		}
		ptr = strtok(NULL, " ");
	}
    qsort(num, numC, sizeof(int), compareNum);
	    qsort(words, wordC, 11, cstring_cmp);

	for (i=0; i<numC;i++) {
		printf("num got: %d\n",num[i]);
	}
	for (i=0; i<wordC;i++) {
		printf("word got: %s\n",words[i]);
	}
    numC=0;
    wordC=0;
	printf("input_save is %s\n",input_save);
    ptr = strtok(input_save, " ");
    while (ptr != NULL) {
        if (ptr[0] == '-') {
            printf("%d",num[numC]);
            numC++;
        }
        else if ((ptr[0] - '0') <= 9) {
            printf("%d",num[numC]);
            numC++;
        }
        else {
            printf("%s",words[wordC]);
            wordC++;
        }
        printf(" " );
        ptr = strtok(NULL, " ");
    }

	return  0;
}
