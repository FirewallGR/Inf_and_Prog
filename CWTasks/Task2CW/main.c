#include <stdio.h>

int main() {
	int price;
	int m1 = 1, m2 = 5, m3 = 10, m4 = 25, k1 = 0, k2 = 0, k3 = 0, k4 = 0;

	printf("Set the price Witcher ");
	scanf_s("%d", &price);

	while (price > 0) {
		while (price >= m4) {
			k4++;
			price = price - m4;
		}
		while (price >= m3) {
			k3++;
			price = price - m3;
		}
		while (price >= m2) {
			k2++;
			price = price - m2;
		}
		while (price >= m1) {
			k1++;
			price = price -m1;
		}
	}
	printf("%d %d %d %d", k4,k3,k2,k1);
	return 0;
}