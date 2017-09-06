
void rest_at_inn(float* days_remaining, int* hp_remaining, int max){


	*days_remaining -= 1;
	*hp_remaining = max;
		printf("You rested up the at the inn\n\n");

}
void train(float* days_remaining, int* hp_remaining, int* experience)
{
	*experience += 10;
	*hp_remaining -= 2;
	*days_remaining -= 0.5;
		printf("You did some training!\n");
}
void battle_demon_lord(int* current_hp)
{
		printf("He's too strong!\n\n");
		*current_hp = 0;
        printf("Game Over!\n");
	}

int main()
{
	float days_remaining = 8.00;
	int currentHP = 10, max = 10, exp = 0;
	int sel;
	do {
		printf("Days remaining:%.1f HP:%d Exp:%d\n", days_remaining, currentHP, exp);
		printf("-- Main Menu --\n");
		printf("1- Rest at Inn\n2- Train\n3- Fight the Demon Lord\n4- Quit Game\n");
		printf("select:\n");
		scanf_s("%d", &sel);
		if (sel == 1){
			rest_at_inn(&days_remaining, &currentHP, max);

		}
		else if (sel == 2)
		{
			train(&days_remaining, &currentHP, &exp);

		}
		else if (sel == 3)
		{
			battle_demon_lord(&currentHP);

		}
		else {
			printf("Game Over!");
			return 0;
		}
	} while (days_remaining > 0 && currentHP> 0);
		if (&days_remaining <= 0 || &currentHP <= 0 || sel==3 )
		{
			printf("Game Over!\n");
		}
		return;
}
	
 