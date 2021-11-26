#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 25000
void swap(int* felem, int* selem) {
	int tmp = *felem;
	*felem = *selem;
	*selem = tmp;
}

void quicksort(int* mass, int first, int last, int* swaps) {
	int left_point = first, right_point = last, pivot = mass[(first + last) / 2];

	do {
		while (mass[left_point] < pivot) left_point++;
		while (mass[right_point] > pivot) right_point--;

		if (left_point <= right_point) {
            if (mass[left_point] > mass[right_point]) { 
                swap(&mass[left_point], &mass[right_point]);
                *swaps = *swaps + 1;
            }
			left_point++;
			right_point--;
		}
	} while (left_point <= right_point);

	if (left_point < last) quicksort(mass, left_point, last, swaps);
	if (right_point > first) quicksort(mass, first, right_point, swaps);
}

void siftDown(int* numbers, int root, int bottom) {
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done)){
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (numbers[root] < numbers[maxChild]){
            int temp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else
            done = 1;
    }
}

void heapSort(int* numbers, int array_size, int* swap) {

    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    for (int i = array_size - 1; i >= 1; i--) {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        *swap = *swap + 1;
        siftDown(numbers, 0, i - 1);
    }
}

void InsertionSort(int n, int mass[], int* swap) {
    int newEl;
    int loc;

    for (int i = 1; i < n; i++) {
        newEl = mass[i];
        loc = i - 1;
        while (loc >= 0 && mass[loc] > newEl) {
            mass[loc + 1] = mass[loc];
            loc--;
            *swap = *swap + 1;
        }
        mass[loc + 1] = newEl;
    }
}

void genNumbers(int* numbers, int size, int x, int y) {
    for (int i = 0; i < size; i++)
        numbers[i] = x + rand() % (y - x + 1);
}

void main() {
    float time = 0;
    int swapQuick = 0;
    int swapPiramid = 0;
    int swapInsert = 0;
    int* mass = malloc(sizeof(int) * SIZE);
    int* mass2 = malloc(sizeof(int) * SIZE);
    int* mass3 = malloc(sizeof(int) * SIZE);

    genNumbers(mass, SIZE, 0, 100);
    time = clock();
	quicksort(mass, 0, SIZE-1, &swapQuick);
    time = clock() - time;
//	for (int i = 0; i < SIZE; i++) {
//		printf_s("%d ", mass[i]);
//	}
    printf("\n%d\n%f\n", swapQuick, time);
    
    genNumbers(mass2, SIZE, 0, 100);
    time = clock();
    heapSort(mass2, SIZE, &swapPiramid);
    time = clock() - time;
 //   for (int i = 0; i < SIZE; i++) {
  //      printf("%d ", mass2[i]);
    //}
    printf("\n%d\n%f\n", swapPiramid, time);
    
    genNumbers(mass3, SIZE, 0, 100);
    time = clock();
    InsertionSort(SIZE, mass3, &swapInsert);
    time = clock() - time;
//    for (int i = 0; i < SIZE; i++) {
//        printf("%d ", mass3[i]);
//    }
    printf("\n%d\n%f\n", swapInsert, time);
}