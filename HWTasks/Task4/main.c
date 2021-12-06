#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 10
#define SIZEX 60

void main() {
	srand(time(NULL));
	char names_list[SIZE][SIZEX] = { "name1","name2","name3","name4","name5","name6","name7","name8","name9","name10" };
	int price_list[SIZE] = { 10,20,30,40,50,60,70,80,90,100 };
	int discount[SIZE];
	int barkode[SIZE];
	int products_count[SIZE];
	int x, check, lastproduct, flagcontinue = 0, flagaddproduct = 0, w = 0, count = 0;
	char operation;
	float amounttopay, amounttopayfullprice, fulldiscount, totalprice;

	while (1) {
		if (w == 0) {


			for (int i = 0; i < SIZE; i++) {
				x = rand() % 8999 + 1000;
				check = 0;
				for (int j = 0; j < i; j++) {
					if (x == barkode[j]) {
						check = 1;
					}
				}
				if (check == 0) {
					products_count[i] = 0;
					barkode[i] = x;
					i++;
				}
				i--;
			}

			for (int i = 0; i < SIZE; i++) {
				discount[i] = rand() % 50;
			}
			printf("| Welcome!\n");
			w++;
			operation = '+';
		}

		if (operation == '+') {
			printf("|\n| To scan an item, press '1'\n| For product information press '2'\n| To add data about the product to the check, press '3'\n| To outpute a purchased products, press '4'\n| To calculate the total price, press '5'\n| To output the final check, press '6'\n| To show the product menu press '0'\n| Press + to re-display the menu\n|");
		}
		printf("\n| Input: ");
		scanf("%s", &operation);

		if (operation == '0') {
			printf("|");
			for (int i = 0; i < SIZE; i++) {
				printf("\n| Barkode: %d | Name: %s | Price: %d (Rub) | Discount: %d%% |", barkode[i], names_list[i], price_list[i], discount[i]);
			}
			printf("\n|");
		}

		if (operation == '1') {
			x = 0;
			printf("|\n| Input barkode: ");
			scanf("%d", &check);
			if (check >= 1000 & check <= 9999) {
				for (int i = 0; i < SIZE; i++) {
					if (check == barkode[i]) {
						printf("|\n|Successfully scanned\n|");
						lastproduct = i;
						x = i = SIZE;
						flagcontinue = 1;
					}
				}
			}
			if (x != SIZE) {
				printf("|\n| Invalid barkode :(\n|");
			}
		}
		if (operation == '2' & flagcontinue == 1) {
			printf("\n| Barkode: %d | Name : %s | Price : %d.00 | Discount : %d%% |\n|", barkode[lastproduct], names_list[lastproduct], price_list[lastproduct], discount[lastproduct]);
		}
		else if (operation == '3' & flagcontinue == 1) {
			printf("|\n| Product add in check\n|");
			products_count[lastproduct]++;
			count++;
			flagaddproduct = 1;
		}

		else if ((operation == '2' || operation == '3' || operation == '7') & flagcontinue != 1) {
			printf("|\n| Invalid opetation!\n|");
		}

		if (operation == '4' & flagaddproduct == 1) {
			printf("| List of goods:\n|");
			for (int i = 0, g = 1, fastprice; i < SIZE; i++) {
				if (products_count[i] != 0) {
					printf("\n| %d. Name : %s ", g, names_list[i]);
					if (products_count[i] == 1) {
						printf("\n| Price : %d.00", price_list[i]);
					}
					else if (products_count[i] > 1) {
						fastprice = products_count[i] * price_list[i];
						printf("\n| %d x %d.00", products_count[i], price_list[i]);
						printf("\n| Price : %d.00", fastprice);

					}
					g++;
				}
			}
		}

		else if ((operation == '4' || operation == '5' || operation == '6') & flagaddproduct != 1) {
			printf("|\n| No products added to the check!\n|");
		}

		if ((operation == '5' || operation == '6') & flagaddproduct == 1) {
			amounttopay = amounttopayfullprice = fulldiscount = totalprice = 0;
			for (int i = 0; i < SIZE; i++) {
				if (products_count[i] != 0) {
					amounttopayfullprice += products_count[i] * price_list[i];
					amounttopay += products_count[i] * (price_list[i] * (0.01 * (100.00 - discount[i])));
				}
			}
			if (operation == '5') {
				printf("|\n| Amount to pay: %.2f\n|", amounttopay);
			}

			if (operation == '6') {
				printf("|\n| Full list of goods:\n|\n");
				for (int i = 0, g = 1, fastprice; i < SIZE; i++) {
					if (products_count[i] != 0) {
						printf("| %d. Name : %s ", g, names_list[i]);
						if (products_count[i] == 1) {
							printf("\n| price_list : %d.00", price_list[i]);
							printf("\n| Discount : %d%%", discount[i]);
							fulldiscount += price_list[i] - (price_list[i] * (0.01 * (100 - discount[i])));
							totalprice = price_list[i] * (0.01 * (100 - discount[i]));
							printf("\n| Total price product : %.2f\n", totalprice);
						}
						else if (products_count[i] > 1) {
							fastprice = products_count[i] * price_list[i];
							fulldiscount += products_count[i] * price_list[i] - (products_count[i] * (price_list[i] * (0.01 * (100 - discount[i]))));
							totalprice = products_count[i] * (price_list[i] * (0.01 * (100 - discount[i])));
							printf("\n| %d x %d.00", products_count[i], price_list[i]);
							printf("\n| Price : %d.00", fastprice);
							printf("\n| Discount : %d%%", discount[i]);
							printf("\n| Total price product : %.2f\n", totalprice);
						}
						g++;
					}
				}
				w--;
				printf("|\n================================\n|");
				printf("\n| Full price :  %.2f", amounttopayfullprice);
				printf("\n| Discount :   -%.2f", fulldiscount);
				printf("\n| Total price : %.2f\n", amounttopay);
				system("pause");
				flagcontinue = flagaddproduct = amounttopay = amounttopayfullprice = fulldiscount = totalprice = 0;
			}
		}
	}
}