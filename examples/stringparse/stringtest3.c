#include <stdio.h>

void solve(char *st)
{
    int i, ans=0, length = 0;
    char tmp1, tmp2;
    while(st[length]!='\0') length++;
    length--;
    for (i=0; i<length/2; i++) {
        tmp1 = st[i];
        tmp2 = st[length-i];
		printf("tmp1 = %c, tmp2 = %c, tmp2-tmp1 = %d\n", tmp1, tmp2, tmp2-tmp1);
        if (tmp1>tmp2) ans += (tmp1-tmp2);
        else ans += (tmp2-tmp1);
    }
    printf("%d\n",ans);
}

int main()
{
    int i, tests;
    char str[10][10*10*10*10];
    scanf("%d",&tests);
    for (i=0; i<tests; i++){
        scanf("%s", str[i]);
    }

    for (i=0; i<tests; i++) {
        solve(str[i]);
    }
    return 0;
}