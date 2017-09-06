
void clearScreen(){
	int clr = 1;
	for (clr = 1; clr < 40; clr++){
		printf("\n");
	}
		
}

int retreive(int min, int max){

	int select;
	scanf_s("%d", &select);
	while (select <min || select> max){
		printf("Invalid Input, try again:");
		scanf_s("%d", &select);
	}
	return select;
}
void newGame(){
	printf("Not Implemented newgame!\n");
	getchar();
	getchar();
    
}
void load(){
	printf("Not Implemented load!\n");
	getchar();
	//getchar();
}
int main() 
{
		int sel;
	do{
		clearScreen();
		printf("-- Main Menu --\n");
		printf("1- New Game\n");
		printf("2- Load Game\n");
		printf("3 - Exit\n");
		printf("Select:\n");
		sel = retreive(1, 3);
		if (sel == 1){
			newGame();
		}
		else if (sel == 2)
		{
			load();
		}
		else {
			printf("Good Bye!");
			exit();
		}
	} while (sel==1 || sel==2 );
	return;


	
}