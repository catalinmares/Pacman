/*Mares Catalin-Constantin
		Grupa: 312CD      */

#include <stdio.h>

#define MAX 80
#define MIN 1

void show_table(int y, int N, int x, int M, char character)
{
	int i, j;
	for(i = 1; i <= N + 2; i++){
		for(j = 1; j <= M + 2; j++){
			if((i == 1 || i == N + 2) && (j != 1 && j != M +2)){
				printf("*");
			}
			if (j == 1 || j == M + 2){
				printf("*");
			}
			else {
				if(i == y + 1 && j == x + 1){
					printf("%c", character);
				}
				else {
					if (i != 1 && i != N+2){
						printf(" ");
					}
				}
			}
		}
		printf("\n");
	}

}

int main()
{
	int N, M, x, y, P, GAME = 1, k;
	char move, character = 'v';

	do {
		scanf("%d %d %d %d %d", &N, &M, &x, &y, &P);
		(N <= MIN)? (k = 1) : (k = 0);
		(N >= MAX)? (k = 1) : (k = 0);
		(y <= MIN)? (k = 1) : (k = 0);
		(y >= MAX)? (k = 1) : (k = 0);
		(M <= MIN)? (k = 1) : (k = 0);
		(M >= MAX)? (k = 1) : (k = 0);
		(x <= MIN)? (k = 1) : (k = 0);
		(x >= MAX)? (k = 1) : (k = 0);
	} while(k);

	show_table(y, N, x, M, character);

	while(GAME){
		scanf("%c", &move);
		switch(move){
			case 'w':{
				if(y == 1){
					show_table(y, N, x, M, character);
					break;
				}
				else {
					character = '^';
					y--;
					if(y == N && x == M){
						show_table(y, N, x, M, character);
						printf("GAME COMPLETED\n");
						GAME = 0;
						break;
					}
					else {
						show_table(y, N, x, M, character);
						break;
					}
				}
			}
			case 'a':{
				if(x == 1){
					show_table(y, N, x, M, character);
					break;
				}
				else {
					character = '<';
					x--;
					if(y == N && x == M){
						show_table(y, N, x, M, character);
						printf("GAME COMPLETED\n");
						GAME = 0;
						break;
					}
					else {
						show_table(y, N, x, M, character);
						break;
					}
				}
			}
			case 's':{				
				if(y == N){
					show_table(y, N, x, M, character);
					break;
				}
				else {
					character = 'v';
					y++;
					if(y == N && x == M){
						show_table(y, N, x, M, character);
						printf("GAME COMPLETED\n");
						GAME = 0;
						break;
					}
					else {
						show_table(y, N, x, M, character);
						break;
					}
				}
			}
			case 'd':{
				if(x == M){
					show_table(y, N, x, M, character);
					break;
				}
				else {
					character = '>';
					x++;
					if(y == N && x == M){
						show_table(y, N, x, M, character);
						printf("GAME COMPLETED\n");
						GAME = 0;
						break;
					}
					else {
						show_table(y, N, x, M, character);
						break;
					}
				}
			}
			case 'q':{
				GAME = 0;
				break;
			}

		}
	}
	return 0;
}