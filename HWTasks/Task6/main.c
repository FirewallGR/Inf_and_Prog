//COPYRIGHT FIREWALLGR

#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

long long factorial(int n) {
	return (n < 2) ? 1 : n * factorial(n - 1);
}

long double sinTalor(float x, int N, float eps, long double etalon, int *count) {
	long double result = 0;
	int i;
	for (i = 0; i < N; i++) {
		result += pow(-1, i) * (pow(x, 2 * i + 1) / (long double) factorial(2 * i + 1));
		printf("%d\n%f\n", i, result);
		if (fabs(etalon - result) < eps) break;
	}
	*count = i;
	return result;
}

long double cosTalor(float x, int N, float eps, long double etalon, int *count) {
	long double result = 0;
	int i;
	for (i = 0; i < N; i++) {
		result += pow(-1, i) * (pow(x, 2 * i) / (long double) factorial(2 * i));
		if (fabs(etalon - result) < eps) break;
	}
	*count = i;
	return result;
}

long double expTalor(float x, int N, float eps, long double etalon, int* count) {
	long double result = 0;
	int i;
	for (i = 0; i < N; i++) {
		result += pow(x, i) / (long double) factorial(i);
		if (fabs(etalon - result) < eps) break;
	}
	*count = i;
	return result;
}

long double lnTalor(float x, int N, float eps, long double etalon, int* count) {
	long double result = 0;
	int i;
	for (i = 0; i < N; i++) {
		result += (pow(-1 , i) * pow(x , i + 1)) / (long double) (i + 1);
		if (fabs(etalon - result) < eps) break;
	}
	*count = i;
	return result;
}

void functions(int variant, float x, int n, double* result, float* etalon, float* difference ,float eps, int *count) {
	switch (variant)
	{
	case 1:
		*etalon = sin(x);
		*result = sinTalor(x, n, eps, *etalon, count);
		*difference = (*result > *etalon) ? (*result) - (*etalon) : (*etalon) - (*result);
		break;
	case 2:
		*etalon = cos(x);
		*result = cosTalor(x, n, eps, *etalon, count);
		*difference = (*result > *etalon) ? (*result) - (*etalon) : (*etalon) - (*result);
		break;
	case 3:
		*etalon = exp(x);
		*result = expTalor(x, n, eps, *etalon, count);
		*difference = (*result > *etalon) ? (*result) - (*etalon) : (*etalon) - (*result);
		break;
	case 4:
		*etalon = log(x + 1.0);
		*result = lnTalor(x, n, eps, *etalon, count);
		*difference = (*result > *etalon) ? (*result) - (*etalon) : (*etalon) - (*result);
		break;
	default:
		break;
	}
}

void main() {
	int n, nmax, variant, mode, delE,
		count = 0,
		modeFlag = 0,
		varFlag = 0,
		xFlag = 0,
		nFlag = 0;
	float x, 
		etalon = 0, 
		difference = 0, 
		eps = 0.000001;
	long double result = 0;


	void (*func)(int, float, int, float*, float*, float*, float, int*);
	func = functions;
	printf("mode 1 2:\n");
	do {
		scanf_s("%d", &mode);
		if (mode == 1 || mode == 2) modeFlag = 1;
		else printf("1 2\n");
	} while (modeFlag != 1);
	
	printf("Variant 1 2 3 4:\n");
	do {
		scanf_s("%d", &variant);
		if (variant >= 1 && variant <= 4) varFlag = 1;
		else printf("1 2 3 4\n");
	} while (varFlag != 1);
	
	printf("x:\n");
	do {
		scanf_s("%f", &x);
		if (-1 <= x && x <= 1) xFlag = 1;
		else printf("from -1 to 1\n");
	} while (xFlag != 1);

	printf("delE:\n");
	scanf_s("%d", &delE);

	switch (mode)
	{
	case 1:
		printf("n:\n");
		do {
			scanf_s("%d", &n);
			if (1 <= n && n <= 1000) nFlag = 1;
			else printf("from 1 to 1000\n");
		} while (nFlag != 1);
		

		func(variant, x, n, &result, &etalon, &difference, eps, &count);
		printf("etalon - %.*f\nresult - %.*lf\ndifference - %.*f\nsummand - %d\n", delE, etalon, delE, result, delE, difference, count);
		break;
	case 2:
		printf("nMax:\n");
		scanf_s("%d", &nmax);
		srand(time(NULL));
		for (int i = 0; i < nmax; i++) {
			n = rand() % 999 + 1;
			printf("%d\n", n);
			func(variant, x, n, &result, &etalon, &difference, eps, &count);
			printf("|etalon - %.*f|\t|result - %.*lf|\t|difference - %.*f|\t|summand - %d|\n", delE, etalon, delE, result, delE, difference, count);
		}
		break;
	default:
		break;
	}
}