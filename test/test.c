#include <stdio.h>
unsigned long active[1000000];
int main() {
    unsigned long numCenters, i,j, hold, data_set_id;
    unsigned long var[100][100];
    //for (i = 0; i<1000000; i++) active[i] = 0;
    //for (i = 0; i<1000000; i++) {
        //for (j=0; j<1000000; j++) {
            //var[i][j] = 0;
		//}
    //}
    scanf("%lu", &numCenters);
	printf("numCenters is %lu\n",numCenters);
    for (i=0;i<numCenters;i++){
        scanf("%lu",&hold);
		printf("hold is %lu\n", hold);
        for (j=0; j<hold; j++) {
            scanf("%lu", &data_set_id);
            active[data_set_id] = 1;
            var[i][data_set_id] = 1;
        }
    }
    
    for (i=0;i<numCenters;i++) {
        for (j=0; j<10; j++) {
            if ((active[j]==1) && (var[i][j]==0)) {
                printf("hello");
            }
        }
    }
    printf("done");
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

