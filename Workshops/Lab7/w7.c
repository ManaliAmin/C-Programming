#include <stdio.h>
 //Count Inventory 
int cal_inventory(int bar[], double money[], int quantity[])
{
	double Value;
	double total = 0;

	for (int i = 0; bar[i]  != 0; i++){
		Value = money[i] * quantity[i];
		printf("%2d      %.2lf          %2d           %.2lf \n\n", bar[i], money[i], quantity[i], Value);
		total = Value + total;
		
	} 
	printf("                                        -----------\n");
	printf("Total value goods in stok:                 %.2lf", total);
	return total;
}
//Print table

int print(int bar[], double price[], int qualitity[]){
	int a;
	printf("       Goods in Stock             \n");
	printf("        =============\n");
	printf("Barcode        Price         Quantity       Value\n");
	printf("__________________________________________________\n");

	a = cal_inventory(bar, price, qualitity);
	
	
}
int main()
{
	int bar[100];
	int qua[100];
	double price[100];
	int i = 0;

	printf("Grocery Store Inventory\n\n");
	while (bar[i] != 0)
	{
		printf("Barcode :\n");                           //Asking for Barcode,price,Quantity
		scanf_s("%d", &bar[i]);
		if (bar[i] == 0){

			break;
		}
		else{
			printf("Price:\n");
			scanf_s("%lf", &price[i]);
			printf("Quantity:\n");
			scanf_s("%d", &qua[i]);
			i++;
		}
	}
	print(bar, price, qua);                                    // call print function




	return 0;
}

