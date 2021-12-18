#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_BALL 100
#define ABIT_LENG 4

int main() {
	int nAb, kAb, prBall;
	int** array;
	int* sum;
	int sumL = 0;
	int* temp;
	scanf_s("%d",&nAb);
	array = (int**)malloc(sizeof(int*) * nAb);
	sum = (int*)malloc(sizeof(int) * nAb);
	temp = (int*)malloc(sizeof(int) * nAb);
	for (int i = 0; i < nAb; i++) {
		array[i] = (int*)malloc(sizeof(int) * ABIT_LENG);
	}

	//ZAPOLNENIE VSEH ABITUROV
	for (int i = 0; i < nAb; i++) {
		array[i][0] = i+1;
		for (int j = 1; j < ABIT_LENG; j++) {
			if (array[i][j] != array[i][j - 1]) {
				array[i][j] = rand() % 100;
			}		
		}
	}

	//VIVOD VSEH ABITUROV
	for (int i = 0; i < nAb; i++) {
		for (int j = 0; j < ABIT_LENG; j++) {
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}

	//SUMMA BALLOV
	for (int i = 0; i < nAb; i++) {
		sumL = 0;
		for (int j = 1; j < ABIT_LENG; j++) {
			sumL += array[i][j];
		}
		sum[i] = sumL;
	}

	//VIVOD SUMMI
	printf("\n");
	for (int i = 0; i < nAb; i++) {
		printf("%d ", sum[i]);
	}
	printf("\n");

	//VVOD KKOLVA ABITUROV
	scanf_s("%d", &kAb);
	
	for (int i = 0; i < nAb; i++) {
		temp[i] = sum[i];
	}

	for (int i = 0; i < nAb; i++) {
		for (int j = 0; j < nAb; j++) {
			if (temp[i] > temp[j]) {
				int tmp = temp[j];
				temp[j] = temp[i];
				temp[i] = tmp;
			}
		}
	}

	/* 
	for (int i = 0; i < nAb; i++) {
		printf("%d ", temp[i]);
	}
	printf("\n");
	*/
	prBall = temp[kAb - 1];

	
	for (int i = 0; i < nAb; i++) {
		if (sum[i] >= prBall) {
			printf("%d ", i);
		}
	}
	printf("\n%d", prBall);
	return 0;
}