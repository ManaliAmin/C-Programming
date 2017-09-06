#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include<math.h>


char getValidCharacter(char low, char high);
void initPlayer(int* playerScore, int playerPrizes[], unsigned int * prizeCount, char* playerName, int* playerPosition);
int getValidItenger(int low, int high);
void playGame(unsigned int boardSize, int *playerScore, int playerPrizes[], unsigned int* prizeCount, char * playerName, int* playerPosition);
void displayBoard(unsigned int size, char playerName, unsigned int playerPosition);
char getTileType(unsigned int index, char	playerName, unsigned int playerPosition);
unsigned int playerRoll();
int getRandom(int low, int high);
void winPrize(int playerPrizes[], unsigned int* prizeCount);
void winGrandPrize(int playerPrizes[], unsigned int* prizeCount);
int loseItem(int playerPrizes[], unsigned int* prizeCount);
int checkout(int* playerScore, int playerPrizes[], unsigned int* prizeCount);

int main(void){
	char userInput;
	int *playerScore;               //aa individuals ata ane bdle 8 instance na array krvana  ha etle hu evu keti ti k
	int *prizeCount;
	int *playerPosition;
	int boardSize;
	int *highScore = 100;
	int score = 0;
	char *playerName;
	char highName = NULL;

	printf("\nWelcome to CHECKOUT\n");
Menu:
	printf("\nMain Menu\n\n");
	printf("p - (p)lay q - (q)uit r - inst(r)uctions s - HI(s)core: ");
	userInput = getValidCharacter('p', 's');

	               //Play Game

	if (userInput == 'p'){
		int check, playerPrizes[10];
		initPlayer(&playerScore, playerPrizes, &prizeCount, &playerName, &playerPosition);
		printf("Enter board size: ");
		boardSize = getValidItenger(5, 15);
		playGame(boardSize, &playerScore, playerPrizes, &prizeCount, &playerName, &playerPosition);
		score = checkout(&playerScore, playerPrizes, &prizeCount);

		if (score > 200){

			printf("You won the game!");
			if (score > highScore){
				highScore = score;
				highName = playerName;
			}
		}
		else{

			printf("You lose the game!");

		}
		goto Menu;

	} 

	        // Displaying HighScore

	else if (userInput == 's'){



		printf("___\n");
		printf("   \\_______\n");
		printf("    \\++++++|\n");
		printf("     \\=====|\n");
		printf("     0---  0\n");
		printf("Score: %d, Player's Name:%c", highScore, highName);
		goto Menu;
	}

	//Instructions

	else if (userInput == 'r'){
		printf("                       Game Rules:\n");
		printf("                       ============\n");
		printf("-Up to 8 players compete to be the first to obtain $1000\n");
		printf("- Game takes place on a square board with 5 tile types\n");
		printf("		o Empty Tile – No effect\n");
		printf("		o Win Tile – Win a random prize\n");
		printf("		o Lose Tile – Lose a random prize\n");
		printf("		o Grand Prize Tile – Win a grand prize\n");
		printf("		o Checkout Tile – Sells all your prizes for cash\n");
		printf("- Players can roll 1 - 3 dice to determine how many tiles they move each turn\n");
		printf("- If a player lands on the same tile as another player, that player steals a prize and moves 1 tile back\n ");
		main();
	}
	                           //Quit

	else if (userInput == 'q'){
		printf("This game is much more fun than bash...");
	}
	else{
		printf("INVALID!");
	}
     return 0;
}
                       //Validate Integer

int getValidItenger(int low, int high){

	int num;
	scanf("%d", &num);
	while (getchar() != '\n');
	while ((num < low || num > high)){

		printf("INVALID! Please enter value between %d and %d:\n", low, high);
		scanf("%d", &num);
		while (getchar() != '\n');
	}
    return num;
}

                         //Validate Character

char getValidCharacter(char low, char high){

	char cha;
	scanf(" %c", &cha);
	while (cha < low || cha > high)
	{
		printf("INVALID! Please enter value between %c and %c:\n", low, high);
		scanf(" %c", &cha);
	}

	return cha;
}
                             //Initlize PlayerName
