#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	int x1, x2, y1, y2,figure, f1 = 0,f2 = 0,f3 = 0,f4 = 0,f5 = 0;
		printf("Enter x and y for first figure: ");
		scanf_s("%d %d", &x1, &y1);
		printf("Enter x and y for second figure: ");
		scanf_s("%d %d", &x2, &y2);

		printf("Select your hero:\n 1-Ferz\n 2-King\n 3-Ladia\n 4-Elephant\n 5-Horse\n ");
		scanf_s("%d", &figure);

		if ((x1 == x2 || y1 == y2) || (abs(x2 - x1) == abs(y2 - y1))) {
			f1 = 1;
		}
		if ((abs(x2 - x1) == 1 && abs(y2 - y1) <= 1) || (abs(y2 - y1) == 1 && abs(x2 - x1) <= 1)) {
			f2 = 1;
		}
		if (abs(x2 - x1) == abs(y2 - y1)) {
			f3 = 1;
		}
		if (x1 == x2 || y1 == y2) {
			f4 = 1;
		}
		if (((abs(x2 - x1) == 3) && (abs(y2 - y1) == 1)) || ((abs(y2 - y1) == 3) && (abs(x2 - x1) == 1))) {
			f5 = 1;
		}
		switch (figure) {
		case 1:
			if (f1 == 1) {
				printf("Ferz mozhet\n");
			}
			else {
				if (f2 == 1) {
					printf("King mozhet\n");
				}
				if (f3 == 1) {
					printf("Ladia mozhet\n");
				}
				if (f4 == 1) {
					printf("Elephant mozhet\n");
				}
				if (f5 == 1) {
					printf("Horse mozhet\n");
				}
			}
			break;
		case 2:
			if (f2 == 1) {
				printf("King mozhet\n");
			}
			else {
				if (f1 == 1) {
					printf("Ferz mozhet\n");
				}
				if (f3 == 1) {
					printf("Ladia mozhet\n");
				}
				if (f4 == 1) {
					printf("Elephant mozhet\n");
				}
				if (f5 == 1) {
					printf("Horse mozhet\n");
				}
			}
			break;
		case 3:
			if (f3 == 1) {
				printf("Ladia mozhet\n");
				break;
			}
			else {
				if (f2 == 1) {
					printf("King mozhet\n");
				}
				if (f1 == 1) {
					printf("Ferz mozhet\n");
				}
				if (f4 == 1) {
					printf("Elephant mozhet\n");
				}
				if (f5 == 1) {
					printf("Horse mozhet\n");
				}
			}
			break;
		case 4:
			if (f4 == 1) {
				printf("Elephant mozhet\n");
				break;
			}
			else {
				if (f2 == 1) {
					printf("King mozhet\n");
				}
				if (f3 == 1) {
					printf("Ladia mozhet\n");
				}
				if (f1 == 1) {
					printf("Ferz mozhet\n");
				}
				if (f5 == 1) {
					printf("Horse mozhet\n");
				}
			}
			break;
		case 5:
			if (f5 == 1) {
				printf("Horse mozhet\n");
				break;
			}
			else {
				if (f2 == 1) {
					printf("King mozhet\n");
				}
				if (f3 == 1) {
					printf("Ladia mozhet\n");
				}
				if (f4 == 1) {
					printf("Elephant mozhet\n");
				}
				if (f1 == 1) {
					printf("Ferz mozhet\n");
				}
			}
			break;
		default:
			break;
		}
		return 0;
	}