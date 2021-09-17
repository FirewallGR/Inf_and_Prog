#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	int x1, x2, y1, y2,figure;
	while (1) {
		printf("Enter x and y for first figure: ");
		scanf_s("%d %d", &x1, &y1);
		printf("Enter x and y for second figure: ");
		scanf_s("%d %d", &x2, &y2);

		printf("Select your hero:\n 1-Ferz\n 2-King\n 3-Ladia\n 4-Elephant\n 5-Horse\n ");
		scanf_s("%d", &figure);
		if (figure == 1) {
			printf("YOUR HERO IS FERZ\n");
			if ((x1 == x2 || y1 == y2) || (abs(x2 - x1) == abs(y2 - y1))) {
				printf("Mozhet\n");
			}
			else {
				printf("nemozhet\n");
			}
		}
		else if (figure == 2) {
			printf("YOUR HERO IS KING\n");
			if ((abs(x2 - x1) == 1 && abs(y2 - y1) <= 1) || (abs(y2 - y1) == 1 && abs(x2 - x1) <= 1)) {
				printf("MOZHET\n");
			}
			else {
				printf("NEMOZHET\n");
			}
		}
		else if (figure == 3) {
			printf("YOUR HERO IS LADIA\n");
			if (abs(x2 - x1) == abs(y2 - y1)) {
				printf("MOZHET\n");
			}
			else {
				printf("NE MOZHET\n");
			}

		}
		else if (figure == 4) {
			printf("YOUR HERO IS ELEPHANT\n");
			if (x1 == x2 || y1 == y2) {
				printf("MOZHET\n");
			}
			else {
				printf("NE MOZHET\n");
			}
		}
		else if (figure == 5) {
			printf("YOUR HERO IS HORSE\n");
			if (((abs(x2 - x1) == 3) && (abs(y2 - y1) == 1)) || ((abs(y2 - y1) == 3) && (abs(x2 - x1) == 1))) {
				printf("MOZHET\n");
			}
			else {
				printf("NEMOZHET\n");
			}
		}
	}
	
	

	
	return 0;
}