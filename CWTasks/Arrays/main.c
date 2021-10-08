// COPYRIGHT 2021 @MEOWMURE
#include <stdio.h>
#define SIZE 10


int main() {
	int tmp;
	int array[SIZE];
	int multipMod2 = 1;
	int multipNotMod2 = 1;
	int multipZn = 1;
	int Ind1, Ind2;
	printf("ZAPOLNYAEM ARRAY\n");
	for (int i = 0; i < SIZE; i++) {
		scanf_s("%d", &array[i]);
	}
	for (int i = 0; i < SIZE; i++) {
		if (i % 2 == 0) {
			multipMod2 *= array[i];
		}
		else {
			multipNotMod2 *= array[i];
		}
		if (array[i] % 2 != 0) {
			multipZn *= array[i];
		}
	}
	printf("1. %d\n2. %d\n3. %d\n", multipMod2, multipNotMod2, multipZn);

	printf("begin swapping elements\n");
	printf("array before:\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array[i]);
	}

	printf("\nenter the indexes of elements\n");
	scanf_s("%d %d", &Ind1, &Ind2);

	tmp = array[Ind2];
	array[Ind2] = array[Ind1];
	array[Ind1] = tmp;

	printf("array after:\n");

	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array[i]);
	}
	

	tmp = array[Ind2];
	array[Ind2] = array[Ind1];
	array[Ind1] = tmp;

	printf("\nbegin swapping halfs of array\n");

	printf("array before:\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array[i]);
	}

	for (int i = 0; i < SIZE / 2; i++) {
		tmp = array[i];
		array[i] = array[i+SIZE/2];
		array[i+SIZE/2] = tmp;
	}

	printf("\narray after:\n");

	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}