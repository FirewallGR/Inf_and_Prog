// Copyright 2021 Marina Usova

/*
���������� ������.

����������� ��������� ���������, ���������� � ���������� ����������.

����������� ����� �������� ��� ��� � �����, ��� � ��� ����� ������������ ����.
�� ��������� ���� ��� � �� ������ ������� � ����� ����. ����� ���������
�������� ������������ �� ����� ������� ����� ���� � �������.
�������� ��� � ����, � ����� �������� ����������, ������� �� �� �����.

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

    // ��������� ������ ��� ������� (��������� ������)
    // N �����, M �������� (������� N x M)
    matrix_A = setMemory(matrix_A, N, M);

    // ���������� ������� ���������� ����������
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            //srand(time(0));
            matrix_A[i][j] = genRandNum(max,min);
        }
    }

    printf("Matrix A =\n");
    // ������ ������� �� �����
    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < M; j++) {
    //       printf("%d ", matrix_A[i][j]);
    //    }
    //    printf("\n");
    //}
    printMatrix(matrix_A, N, M);

    // ��������� ������� �� �����

    value = genRandNum(max,min);

    // ��������� ������
    result = setMemory(result, N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result[i][j] = matrix_A[i][j] * value;
        }
    }

    printf("Matrix A x %d =\n", value);
    // ������ ������� �� �����
    printMatrix(matrix_A, N, M);
    // ���������������� �������

    result = setMemory(result, M, N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix_A[j][i];
        }
    }

    printf("Matrix AT =\n");
    // ������ ������� �� �����
    printMatrix(matrix_A,N,M);

    // �������� ���������� ����� ������
    for (int i = 0; i < M; i++) free(result[i]);
    free(result);

    // ��������� ���� ������

    matrix_B = setMemory(matrix_B, M, K);

    // ���������� ������� ���������� ����������
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            matrix_B[i][j] = genRandNum(max,min);
        }
    }

    printf("Matrix B =\n");
    // ������ ������� �� �����
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
    // ������ ������� �� �����
    printMatrix(matrix_B, M, K);

    // �������� ���������� ����� ������
    for (int i = 0; i < N; i++) free(result[i]);
    free(result);

    // �������� ���� ������
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

    // ��������� ������� �� �����
    // ???

    // �������� ���� ��������
    // ???

    // ��������� ���� ��������
    // ???

      // �������� ���� ���������� ������
    for (int i = 0; i < N; i++) free(matrix_A[i]);
    free(matrix_A);
    for (int i = 0; i < M; i++) free(matrix_B[i]);
    free(matrix_B);

    return 0;
}
