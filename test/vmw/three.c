#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseWords(char *sentence) {
	char * token;
	int i;
	char delim[2] = " ";
	char * cpy = malloc(sizeof(char) * strlen(sentence));
	char * cpy2 = malloc(sizeof(char) * strlen(sentence) + 1);
	char * cpy3 = malloc(sizeof(char) * strlen(sentence));
	//cpy = "";
	strcpy(cpy, sentence);
	printf("cpy is %s\n", cpy);
	token = strtok(cpy, " ");
	printf("token is %s\n", token);
	while(token != NULL) {
		printf("token: %s\n", token);
		strcpy(cpy3, token);
		strcat(cpy3, " ");
		strcat(cpy3, cpy2);
		strcpy(cpy2, cpy3);
		token = strtok(NULL, " ");
	}
	printf("cpy2 = %s\n", cpy2);
	for (i=0; i<3; i++){
		sentence[i] = cpy2[i];
	}
	//strcpy(sentence, cpy2);
}

int main() {
	char *str = "hello world good bye";
	printf("%s\n", str);
	reverseWords(str);
	printf("%s\n", str);
}
