#include <stdio.h>
#include <stdlib.h>

int answer;

struct node {
	int end;
	struct node *right;
	struct node *up;
};

void crNode(struct node *x, int up)
{
	struct node *me;
	me = malloc(sizeof(struct node));
	me->right = NULL;
	me->up = NULL;
	if (up == 1)
		x->up = me;
	else
		x->right = me;
}

struct node * fdNode(struct node *x, int val)
{
	int i;
	struct node *me;
	me = x;
	for (i=0;i<val;i++)
		me = me->up;
	return me->right;
}

void myprintR(struct node *x)
{
	if (x == NULL) return;
	else{
		printf("\t[%d]",x->end);
		myprintR(x->right);
	}
}

void myprint(struct node *x)
{
	if (x == NULL) return;
	else
	{
		myprintR(x);
		printf("\n");
		myprint(x->up);
	}
}

void solve(struct node *x, int val)
{
	if (x == NULL) return;
	if (x->end == val) 
		answer++;
	else
	{
		solve(x->right, val);
		solve(x->up, val);
	}
}

int main(int argc, char *argv[])
{
	int width;
	int height;
	int i, j;
	struct node *start;
	struct node *traverse;
	struct node *travBk;
	struct node *travLf;
	if (argc != 3)
	{
		printf("Usage:\n\t %s [width] [height]\n",argv[0]);
		return -1;
	}
	else
	{
		width = atoi(argv[1]);
		height = atoi(argv[2]);
	}
	printf("Solving for parameters: width = %d, height = %d\n",width, height);

	start = malloc(sizeof(struct node));
	traverse = start;
	travBk = traverse;
	travLf = traverse;
	for (i = 0; i<width; i++)
	{
		travBk=traverse;
		for (j = 0; j<height; j++)
		{
			traverse->end = (i*height)+j;
			if (i<width-1)
			{
				crNode(traverse, 0);
			}
			else
			{
				traverse->right = NULL;
			}
			if ((i==0) && (j<(height-1)))
			{
				crNode(traverse, 1);
			}
			else if(j==(height-1))
			{
				traverse->up = NULL;
			}
			else
			{
				traverse->up = fdNode(travLf,j+1);
			}
			traverse = traverse->up;
		}
		travLf = travBk;
		traverse = travBk->right;
	}
	answer = 0;
	myprint(start);
	solve(start, (width*height)-1);
	printf("Number of routes = %d\n",answer);
	return 0;
}
