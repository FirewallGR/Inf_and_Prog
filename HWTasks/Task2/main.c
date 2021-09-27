//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>


int main() {
	int Variant, HNumber, CNumber, accuracy = 0, win = 0, count = 0, multiplier = 1000;
	char comparison;
	char greater = '>';
	char less = '<';
	char equally = '=';
	while (accuracy != 1) {
		printf("Please, enter variant of game(1 or 2): ");
		scanf_s("%d", &Variant);

		switch (Variant)
		{
		case 1:
			srand(time(NULL));
			CNumber = rand() % 1000 + 1;
			printf("%d\n", CNumber);
			printf("Computer generated random number\n Your turn\n Guess the number\n");
			while (win != 1) {
				scanf_s("%d", &HNumber);
				if (HNumber > CNumber) {
					printf("The hidden number is less\n");
					count++;
				}
				if (HNumber < CNumber) {
					printf("The hidden number is greater\n");
					count++;
				}
				if (HNumber == CNumber) {
					printf("You got this\n");
					count++;
					win = 1;
				}
			}
			accuracy = 1;
			break;
		case 2:
			scanf_s("%d", &HNumber);
			while (win != 1) {
				srand(time(NULL));
				CNumber = rand() % multiplier + 1;
				printf("Computer guess that number is %d Is it true?\n", CNumber);
				scanf_s("%c", &comparison, 1);
				if (comparison == greater) {
					if (multiplier < HNumber) {
						multiplier++;
					}
					count++;
				}
				else if (comparison == less) {
					multiplier--;
					count++;
					printf("%d", multiplier);
				}
				else if (comparison == equally) {
					printf("Game over\n Computer is right\n");
					count++;
					win = 1;
				}
			}
			accuracy = 1;
			break;
		default:
			printf("You wrote wrong variant\n");
			break;
		}
	}
	printf("%d\n", count);

	return 0;
}