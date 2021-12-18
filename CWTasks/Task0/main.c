#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

void SqOfTriang(void) {
	double x, h;
	double result;
	printf("You choose square of triangle\n");
	printf("Please enter the parametres of Triangle(x and h):");
	scanf_s("%lf %lf", &x, &h);
	result = 0.5 * x * h;
	printf("Square is: %.2lf\n", result);
}
void SqOfRect() {
	float a, b, result;
	printf("You choose square of Rectangle\n");
	printf("Please enter the parametres of Rectangle(sides a and b):");
	scanf_s("%f %f", &a, &b);
	result = a * b;
	printf("Square is: %.2f\n", result);
}

void SqOfRound() {
	float r,result;
	printf("You choose square of Cicrle\n");
	printf("Please enter the parametres of Cicrle(radius):");
	scanf_s("%f", &r);
	result = M_PI * r * r * 0.5;
	printf("Square is: %.2f\n", result);
}

void Mean1() {
	int a, b, c;
	float result;
	printf("You choose Mean of 3 numbers\n");
	printf("Please enter 3 numbers:");
	scanf_s("%d %d %d", &a, &b, &c);
	result = (a + b + c) / 3;
	printf("Mean is: %.2f\n", result);
}

void Mean2() {
	int a, b, c;
	float result;
	printf("You choose Mean of square of 3 numbers\n");
	printf("Please enter 3 numbers:");
	scanf_s("%d %d %d", &a, &b, &c);
	result = (a*a + b*b + c*c) / 3;
	printf("Mean is: %.2f\n", result);
}

void Mean3() {
	int a, b, c;
	float result;
	printf("You choose Mean of abs of 3 numbers\n");
	printf("Please enter 3 numbers:");
	scanf_s("%d %d %d", &a, &b, &c);
	result = (abs(a) + abs(b) + abs(c)) / 3;
	printf("Mean is: %.2f\n", result);
}

void Mean4() {
	int a, b, c;
	float result;
	printf("You choose Mean of roots of 3 numbers\n");
	printf("Please enter 3 numbers:");
	scanf_s("%d %d %d", &a, &b, &c);
	result = (sqrt(a) + sqrt(b) + sqrt(c)) / 3;
	printf("Mean is: %.2f\n", result);
}

int main() {
	int variant;

	printf("Hello user, it's a global machine\n");
	printf("Choose what you want to see:\n\t1 - Square of Triangle\n\t2 - Square of Rectangle\n\t3 - Square of Cicrle\n\t4 - Mean of 3 numbers\n\t5 - Mean of squares of 3 numbers\n\t6 - Mean of abs of 3 numbers\n\t7 - Mean of roots of 3 numbers\n");
	scanf_s("%d",&variant);
	switch (variant) {
	case 1:
		SqOfTriang();
		break;
	case 2:
		SqOfRect();
		break;
	case 3:
		SqOfRound();
		break;
	case 4:
		Mean1();
		break;
	case 5:
		Mean2();
		break;
	case 6:
		Mean3();
		break;
	case 7:
		Mean4();
		break;
	default:
		break;
	}
	return 0;
}



