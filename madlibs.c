//Kaito Fukuda &  &
//11/26/24
//A program to simulate madlibs
#include <stdio.h>
#define INPUT_FILE "madlib1.txt"
#define ROW_LENGTH 100
#define COL_LENGTH 100
void scanFile(FILE *fptr, int rows, int columns, char array[][columns]);

int main(){
	FILE *inFp;
	char madlibs[ROW_LENGTH][COL_LENGTH];
	inFp = fopen(INPUT_FILE, "r");
	if(inFp == NULL){
		printf("Can't open file\n");
		return 0;
	}
	scanFile(inFp, ROW_LENGTH, COL_LENGTH, madlibs);
	for(int i=0; i<100; i++){
		printf("%s", madlibs[i]);
	}
	fclose(inFp);
	return 0;
}

void scanFile(FILE *fptr, int rows, int columns, char array[][columns]){
	char letter, firstLetter;
	int columnCounter=0;
	int rowCounter=0;
	do{
		do{
			fscanf(fptr, "%c", &letter);
			array[rowCounter][columnCounter] = letter;
			columnCounter++;
		}while(letter != '\n');
		rowCounter++;
		columnCounter=0;
	}while(array[rowCounter][0] == '\0');
	
}

