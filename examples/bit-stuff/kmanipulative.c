#include <stdio.h>

int main() {
    int i, first, prev=0, val, min=0, num, answer=0;
    scanf("%d",&num);
    for (i=0; i<num; i++){
        scanf("%d", &val);
        if (i==0) {
            first=val;
            min=val;
        }
        else {
			printf("prev^val is %d, min before is %d\n", prev^val, min);
            if ((prev^val) < min) min = prev^val;
			printf("prev is %d, val is %d, min is %d\n",prev,val,min);
        }
        prev = val;
    }
    if ((prev^first) < min) min = prev^first;
    printf("min is %d\n",min);
    while (min>0) {
        min>>=1;
        answer++;
    }
    printf("%d\n",answer-1);
}
