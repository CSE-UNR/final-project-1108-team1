// Authors: Zeed Almelhem 
// Team1 1108
// 12/3/2024

#include <stdio.h>

#define INPUT_FILE "madlib2.txt"
#define ROW_LENGTH 100
#define COL_LENGTH 100


void readFileToArray(FILE *file, char rows[ROW_LENGTH][COL_LENGTH], int *numRows); // Function to read file into an array and count rows
int stringLength(char str[]); // Return the length of a string
void findSpecificRows(char rows[ROW_LENGTH][COL_LENGTH], int numRows, char resultChars[], int resultRows[], int *resultCount); // Function to find rows starting with 'A', 'N', or 'V' and of length 1
void collectUserInputs(char characters[], int count, char responses[ROW_LENGTH][COL_LENGTH]); // Function to collect user inputs using scanf
void replaceWords(char madlibs_array[ROW_LENGTH][COL_LENGTH], int resultRows[ROW_LENGTH], int resultCount, char user_responses[ROW_LENGTH][COL_LENGTH]); // Replace the A, N & V with the user responses in the madlibs
void display_updated_madlibs(char madlibs_array[ROW_LENGTH][COL_LENGTH], int madlibs_rows_length); // Print the updated madlibs array


int main(){
	FILE *inFp; // File pointer
	char madlibs[ROW_LENGTH][COL_LENGTH]; // 2D-Array to store the madlibs
	int madlibs_rows_length; // The number of rows in the madlibs
	char resultChars[ROW_LENGTH]; // The rows starting with 'A', 'N', or 'V'
	int resultRows[ROW_LENGTH]; // The rows starting with 'A', 'N', or 'V'
	int resultCount; // The number of rows that start with 'A', 'N', or 'V'
	char user_responses[ROW_LENGTH][COL_LENGTH]; // The user responses for 'A', 'N', and 'V'
	
	// Open the file
	inFp = fopen(INPUT_FILE, "r");
	if(inFp == NULL){
		printf("Can't open file\n");
		return 0;
	}
	
	
	// Read file into an array and count rows
	readFileToArray(inFp, madlibs, &madlibs_rows_length);
	
	// Close the file
	fclose(inFp);
	
	// Find rows starting with 'A', 'N', or 'V' and of length 1
	findSpecificRows(madlibs, madlibs_rows_length, resultChars, resultRows, &resultCount);
	
	
	// Collect user inputs
	collectUserInputs(resultChars, resultCount, user_responses);
	
	
	// Replace the A, N & V with the user responses in the madlibs
	replaceWords(madlibs, resultRows, resultCount, user_responses);
	
	
	// Display the updated madlibs array
	display_updated_madlibs(madlibs, madlibs_rows_length);
	
	return 0;
}

void readFileToArray(FILE *file, char array[ROW_LENGTH][COL_LENGTH], int *numRows){
	char letter, firstLetter;
	int columnCounter=0;
	int rowCounter=0;
	do{
		do{
			fscanf(file, "%c", &letter);
			array[rowCounter][columnCounter] = letter;
			columnCounter++;
		}while(letter != '\n');
		rowCounter++;
		columnCounter=0;
	}while(rowSize(array[rowCounter-1]) != 1);
	*numRows = rowCounter;
}

// Function to read file into an array and count rows
//void readFileToArray(FILE *file, char rows[ROW_LENGTH][COL_LENGTH], int *numRows) {
    
//    int count = 0;
//    int colIndex = 0;
//    char ch;

    // Read file character by character
 
 //    while ((ch = fgetc(file)) != EOF && count < ROW_LENGTH){ // Note: We shouldn't use EOF, but this is the only way that it worked for me
 //       if (ch == '\n' || colIndex == COL_LENGTH - 1) {
            // End of line or maximum column limit reached
 //           rows[count][colIndex] = '\0';  // Null-terminate the current row
 //           count++;  // Move to the next row
 //           colIndex = 0;

 //           if (ch == '\n') {
                continue;
//            }
//        }

//        if (count < ROW_LENGTH) {
//            rows[count][colIndex++] = ch;
//        }
//    }

    // Handle the last line if the file doesn't end with a newline
    if (colIndex > 0 && count < ROW_LENGTH) {
        rows[count][colIndex] = '\0';
        count++;
    }

    *numRows = count;  // Store the number of rows
}


// Return the length of a string
int stringLength(char str[]){
	
	// my code:
	int i;
	for(i=0; str[i]!='\0' ; i++){ // Note: We could optimize it using a while loop
		// Count the characters of the string.	
	}
	return i;
}


// Function to find rows starting with 'A', 'N', or 'V' and of length 1
void findSpecificRows(char rows[ROW_LENGTH][COL_LENGTH], int numRows, char resultChars[], int resultRows[], int *resultCount) {
    int count = 0;

    for (int i = 0; i < numRows; i++) {
        // Check if the row starts with 'A', 'N', or 'V' and has a length of 1
        if ((rows[i][0] == 'A' || rows[i][0] == 'N' || rows[i][0] == 'V') && stringLength(rows[i]) == 1) {
            resultChars[count] = rows[i][0];  // Store the character
            resultRows[count] = i;           // Store the row number
            count++;
            // printf("it worked in if %d \n", count);
        }
    }

    *resultCount = count;  // Update the result count
}


// Function to collect user inputs using scanf
void collectUserInputs(char characters[], int count, char responses[ROW_LENGTH][COL_LENGTH]) {
    for (int i = 0; i < count; i++) {
        switch (characters[i]) {
            case 'N':  // Noun
                printf("Please enter a noun: ");
                break;
            case 'A':  // Adjective
                printf("Please enter an adjective: ");
                break;
            case 'V':  // Verb
                printf("Please enter a verb: ");
                break;
            default:   // Invalid character
                printf("Unknown character '%c'. Skipping...\n", characters[i]);
                continue;
        }

        // Read user input using scanf
        scanf("%s", responses[i]);
    }
}


// Replace the A, N & V with the user responses in the madlibs
void replaceWords(char madlibs_array[ROW_LENGTH][COL_LENGTH], int resultRows[ROW_LENGTH], int resultCount, char user_responses[ROW_LENGTH][COL_LENGTH]){
    // This code is basically excuting this statement: for 0 ---> resultCount: madlibs_array[resultRows[i]] = user_responses[i]. But we can't copy an entire string in C, we have to copy it char by char.
    
    // Loop through the result array to find rows and replace placeholders
    for (int i = 0; i < resultCount; i++) {
        int rowToReplace = resultRows[i]; // Row in madlibs to replace
        
        // Manually copy user_responses[i] to madlibs[rowToReplace]
        int j = 0;
        while (user_responses[i][j] != '\0' && j < COL_LENGTH - 1) {
            madlibs_array[rowToReplace][j] = user_responses[i][j];
            j++;
        }
        madlibs_array[rowToReplace][j] = '\0'; // Null-terminate the string
    }
}

// Display the updated madlibs array
void display_updated_madlibs(char madlibs_array[ROW_LENGTH][COL_LENGTH], int madlibs_rows_length){
	
	printf("\n");
	for(int i=0; i<madlibs_rows_length ; i++){ // Note: There's still a problem with "." & "," in statements like: their zeed. & their zeed . 
		printf(" %s", madlibs_array[i]);
	}
	printf("\n");
}


// Note: For extra credite: Use Command Line Arguments to get the madlibs file name at program execution.