void initPlayer(int* playerScore, int playerPrizes[], unsigned int * prizeCount, char * playerName, int* playerPosition){
	char name;
	int boardSize, i, prize = 0;
	printf("number of players is 1\n");
	printf("Enter One character long name : ");
	scanf(" %c", &name);
    *playerScore = 0;
	for (i = 0; i < 10; i++){
         playerPrizes[i] = 0;
	}
	*prizeCount = 0;
	*playerName = name;
	*playerPosition = 0;
}
                                // Playing Game

void playGame(unsigned int boardSize, int *playerScore, int playerPrizes[], unsigned int* prizeCount, char * playerName, int* playerPosition){
	int position, score, total, i;
	 do{
		displayBoard(boardSize, *playerName, *playerPosition);                                         //Displaying Board
		printf("Score %d  Inventory( items): ", *playerScore);
		for (i = 0; i < 10; i++){
			if (playerPrizes[i]>10 && playerPrizes[i]<200){
				printf("%d,", playerPrizes[i]); 
              }
		}
		total = playerRoll();
		printf("\nAdvancing %d spaces\n", total);
		*playerPosition += total;
		if (*playerPosition >= (4 * boardSize - 4)){
			*playerPosition = *playerPosition - (4 * boardSize - 4);
		}
		if (*playerPosition == 0){                                                                   //Analizing Prizes

			return;

		}
		else if (*playerPosition % 3 == 0 && *playerPosition % 5 == 0 && *playerPosition % 7 == 0){
			winGrandPrize(playerPrizes, prizeCount);
		}
		else if (*playerPosition % 3 == 0 && *playerPosition % 5 == 0){
			loseItem(playerPrizes, prizeCount);
		}
		else if (*playerPosition % 3 == 0){
			winPrize(playerPrizes, prizeCount);
		}
		else if (*playerPosition % 5 == 0){
			loseItem(playerPrizes, prizeCount);
		}
		else if (*playerPosition % 7 == 0){
			winGrandPrize(playerPrizes, prizeCount);
		}
		else{
			printf("nothing happens, go again.\n");
		}
	} while (playerPosition != 0);
}

void displayBoard(unsigned int size, char playerName, unsigned int playerPosition){

	int i, j, k, S, n;
	char c;
	S = 4 * size - 5;                              // tiles are counted in a clockwise order starting from the top left
	n = size;
	// Printing for Only size 1
	if (size == 1){
		for (i = 0; i < size; i++){

			printf(" ___ ");
		}
		printf("\n");
		for (i = 0; i < size; i++){

			c = getTileType(i, playerName, playerPosition);

			printf("| %c |", c);
		}
		printf("\n");

		for (i = 0; i < size; i++){

			printf("|___|");

		}
		printf("\n");
	}
	// Printing for  any size

	else if (size > 1){
		for (i = 0; i < size; i++){

			printf(" ___ ");
		}
		printf("\n");
		for (i = 0; i < size; i++){                        // printing first row

			c = getTileType(i, playerName, playerPosition);

			printf("| %c |", c);
		}
		printf("\n");

		for (i = 0; i < size; i++){

			printf("|___|");

		}
		printf("\n");

		for (k = 1; k <= size - 2; k++){

			for (j = 1; j <= size; j++){
				if ((j == 1) || (j == (size))){            // Printing two Column

					printf(" ___ ");
				}
				else{

					printf("     ");
				}
			}
			printf("\n");

			c = getTileType(S, playerName, playerPosition);

			printf("| %c |", c);

			for (j = 1; j <= size - 2; j++){

				printf("     ");
			}

			c = getTileType(n, playerName, playerPosition);

			printf("| %c |", c);

			printf("\n");
			for (i = 1; i <= size; i++){

				if ((i == 1) || (i == (size))){

					printf("|___|");
				}
				else
				{
					printf("     ");
				}
			}

			S = S - 1;                                  // Decrising S by 1 and Incresing tile numer by 1
			n = n + 1;

			printf("\n");
		}

		for (i = 0; i < size; i++){

			printf(" ___ ");

		}
		printf("\n");                                     // Printing last row

		for (i = 0; i < size; i++){

			c = getTileType(S, playerName, playerPosition);

			printf("| %c |", c);

			S = S - 1;

		}
		printf("\n");

		for (i = 0; i < size; i++){

			printf("|___|");

		}printf("\n");
	}

}


                 //Assign Player's ID into Player's current Position

