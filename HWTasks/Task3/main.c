#include <stdio.h>
#include <math.h>
#include <time.h>
#include <set>
#include <stdlib.h>
#include <conio.h>

int main() {
	int n, CNumber, HNumber;
	
	printf("Enter the length of number(from 2 to 5): ");
	scanf_s("%d",&n);

	switch (n)
	{
	case 2:
		CNumber = createNumber(n);
		printf("%d", CNumber);
		break;
	case 3:
		CNumber = createNumber(n);
		printf("%d", CNumber);
		break;
	case 4: 
		CNumber = createNumber(n);
		printf("%d", CNumber);
		break;
	case 5:
		CNumber = createNumber(n);
		printf("%d", CNumber);
		break;
	default:
		break;
	}
	return 0;
}

int createNumber(int n) {
	int result = 0, x, cache = 0, flag = 0;
	while (n > 0) {
		srand(time(NULL));
		x = rand() % 9 + 1;
		/*for (int i; i < size; i++) {
			if (p[i] == x) {
				flag = 1;
			}
			else {
				flag = 0;
			}
		}*/
		if (flag == 1) {
			result = result + (x * pow(10, n - 1));
			n--;
		}
		cache = x;
	}
	return result;
}