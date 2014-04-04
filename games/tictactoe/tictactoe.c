#include <stdio.h>
#include <stdlib.h>

int board[9];

void initBoard()
{
	int i;
	for (i=0; i<9; i++) board[i] = 0;
}
int invalidMove(int x, int val)
{
	if ( (x<1) || (x>9) || (board[x-1] != 0) ) return 1;
	else {
		board[x-1] = val;
		return 0;
	}
}

void printBoard()
{
	int i;
	char c;
	printf("\n");
	for (i = 0; i<9; i++) {
		if (board[i] == 0) c = ' ';
		else if (board[i] == 1) c = 'O';
		else if (board[i] == 2) c = 'X';
		printf(" %c ", c);
		if (i == 8) break;
		else if ((i+1)%3 == 0) printf("\n-----------\n");
		else printf("|");
	}
}

int checkH(int x)
{
	int val = board[x];
	int val2, val3;
	int place = x%3;
	if (place == 0) {
		val2 = board[x+1];
		val3 = board[x+2];
	}
	else if (place == 1) {
		return checkH(x-1);
	}
	else if (place == 2) {
		return checkH(x-2);
	}
	if ( (val == val2) && (val == val3)) return val;
	else return 0;
}

int checkV(int x)
{
	int val = board[x];
	int val2, val3;
	int place = x/3;
	if (place == 0) {
		val2 = board[x+3];
		val3 = board[x+6];
	}
	else if (place == 1) {
		return checkV(x-3);
	}
	else if (place == 2) {
		return checkV(x-6);
	}
	if ( (val == val2) && (val == val3)) return val;
	else return 0;
}

int checkD(int x)
{
	int val = board[x];
	int val2, val3;
	int place = 4-x;
	if (place%2 != 0) return 0;
	if (place == 0) {
		val2 = checkD(2);
		val3 = checkD(0);
	}
	else if (place == 2) {
		val2 = board[4];
		val3 = board[6];
	}
	else if (place == 4) {
		val2 = board[4];
		val3 = board[8];
	}
	else if (place == -2) {
		return checkD(2);
	}
	else if (place == -4) {
		return checkD(4);
	}
	if ( (val == val2) && (val == val3)) return val;
	else return 0;
}

int checkBoard()
{
	int ret;
	int i;
	for (i=0; i<9; i++) {
		if (ret = checkH(i)) break;
		if (ret = checkV(i)) break;
		if (ret = checkD(i)) break;
	}
	return ret;
}

int main()
{
	int end=0;
	int turn=0;
	int move=0;
	initBoard();
	printf("Welcome to console Tic Tac Toe\n");
	while(end==0) {
		printBoard();
		printf("\tPlayer %d's turn!\n",turn%2+1);
		printf("Input 1-9: ");
		scanf("%d",&move);
		while (invalidMove(move, turn%2 + 1)) {
			printf("Invalid input, try again: ");
			scanf("%d",&move);
		}
		end = checkBoard();
		turn++;
	}
	printf("\n=====================\n");
	printBoard();
	printf("\tWinner is Player %d!\n",end);
	return 0;
}