int main()
{
	int pstr = 10, pdef = 20, pinte = 40, php = 10, estr = 30, einte = 25, edef = 40, ehp = 10;
	int move, nphp;
	double ppower, epower;
	printf("Battle Start!\n");
	while (php>0 && ehp>0)
	{
		printf("Your HP:%d Enemy HP:%d\n", php, ehp);
		printf("1-Attack\n2-Magic\n");
		printf("Enter your move : \n");
		scanf_s("%d", &move);
		if (move == 1){
			printf("You attacked the enemy!\nThe enemy attacked you!\n");
			epower = (double)pstr / edef;
			ehp = (double)ehp - (epower * 5);
			ppower = (double)estr / pdef;
			php = (double)php - (ppower * 5);

		}

		if (move == 2){
			printf(" You shocked the enemy!\nThe enemy attacked you!\n");
			epower = (double)pinte / einte;
			ehp = (double)ehp - (epower * 5);
			ppower = (double)pinte / einte;
			php = (int)php - (ppower * 5);

		
		}

		if (ehp <= 0){
			printf("You won!\n");
		}
		else if (php <= 0){
			printf("You Died!\n");
		}
		


	}

	return 0;
}