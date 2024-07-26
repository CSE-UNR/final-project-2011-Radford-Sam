//code for a one time play of batship 
#include<stdio.h>
#include<stdbool.h>

#define SIZE 10
#define FILETXT "easy.txt"

int loadGame(FILE *fpin, char board[][SIZE]);
void clear(char board[][SIZE]);
void display(char board[][SIZE]);
bool check(char ship[][SIZE], char guess[][SIZE]);
int gamePlay(char guess[][SIZE], char spot[][SIZE]);

int main(){

char guess[SIZE][SIZE];
char spot[SIZE][SIZE];
char playAgain;
int userGuess;
int numSpot;

FILE *fp;

	fp=fopen(FILETXT, "r");
		if(fp == NULL){
			printf("Wont open, try again\n");
			return 0;
			}
	numSpot= loadGame(fp, spot);

	fclose(fp);
	
		do{
		clear(guess);
		userGuess = gamePlay(guess, spot );
		display(guess);
		
		printf("Congratulation!!!!\nIt took %d turns for you to hit %d", userGuess, numSpot);
		printf("Your score is %d!\n",100- userGuess + numSpot);
		
		printf("play again?(Y/N)");
		scanf(" %c", &playAgain);
	
	
	}while(playAgain == 'Y' || playAgain == 'y');



return 0;
}

int loadGame(FILE *fpin, char board[][SIZE]){

	char clear;
	int spots = 0;
	
		for(int row; row<SIZE; row++){
			for(int col; col<SIZE; col++){
				fscanf(fpin, " %c", &board[row][col]);
					if(board[row][col] == 'S'){
						spots++;
					}
				}
		fscanf(fpin," %c", &clear);	
			}
return spots;
}

void clear(char board[][SIZE]){
	for(int row; row<SIZE; row++){
		for(int col; col<SIZE; col++){
			board[row][col]=' ';
		}
	}

}

void display(char board[][SIZE]){
	printf(" A B C D E F G H I\n");
		for(int row = 0; row < SIZE; row++){
			if(row == SIZE -1){
				printf("%d", row+1);
			}else{
				printf("%d", row+1);
			}
			for(int col = 0; col < SIZE; col++){
				printf(" %c", board[row][col]);
			}
			printf("\n");
		}
}

bool check(char ship[][SIZE], char guess[][SIZE]){
	for(int row = 0; row < SIZE; row++){
		for(int col = 0; col <SIZE; col++){
			if(ship[row][col] == 'S' && guess[row][col] != 'X'){
				return false;
			}
		}
	}
	return true;
	
}

int gamePlay(char guess[][SIZE], char spot[][SIZE]){
	int gRow, gCol;
	int numGuess = 0;
	char letGuess;
	
	do{
		display(guess);
			
		printf("Fire away!\n (Enter a square in the grid like A1) ");
		scanf("%c%d", &letGuess, &gRow);
		
		gRow--;
		gCol=letGuess-'A';
		
		if(spot[gRow][gCol] == 'S'){
			guess[gRow][gCol] = 'X';
		}else{
			guess[gRow][gCol] = 'O';
		}
	
		numGuess++;
	
	}while(check(spot,guess));
	
	return numGuess;

}
