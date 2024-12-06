//Kaito Fukuda &  &
//11/26/24
//A program to simulate madlibs
#include <stdio.h>
#define INPUT_FILE "madlib1.txt"
#define ROW_LENGTH 100
#define COL_LENGTH 100
#define ARRAY_SIZE 50
void scanFile(FILE *fptr, int rows, int columns, char array[][columns]);
void findLetters(int rowLength, int columnLength, char madlibsArr[][columnLength], int size, char letters[], int rowNums[]);
int rowSize(char array[]);

int main(){
	FILE *inFp;
	char madlibs[ROW_LENGTH][COL_LENGTH];
	inFp = fopen(INPUT_FILE, "r");
	if(inFp == NULL){
		printf("Can't open file\n");
		return 0;
	}
	scanFile(inFp, ROW_LENGTH, COL_LENGTH, madlibs);
	findLetters(ROW_LENGTH, COL_LENGTH, madlibs, ARRAY_SIZE, letterArr, rowNumArr);
	for(int i=0; i<50; i++){
		printf("%s", madlibs[i]);
	}
	for(int i=0; i<10; i++){
		printf("%c%d ", letterArr[i], rowNumArr[i]);
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

void findLetters(int rowLength, int columnLength, char madlibsArr[][columnLength], int size, char letters[], int rowNums[]){
	int rowCounter = 0;
	int colCounter = 0;
	while(madlibsArr[rowCounter][0] != '\0'){
		if(rowSize(madlibsArr[rowCounter]) >= 2 && (madlibsArr[rowCounter][0] == 'A' || madlibsArr[rowCounter][0] == 'N' || madlibsArr[rowCounter][0] == 'V')){
		 letters[colCounter] = madlibsArr[rowCounter][0];
		 rowNums[colCounter] = rowCounter;
		 colCounter++;
		}
		rowCounter++;
	}
}

int rowSize(char array[]){
	int counter = 0;
	for(int i=0; array[i] != '\0'; i++){
		counter++;
	}
	return counter;
}
