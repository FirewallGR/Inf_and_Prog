#define _CRT_SECURE_NO_WARNINGS
#include <C:\Users\sskam\OneDrive\Рабочий стол\CLion Projects\Inf_and_Prog\HWTasks\dirent-1.23.2\include\dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>


int fileSizes[255];
int i = 0;
char fileName[255][255];
int getFileSize(const char* file) {
    struct stat st;
    int full_size = 0;

    if (stat(file, &st) == 0) {
        if ((st.st_mode & S_IFMT) == S_IFDIR)
            return -1;
        else if ((st.st_mode & S_IFMT) == S_IFREG)
            return st.st_size;
        else
            return -2;
    }
}

void getSizesFromDir(char* path) {
    struct dirent* cur_file;
    DIR* dir;

    char full_file_path[200];

    dir = opendir(path);

    if (dir) {
        while ((cur_file = readdir(dir)) != NULL) {
            if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {
                strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
                int cur_file_size = getFileSize(full_file_path);
                if (cur_file_size >= 0) {
                    //printf("%s - %d B (%d kB)\n", cur_file->d_name, cur_file_size, cur_file_size / 1024);
                    strncpy(fileName[i], cur_file->d_name, 254);
                    fileSizes[i] = cur_file_size;
                    fileName[i][254] = '\0';
                    i++;
                }  
                else if (cur_file_size == -1)
                    getSizesFromDir(full_file_path);
            }
        }
        closedir(dir); 
    }
}

void quickSort(int* sizes, int* indexes, int first, int last) {
    int left_point = first, right_point = last, pivot = sizes[(first + last) / 2];

    do {
        while (sizes[left_point] < pivot) left_point++;
        while (sizes[right_point] > pivot) right_point--;
        if (left_point <= right_point) {
            if (sizes[left_point] > sizes[right_point]) {
                int tmpsize = sizes[right_point];
                sizes[right_point] = sizes[left_point];
                sizes[left_point] = tmpsize;

                int tmpindex = indexes[right_point];
                indexes[right_point] = indexes[left_point];
                indexes[left_point] = tmpindex;
            }
            left_point++;
            right_point--;
        }

    } while (left_point <= right_point);

    if (left_point < last) quickSort(sizes, indexes, left_point, last);
    if (right_point > first) quickSort(sizes, indexes, first, right_point);

}

void siftDown(int* numbers,int* indexes, int root, int bottom) {
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (numbers[root] < numbers[maxChild]) {
            int temp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            int tmpindex = indexes[root];
            indexes[root] = indexes[maxChild];
            indexes[maxChild] = tmpindex;
            root = maxChild;
        }
        else
            done = 1;
    }
}

void heapSort(int* numbers,int* indexes, int array_size, int* swap) {

    for (int k = (array_size / 2); k >= 0; k--)
        siftDown(numbers,indexes, k, array_size - 1);
    for (int k = array_size - 1; k >= 1; k--) {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        *swap = *swap + 1;
        siftDown(numbers,indexes, 0, i - 1);
    }
}

void InsertionSort(int n, int mass[],int* indexes, int* swap) {
    int newEl;
    int loc;
    int newElIn;

    for (int k = 1; k < n; k++) {
        newEl = mass[k];
        newElIn = indexes[k];
        loc = k - 1;
        while (loc >= 0 && mass[loc] > newEl) {
            mass[loc + 1] = mass[loc];
            indexes[loc + 1] = indexes[loc];
            loc--;
            *swap = *swap + 1;
        }
        mass[loc + 1] = newEl;
        indexes[loc + 1] = newElIn;
    }
}

int main() {
    int sort;
    int time;
    int swap;
    char path[200];
    printf("Input path to dir: ");
    gets(path);

    printf("Choose sort mode(1 - quick sort, 2 - insertion sort, 3 - piramid sort\n");
    scanf_s("%d", &sort);

    printf("\n\n\nUnsorted files:\n\n\n");
    getSizesFromDir(path);

    for (int j = 0; j < i; j++) {
        printf("File name - %s \nFile size - %d B (%d KB)\n", fileName[j], fileSizes[j], fileSizes[j] / 1024);
    }

    int* indexes = malloc(sizeof(int) * i);
    for (int j = 0; j < i; j++) {
        indexes[j] = j;
    }
    
    if (sort == 1) {
        time = clock();
        quickSort(fileSizes, indexes, 0, i - 1);
        time = clock() - time;
    }
    else if (sort == 2) {
        time = clock();
        heapSort(fileSizes, indexes, i, &swap);
        time = clock() - time;
    }
    else if (sort == 3) {
        time = clock();
        InsertionSort(i, fileSizes, indexes, &swap);
        time = clock() - time;
    }
    


    printf("\n\n\nSorted files\n\n\n");
    for (int j = 0; j < i; j++) {
        int k = indexes[j];
        printf("File name - %s\nFile size - %d B (%d KB)\n", fileName[k], fileSizes[j], fileSizes[j] / 1024);
    }
    printf("Sorting time - %d\n", time);

    return 0;
}