#include <stdio.h>

int main() {
	
	
	int isEnd = 0;
	while(isEnd!=1) {
		int result = 0;
		int number;
		int isWork = 1;
		int variant = 0;
		int accuracy = 0;
		while (accuracy == 0) {
			printf("Enter variant of game of life(1 or 2): ");
			scanf_s("%d", &variant);

			printf("Print your number: ");
			scanf_s("%d", &number);
			if (variant == 1 || variant == 2 && number >= 0) {
				accuracy = 1;
			}
		}
		if (number == 0) {
			isEnd = 1;
			break;
		}

		switch (variant) {
		case 1:
			while (number > 0) {
				result = result + number % 10;
				number /= 10;
			}
			printf("Sum = %d\n", result);
			break;
		case 2:
			result = 0;
			printf("Your number : %d\n", number);

			do {
				result = result * 10 + number % 10;
				number /= 10;
			} while (number);

			printf("result = %d\n", result);
			break;
		default:
			break;
		}
	}
	return 0;
}