#include <stdio.h>
#include <stdlib.h>

int board[7][7];

void initBoard()
{
	int i,j;
	for (i = 0; i<7; i++) {
		for (j=0; j<7; j++) {
			board[i][j] = 0;
		}
	}
}

int invalidMove(int x, int val)
{
	int i;
	if ( (x<1) || (x>7) || (board[6][x]!=0 )) return -1;
	else {
		for (i=0; i<7; i++) {
			if (board[i][x-1] == 0) {
				board[i][x-1] = val;
				return i;
			}
		}
	}
}

void printBoard()
{
	int i, j;
	char c;
	printf("\n");
	for (i=7-1; i>=0; i--) {
		for (j=0; j<7; j++) {
			if (board[i][j] == 0) c = ' ';
			else if (board[i][j] == 1) c = 'O';
			else if (board[i][j] == 2) c = 'X';
			if (j==0) printf("\t||");
			printf(" %c ",c);
			if (j!=7-1) printf("|");
			else printf("||");
		}
		if (i==0) printf("\n\t===============================\n");
		else printf("\n\t-------------------------------\n");
	}
}

int checkH(int x, int y, int val)
{
	int i;
	int count = 1;
	for (i = x+1; i<7; i++) {
		if (board[y][i] == val) count++;
		else break;
	}
	for (i = x-1; x>=0; i--) {
		if (board[y][i] == val) count++;
		else break;
	}
	if (count >= 4) return 1;
	else return 0;
}

int checkV(int x, int y, int val)
{
	int i;
	int count = 1;
	for (i = y-1; i>=0; i--) {
		if (board[i][x] == val) count++;
		else break;
	}
	if (count >= 4) return 1;
	else return 0;
}

int checkD1(int x, int y, int val)
{
	int i;
	int count = 1;
	for (i=1; x+i<7 && y+i<7; i++) {
		if (board[y+i][x+i] == val) count++;
		else break;
	}
	for (i=1; x-i>=0 && y-i>=0; i++) {
		if (board[y-i][x-i] == val) count++;
		else break;
	}
	if (count >= 4) return 1;
	else return 0;
}

int checkD2(int x, int y, int val)
{
	int i;
	int count = 1;
	for (i=1; x+i<7 && y-i>=0; i++) {
		if (board[y-i][x+i] == val) count++;
		else break;
	}
	for (i=1; x-i>=0 && y+i<7; i++) {
		if (board[y+i][x-i] == val) count++;
		else break;
	}
	if (count >= 4) return 1;
	else return 0;
}

int checkD(int x, int y, int val)
{
	if (checkD1(x,y,val)) return val;
	else if (checkD2(x,y,val)) return val;
	else return 0;
}

int checkBoard(int x, int y, int val)
{
	if (checkH(x-1,y,val)) return val;
	else if (checkV(x-1,y,val)) return val;
	else if (checkD(x-1,y,val)) return val;
	else return 0;
}

int main()
{
	int end = 0;
	int turn=0;
	int move=0;
	int height=0;
	initBoard();
	printf("Welcome to console Connect Four!\n");
	while (end==0) {
		printBoard();
		printf("\t      Player %d's turn!\n",turn%2+1);
		printf("Input 1-7: ");
		scanf("%d",&move);
		while ((height=invalidMove(move, turn%2 + 1)) == -1) {
			printf("Invalid input, try again: ");
			scanf("%d",&move);
		}
		end = checkBoard(move, height, turn%2+1);
		turn++;
	}
	printf("\n===================================================\n");
	printBoard();
	printf("\t     Winner is Player %d!\n",end);
	return 0;
}