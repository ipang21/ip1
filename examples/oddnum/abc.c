#include <stdio.h>
int main() {
	int x, y, z;
	for (x = 0; x<10; x++) {
		for (y=0; y<10; y++) {
			for (z=0; z<10; z++) {
				//printf("x = %d, y=%d, z=%d\n",x,y,z);
				if (x < y && z == 0) //printf("^^^^^\n");
				printf("x = %d, y=%d, z=%d\n",x,y,z);
			}
		}
	}
	return 0;
}
