// Copyright 2021 Marina Usova

/*
Постановка задачи.

Реализована некоторая программа, работающая с матричными операциями.

Программист начал работать над ней и понял, что в ней много дублирования кода.
Он посмотрел свой код и не увидел проблем в самом коде. Чтобы исправить
проблему дублирования он решил вынести часть кода в функции.
Помогите ему в этом, а также допишите функционал, который он не успел.

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3
#define K 2
/// <summary>
/// generated random number from min to max
/// </summary>
/// <param name="max"></param>
/// <param name="min"></param>
/// <returns></returns>
int genRandNum(int max, int min) {
    return (max - min) * ((float)rand() / RAND_MAX) + min;
}

void printMatrix(int** Matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
}
int** setMemory(int** matrix, int n, int m) {
    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(m * sizeof(int));
    }
    return matrix;
}

void cleanMemory(int** matrix, int m, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int** matrix_A = NULL, ** matrix_B = NULL, ** result = NULL;
    int max = 4, min = 0, value = 0;

    // выделение памяти под матрицу (двумерный массив)
    // N строк, M столбцов (матрица N x M)
    matrix_A = setMemory(matrix_A, N, M);

    // заполнение массива рандомными значениями
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            //srand(time(0));
            matrix_A[i][j] = genRandNum(max,min);
        }
    }

    printf("Matrix A =\n");
    // печать матрицы на экран
    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < M; j++) {
    //       printf("%d ", matrix_A[i][j]);
    //    }
    //    printf("\n");
    //}
    printMatrix(matrix_A, N, M);

    // умножение матрицы на число

    value = genRandNum(max,min);

    // выделение памяти
    result = setMemory(result, N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result[i][j] = matrix_A[i][j] * value;
        }
    }

    printf("Matrix A x %d =\n", value);
    // печать матрицы на экран
    printMatrix(matrix_A, N, M);
    // транспонирование матрицы

    result = setMemory(result, M, N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix_A[j][i];
        }
    }

    printf("Matrix AT =\n");
    // печать матрицы на экран
    printMatrix(matrix_A,N,M);

    // очищение результата после вывода
    for (int i = 0; i < M; i++) free(result[i]);
    free(result);

    // умножение двух матриц

    matrix_B = setMemory(matrix_B, M, K);

    // заполнение массива рандомными значениями
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            matrix_B[i][j] = genRandNum(max,min);
        }
    }

    printf("Matrix B =\n");
    // печать матрицы на экран
    printMatrix(matrix_B,M,K);

    result = setMemory(result, N, K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            result[i][j] = 0;
            for (int k = 0; k < M; k++) {
                result[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }

    printf("Matrix AxB =\n");
    // печать матрицы на экран
    printMatrix(matrix_B, M, K);

    // очищение результата после вывода
    for (int i = 0; i < N; i++) free(result[i]);
    free(result);

    // сложение двух матриц
    // ???
    result = setMemory(result, N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }

    printMatrix(result, N, M);

    for (int i = 0; i < M; i++) free(result[i]);
    free(result);

    // умножение вектора на число
    // ???

    // сложение двух векторов
    // ???

    // умножение двух векторов
    // ???

      // очищение всей выделенной памяти
    for (int i = 0; i < N; i++) free(matrix_A[i]);
    free(matrix_A);
    for (int i = 0; i < M; i++) free(matrix_B[i]);
    free(matrix_B);

    return 0;
}
