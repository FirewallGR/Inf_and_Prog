#include <stdio.h>
#include <math.h>

int main() {
	float x1, x2, y1, y2, r1, r2, dist, min, max;

	printf(" Hello User!\n Let's start completing the task\n Please, enter parameters of first circle(coordinates of center(x and y) and radius): ");
	scanf_s("%d %d %d", &x1, &y1, &r1);
	printf("Okay, now enter the parameters of second circle(the same): ");
	scanf_s("%d %d %d", &x2, &y2, &r2);

	dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	if (r1 > r2) {
		min = r2;
		max = r1;
	}
	else {
		min = r1;
		max = r2;
	}


	if (dist == (r1 + r2)) {
		printf("The circles touch\n");
	}
	else if ((dist < (r1 + r2)) && (dist > max)) {
		printf("The circles intersect\n");
	}
	else if (dist > (r1 + r2) && (dist > max)) {
		printf("The circles are far from each other\n");
	}
	else if ((dist + min) < max) {
		printf("One circle inside other\n");
	}
	else if ((dist + min) == max) {
		printf("internal touch\n");
	}
	return 0;
}