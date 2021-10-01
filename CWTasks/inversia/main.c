#include <stdio.h>

int main() {
	int result = 0;
	int number;
	int isWork = 1;
	int variant = 0;
	int accuracy = 0;

	while (accuracy == 0) {
		printf("Enter variant of game of life(1 or 2): ");
		scanf_s("%d", &variant);

		if (variant == 1 || variant == 2) {
			accuracy = 1;
		}
	}

	switch (variant) {
	case 1:
		accuracy = 0;
		printf("You choose first variant\n");
		while (accuracy != 1) {
			printf("Print your number: ");
			scanf_s("%d", &number);

			if (number >= 0) {
				accuracy = 1;
			}
			else {
				printf("you wrote negative number\n please, try again\n");
			}
		}
		

		while (number > 0) {
			result = result + number % 10;
			number /= 10;
		}
		printf("Sum = %d\n", result);
		break;
	case 2:
		printf("You choose second variant\n ");
		while (isWork) {
			printf("Let's begin!\n Write 0 to terminate\n");

			int isError = 0;
			do {
				if (isError) {
					printf("You wrote wrong number\n Try again\n");
				}

				printf("Input number > 0: \n");
				scanf_s("%d", &number);

				if (number == 0) {
					isWork = 0;
					break;
				}

				isError = (number <= 0);
			} while (isError);

			if (!isWork) continue;

			if (isWork) {
				result = 0;
				printf("Your number : %d\n", number);

				do {
					result = result * 10 + number % 10;
					number /= 10;
				} while (number);

				printf("result = %d\n", result);
			}
		}
		break;
	default:
		break;

	}

	

	return 0;
}