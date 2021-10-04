#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

//This function checks the generated number for repetition
int in(int suspect, int *array, int size) {
	int flag = 0;
//	for (int i = 0; i < size; i++) {
//		printf("%d\n", array[i]);
//	}
	for (int i = 0; i < size; i++) {
		if (suspect == array[i]) flag = 1;
	}

	return flag;
}


//This function generates number of a given size
int createNumber(int n) {
	int *array = NULL;
	int result = 0, x, cache = 0, flag = 0;

	array = malloc(sizeof(int) * n);

	while (n > 0) {
		srand(time(NULL));
		x = rand() % 9 + 1;
		if (in(x, array, n) == 0) {
			result = result + x * pow(10, n-1);
			n--;
			array[n - 1] = x;
		}
	}
	return result;
}

//This function is a game
int game(int CNumber, int HNumber, int size) {
	int bull = 0;
	int cow = 0;

	int *number1 = NULL;
	int *number2 = NULL;
	number1 = malloc(sizeof(int) * size);
	number2 = malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		number1[i] = CNumber % 10;
		number2[i] = HNumber % 10;
		CNumber /= 10;
		HNumber /= 10;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (number2[i] == number1[j]) {
				if (i == j) { 
					bull++; 
					break;
				}
				else { 
					cow++;
					break;
				}
			}
		}
	}
	if (bull == size) {
		printf("you win");
		return 1;
	}
	else {
		printf("%d bulls and %d cows\n", bull, cow);
	}
	
}

//This function checks user input for an incorrect number size
int accuracy(int num, int size) {
	int count = 0;
	while (num > 0) {
		num /= 10;
		count++;
	}
	if (count == size) {
		return 1;
	} else {
		printf("you entered a number of the wrong size\n");
		return 0;
	}
}

int main() {
	int n, CNumber, HNumber;
	int isError = 0;
	while (isError != 1) {
		printf("Enter the length of number(from 2 to 5): ");
		scanf_s("%d", &n);

		switch (n)
		{
		case 2:
			isError = 1;
			CNumber = createNumber(n);
			printf("%d\n", CNumber);
			
			do {
				do {
					scanf_s("%d", &HNumber);
				} while (accuracy(HNumber, n) != 1);
			} while (game(CNumber, HNumber, n) != 1);
			
			break;
		case 3:
			isError = 1;
			CNumber = createNumber(n);
			printf("%d\n", CNumber);

			do {
				do {
					scanf_s("%d", &HNumber);
				} while (accuracy(HNumber, n) != 1);
			} while (game(CNumber, HNumber, n) != 1);

			break;
		case 4:
			isError = 1;
			CNumber = createNumber(n);
			printf("%d\n", CNumber);

			do {
				do {
					scanf_s("%d", &HNumber);
				} while (accuracy(HNumber, n) != 1);
			} while (game(CNumber, HNumber, n) != 1);

			break;
		case 5:
			isError = 1;
			CNumber = createNumber(n);
			printf("%d\n", CNumber);

			do {
				do {
					scanf_s("%d", &HNumber);
				} while (accuracy(HNumber, n) != 1);
			} while (game(CNumber, HNumber, n) != 1);

			break;
		default:
			printf("You enter incorrect size\n Please, try again\n");
			break;
		}
	}
	
	return 0;
}