void getInput(int rows, int cols, char inputArray[][cols], char placeholderArray[]){ 
	
	for(int i = 0; placeholderArray[i] != '\0'; i++){
		if(placeholderArray[i] == 'A'){
			printf("Enter an adjective: ");
			fgets(inputArray[i], cols, stdin);
		}
		else if(placeholderArray[i] == 'V'){
			printf("Enter a verb: ");
			fgets(inputArray[i], cols, stdin);
		}
		else{
			printf("Enter a noun: ");
			fgets(inputArray[i], cols, stdin);
		}
	}
}
//placeholderArray is stored A's N's and V's
//inputArray stores user inputted word
//for loop loops for every character in the placeholder array
