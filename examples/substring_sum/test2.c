#include <stdio.h>
#include <string.h>

int main() {
	char str[256];
	int i;
	unsigned int len, tmp, factor=1, ans=0;
	printf("Enter num: ");
	scanf("%s", str);
	for (i=strlen(str)-1;i>=0;i--) {
		ans = ans + (str[i]-'0') * factor * (i+1);
		factor = factor * 10 + 1;
	}
	printf("answer is %d\n",ans);
	return 0;
}
