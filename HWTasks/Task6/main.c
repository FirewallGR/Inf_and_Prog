//COPYRIGHT FIREWALLGR


#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

long long factorial(int n) {
	return (n < 2) ? 1 : n * factorial(n - 1);
}

long double sinTalor(float x, int N) {
	long double result = 0;
	int i;
	for (i = 0; i < N; i++) {
		result += pow(-1, i) * (pow(x, 2 * i + 1) / (long double) factorial(2 * i + 1));
		printf("%d\n%f\n", i, result);
	}
	
	return result;
}

long double cosTalor(float x, int N) {
	long double result = 0;
	for (int i = 0; i < N; i++) {
		result += pow(-1, i) * (pow(x, 2 * i) / (long double) factorial(2 * i));
	}
	return result;
}

long double expTalor(float x, int N) {
	long double result = 0;
	for (int i = 0; i < N; i++) {
		result += pow(x, i) / (long double) factorial(i);
	}
	return result;
}

long double lnTalor(float x, int N) {
	long double result = 0;
	for (int i = 0; i < N; i++) {
		result += (pow(-1 , i) * pow(x , i + 1)) / (long double) (i + 1);
	}
	return result;
}

void functions(int variant, float x, int n, double* result, float* etalon, float* difference) {
	switch (variant)
	{
	case 1:
		*result = sinTalor(x, n);
		*etalon = sin(x);
		*difference = (*result > *etalon) ? (*result) - (*etalon) : (*etalon) - (*result);
		break;
	case 2:
		*result = cosTalor(x, n);
		*etalon = cos(x);
		*difference = (*result > *etalon) ? (*result) - (*etalon) : (*etalon) - (*result);
		break;
	case 3:
		*result = expTalor(x, n);
		*etalon = exp(x);
		*difference = (*result > *etalon) ? (*result) - (*etalon) : (*etalon) - (*result);
		break;
	case 4:
		*result = lnTalor(x, n);
		*etalon = log10f(x);
		*difference = (*result > *etalon) ? (*result) - (*etalon) : (*etalon) - (*result);
		break;
	default:
		break;
	}
}

void main() {
	int n, nmax, variant, mode, delE;
	float x, etalon = 0, difference = 0;
	long double result = 0;
	void (*func)(int, float, int, float*, float*, float*);
	func = functions;

	printf("mode 1 2:\n");
	scanf_s("%d", &mode);

	printf("Variant 1 2 3 4:\n");
	scanf_s("%d", &variant);

	printf("x:\n");
	scanf_s("%f", &x);

	printf("delE:\n");
	scanf_s("%d", &delE);

	switch (mode)
	{
	case 1:
		printf("n:\n");
		scanf_s("%d", &n);

		func(variant, x, n, &result, &etalon, &difference);
		printf("etalon - %.*f\nresult - %.*lf\ndifference - %.*f\nsummand - %d\n", delE, etalon, delE, result, delE, difference, n);
		break;
	case 2:
		printf("nMax:\n");
		scanf_s("%d", &nmax);
		for (int i = 0; i < nmax; i++) {
			n = rand() % 999 + 1;
			func(variant, x, n, &result, &etalon, &difference);
			printf("|etalon - %.*f|\t|result - %.*lf|\t|difference - %.*f|\t|summand - %d|\n", delE, etalon, delE, result, delE, difference, n);
		}
		break;
	default:
		break;
	}
}