char getTileType(unsigned int index, char	playerName, unsigned int playerPosition){
	int i = index;
	char res;
	if (playerPosition == 0 && i == 0){
		res = playerName;
	}
	else if (playerPosition == i && i % 7 == 0){
		res = playerName;
	}
	else if (playerPosition == i && i % 5 == 0){
		res = playerName;
	}
	else if (playerPosition == i && i % 3 == 0){
		res = playerName;
	}
	else if (i == 0){
		res = 'C';
	}
	else if (i % 3 == 0)
	{
		res = 'W';
		if (playerPosition == i && i % 7 == 0){
			res = playerName;
		}
		else if (i % 7 == 0)
		{
			res = 'G';
		}
		else if (playerPosition == i && i % 5 == 0){
			res = playerName;
		}
		else if (i % 5 == 0)
		{
			res = 'L';
		}
	}
	else if (i % 7 == 0)
	{
		res = 'G';

	}
	else if (i % 5 == 0)
	{
		res = 'L';

	}
	else {
		if (playerPosition == i){
			res = playerName;
		}
		else{
			res = '   ';
		}
	}
	return res;
}

                               //Dice roll

unsigned int playerRoll(){
	int diceRoll, i, total, d1 = 0, d2 = 0, d3 = 0;
	printf("\nyour turn, how many dice will you roll? ");
	diceRoll = getValidItenger(1, 3);
	srand(time(NULL));
	if (diceRoll == 1){
		int d1 = getRandom(1, 6);
		printf("You rolled: %d", d1);
		total = d1;
	}
	else if (diceRoll == 2){
		int d1 = getRandom(1, 6);
		int d2 = getRandom(1, 6);
		printf("You rolled: %d %d", d1, d2);
		total = d1 + d2;
	}
	else if (diceRoll == 3){
		int d1 = getRandom(1, 6);
		int d2 = getRandom(1, 6);
		int d3 = getRandom(1, 6);

		printf("You rolled: %d %d %d", d1, d2, d3);
		total = d1 + d2 + d3;
	}
	return total;
}

//Generate Random num for Dice and prizes

int getRandom(int low, int high){
	int num;
	num = rand() % high + low;
	if (num > high)
		getRandom(low, high);
	else
		return num;
}

//Calculating Win prize

void winPrize(int playerPrizes[], unsigned int* prizeCount){
	int num, i;
	srand(time(NULL));
	num = getRandom(10, 100);
    printf("you won a prize of %d\n", num);
	*prizeCount = *prizeCount + 1;

	for (i = 0; i < 10; i++)
	{
		if (playerPrizes[i] <= 0){
			playerPrizes[i] = num;
			break;
		}
	}
}

                     //Calculating  Grand Win prize

void winGrandPrize(int playerPrizes[], unsigned int* prizeCount){
	int num, i;
	srand(time(NULL));
	num = getRandom(100, 200);

	printf("you won a grand prize of %d\n", num);
	*prizeCount = *prizeCount + 1;
	for (i = 0; i < 10; i++)
	{
		if (playerPrizes[i] <= 0){
			playerPrizes[i] = num;
			break;
		}
	}

}
                     //Calculating Lose prize

int loseItem(int playerPrizes[], unsigned int* prizeCount){
	int i;
	int n = rand() % 1;
	if (playerPrizes[n] > 0){
		printf("Player lost a prize valued at %d\n", playerPrizes[n]);
		playerPrizes[n] = playerPrizes[n - 1];
	}
	*prizeCount = *prizeCount - 1;
}
                     //Total Score
int checkout(int* playerScore, int playerPrizes[], unsigned int* prizeCount){
	int i, score = 0;
	for (i = 0; i < 10; i++) {
		if (playerPrizes[i]>0){
			score += playerPrizes[i];
		}
	}
	*playerScore = score;
	printf("You checkedout for $%d Score is now: $%d\n", score, *playerScore);
	return *playerScore;
}