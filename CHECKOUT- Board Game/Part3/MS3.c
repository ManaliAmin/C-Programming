/*I declare that the attached assignment is wholly my own work in accordance with
Seneca Academic Policy. No part of this assignment has been copied manually or
electronically from any other source (including web sites) or distributed to
other students.
Name _______Manali Amin_________________ Student ID _____119679157____________
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include<math.h>
#define TOTAL_AMOUNT 500

struct Player{
	char id;
	int playerPrizes[10], count;   //, playersize
	int inventory, playerPosition, playerScore, prizeCount;
};

void initPlayer(struct Player* player);
int getValidItenger(int low, int high);
char getValidCharacter(char low, char high);
unsigned int playerRoll();
int getRandom(int low, int high);
void playGame(unsigned int boardSize, struct Player players[], unsigned int playerCount);
void displayBoard(unsigned int size, struct Player players[], unsigned int playerCount);
char getTileType(unsigned int index, struct Player players[], unsigned int playerCount);
void winPrize(struct Player* player);
void winGrandPrize(struct Player* player);
int loseItem(struct Player* player);
int checkout(struct Player* player);
int stealPrize(struct Player* player, int i, unsigned int playerCount);

int main(){
	struct Player player[8];
	int  playerCount = 0, score, highScore = 500;
	char userInput, highName = NULL;
	printf("\nWelcome to CHECKOUT\n");
Menu:
	printf("\nMain Menu\n\n");
	printf("p - (p)lay q - (q)uit r - inst(r)uctions s - HI(s)core: ");
	userInput = getValidCharacter('p', 's');
	if (userInput == 'p'){
		int i = 0, boardSize;

		printf("Enter Number of Players:");
		playerCount = getValidItenger(1, 8);
		score = playerCount;
		for (i = 0; i < playerCount; i++){												
			if (player[i].id != NULL){
				initPlayer(&player[i]);
			}
		}

		printf("Enter board size: ");
		boardSize = getValidItenger(5, 15);
		playGame(boardSize, player, playerCount);
		score = checkout(player);
		highScore = score;
		for (i = 0; i<playerCount; ++i)                                                         /* Loop to store largest number to arr[0] */
		{
			if (score<player[i].playerScore)                                                /* Change < to > if you want to find smallest element*/
				score = player[i].playerScore;
			highName = player[i].id;


		}
		printf("%c Won the game!", highName);
		goto Menu;


	}
	else if (userInput == 's'){
		printf("___\n");
		printf("   \\_______\n");
		printf("    \\++++++|\n");
		printf("     \\=====|\n");
		printf("     0---  0\n");
		printf("Score: %d, Player's Name:%c", highScore, highName);
		goto Menu;
	}
	else if (userInput == 'r'){
		printf("                       Game Rules:\n");
		printf("                       ============\n");
		printf("-Up to 8 players compete to be the first to obtain $1000\n");
		printf("- Game takes place on a square board with 5 tile types\n");
		printf("		o Empty Tile � No effect\n");
		printf("		o Win Tile � Win a random prize\n");
		printf("		o Lose Tile � Lose a random prize\n");
		printf("		o Grand Prize Tile � Win a grand prize\n");
		printf("		o Checkout Tile � Sells all your prizes for cash\n");
		printf("- Players can roll 1 - 3 dice to determine how many tiles they move each turn\n");
		printf("- If a player lands on the same tile as another player, that player steals a prize and moves 1 tile back\n ");
		main();
	}

	else if (userInput == 'q'){
		printf("This game is much more fun than bash...");
	}
	else{
		printf("INVALID!");
	}
	return 0;
}

void initPlayer(struct Player*  player)
{
	int i;
	printf("Enter player ID:");
	scanf_s("%c", &player->id);
	while (getchar() != '\n');
	player->playerScore = 0;
	player->prizeCount = 0;
	player->playerPosition = 0;
	for (i = 0; i < 10; i++){
		player->playerPrizes[i] = 0;
	}
}

int getValidItenger(int low, int high){

	int num;
	scanf_s("%d", &num);
	while (getchar() != '\n');
	while ((num < low || num > high)){

		printf("INVALID! Please enter value between %d and %d:\n", low, high);
		scanf_s("%d", &num);
		while (getchar() != '\n');
	}
	return num;
}

char getValidCharacter(char low, char high){

	char cha;
	scanf_s(" %c", &cha);
	while (cha < low || cha > high)
	{
		printf("INVALID! Please enter value between %c and %c:\n", low, high);
		scanf_s(" %c", &cha);
	}

	return cha;
}

unsigned int playerRoll(){
	int diceRoll, i, total, d1 = 0, d2 = 0, d3 = 0;
	printf(", how many dice will you roll? ");
	diceRoll = getValidItenger(1, 3);
	srand(time(NULL));
	if (diceRoll == 1){
		int d1 = getRandom(1, 6);
		printf("You rolled: %d\n", d1);
		total = d1;
	}
	else if (diceRoll == 2){
		int d1 = getRandom(1, 6);
		int d2 = getRandom(1, 6);
		printf("You rolled: %d %d\n", d1, d2);
		total = d1 + d2;
	}
	else if (diceRoll == 3){
		int d1 = getRandom(1, 6);
		int d2 = getRandom(1, 6);
		int d3 = getRandom(1, 6);

		printf("You rolled: %d %d %d\n", d1, d2, d3);
		total = d1 + d2 + d3;
	}
	return total;
}

int getRandom(int low, int high){
	int num;
	num = rand() % high + low;
	if (num > high)
		getRandom(low, high);
	else
		return num;
}

void playGame(unsigned int boardSize, struct Player players[], unsigned int playerCount){

	do{
		int total = 0;
		int i, j, k, r = 1;
		for (i = 0; i < playerCount; i++){
			displayBoard(boardSize, players, playerCount);
			printf("\n%c's Turn ", players[i].id);
			total = playerRoll();
			players[i].playerPosition += total;
			if (players[i].playerPosition >= (4 * boardSize - 4)){
				players[i].playerPosition = players[i].playerPosition - (4 * boardSize - 4);
			}

			stealPrize(players, i, playerCount);


			if (players[i].playerPosition == 0){                                                             //Analizing Prizes

				for (j = 0; j < 10; j++) {
					if (players[i].playerPrizes[j]>10 && players[i].playerPrizes[j]<200){
						players[i].playerScore += players[i].playerPrizes[j];
					}
				}

				if (players[i].playerScore>TOTAL_AMOUNT){
					printf("You checked out for $%d\n", players[i].playerScore);
					return;
				}
				else{
					printf("You checked out for $%d\n", players[i].playerScore);
					continue;
				}
			}


			else if (players[i].playerPosition % 3 == 0 && players[i].playerPosition % 5 == 0 && players[i].playerPosition % 7 == 0){
				players[i].count = i;
				winGrandPrize(players);
				players[i].count = -1;
			}
			else if (players[i].playerPosition % 3 == 0 && players[i].playerPosition % 5 == 0){
				players[i].count = i;
				loseItem(players);
				players[i].count = -1;
			}
			else if (players[i].playerPosition % 3 == 0){
				players[i].count = i;
				winPrize(players);

				players[i].count = -1;
			}
			else if (players[i].playerPosition % 5 == 0){
				players[i].count = i;
				loseItem(players);
				players[i].count = -1;
			}
			else if (players[i].playerPosition % 7 == 0){
				players[i].count = i;
				winGrandPrize(players);

				players[i].count = -1;
			}
			else{
				printf("You do nothing.\n");
			}

		}

	} while (players[0].playerScore<500);
}

void displayBoard(unsigned int size, struct Player players[], unsigned int playerCount){
	int i, j, k, S, n;
	char c;
	S = 4 * size - 5;                                                                 // tiles are counted in a clockwise order starting from the top left
	n = size;
	// Printing for Only size 1
	if (size == 1){
		for (i = 0; i < size; i++){

			printf(" ___ ");
		}
		printf("\n");
		for (i = 0; i < size; i++){

			c = getTileType(i, players, playerCount);

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

			c = getTileType(i, players, playerCount);

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

			c = getTileType(S, players, playerCount);

			printf("| %c |", c);

			for (j = 1; j <= size - 2; j++){

				printf("     ");
			}

			c = getTileType(n, players, playerCount);

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

			c = getTileType(S, players, playerCount);

			printf("| %c |", c);

			S = S - 1;

		}
		printf("\n");

		for (i = 0; i < size; i++){

			printf("|___|");

		}printf("\n");
	}

}

char getTileType(unsigned int index, struct Player players[], unsigned int playerCount){
	int i = index, p, q, r = 1;
	char res;
	for (p = 0; p < playerCount; p++)
	{
		if (players[p].playerPosition == 0 && i == 0){
			res = players[p].id;
			return res;
		}

	}
	for (p = 0; p < playerCount; p++){
		if (players[p].playerPosition == i && i % 7 == 0){
			res = players[p].id;
			return res;
		}
	}
	for (p = 0; p < playerCount; p++){
		if (players[p].playerPosition == i && i % 5 == 0){
			res = players[p].id;
			return res;
		}
	}
	for (p = 0; p < playerCount; p++){
		if (players[p].playerPosition == i && i % 3 == 0){
			res = players[p].id;
			return res;
		}
	}

	if (i == 0){
		res = 'C';
		return res;
	}
	else if (i % 5 == 0){
		res = 'L';
		return res;
	}
	else if (i % 3 == 0){
		res = 'W';
		return res;
		for (p = 0; p < playerCount; p++){
			if (players[p].playerPosition == i && i % 7 == 0){
				res = players[p].id;
				return res;
			}
		}
		if (i % 7 == 0){
			res = 'G';
			return res;
		}
		for (p = 0; p < playerCount; p++){
			if (players[p].playerPosition == i && i % 5 == 0){
				res = players[p].id;
				return res;
			}
		}
		if (i % 5 == 0){
			res = 'L';
			return res;
		}
	}
	else if (i % 7 == 0){
		res = 'G';
		return res;

	}
	
	else {
		for (p = 0; p < playerCount; p++){
			if (players[p].playerPosition == i){
				res = players[p].id;
				return res;
			}
		}
		res = '   ';
		return res;


	}
}

void winPrize(struct Player* player){

	int num, i, j, k;
	for (j = 0; j < 8; j++){
		if (player[j].count >= 0 && player[j].count <= 8){
			k = player[j].count;
        }
	}
	srand(time(NULL));
	num = getRandom(10, 100);
	printf("you won a prize of %d\n", num);
	player[k].prizeCount = player[k].prizeCount + 1;
	for (i = 0; i < 10; i++)
	{
		if (player[k].playerPrizes[i] <= 0){
			player[k].playerPrizes[i] = num;
			break;
		}
	}
}

//Calculating  Grand Win prize

void winGrandPrize(struct Player* player){
	int num, i, j, k;
	for (j = 0; j < 8; j++){
		if (player[j].count >= 0 && player[j].count <= 8){
			k = player[j].count;
		}

	}
	srand(time(NULL));
	num = getRandom(100, 200);
	printf("you won a grand prize of %d\n", num);
	player[k].prizeCount = player[k].prizeCount + 1;
	for (i = 0; i < 10; i++)
	{
		if (player[k].playerPrizes[i] <= 0){
			player[k].playerPrizes[i] = num;
			break;
		}
	}
}
//Calculating Lose prize

int loseItem(struct Player* player){
	int i, j, k;
	for (j = 0; j < 8; j++){
		if (player[j].count >= 0 && player[j].count <= 8){
			k = player[j].count;
		}
	}

	int n = rand() % 1;
	if (player[k].playerPrizes[n] > 0){
		printf("Player lost a prize valued at %d\n", player[k].playerPrizes[n]);
		player[k].playerPrizes[n] = player[k].playerPrizes[n - 1];
	}
	player[k].prizeCount = player[k].prizeCount - 1;

}

//Total Score

int checkout(struct Player* player){
	int i, score = 0, j, k;

	for (i = 0; i<8; ++i)                                                                              /* Loop to store largest number to arr[0] */
	{
		if (score<player[i].playerScore)                                                              /* Change < to > if you want to find smallest element*/
			score = player[i].playerScore;
	}
	return score;
}

int stealPrize(struct Player* player, int i, unsigned int playerCount){
	int j, k, prize = 0;

	for (j = 0; j < playerCount; j++){
		if (i != j && player[j].playerPosition>0){
			if (player[i].playerPosition == player[j].playerPosition){
				player[i].playerPosition--;                                                     //new player's position -1
				if (player[j].prizeCount>0){                     //prizeCount checking that prize is adding into inventory if its not then else part is working 

					printf("You Stole a prize from %c!\n", player[j].id);

					int n = rand() % 1;
					if (player[j].playerPrizes[n] > 0){
						prize = player[j].playerPrizes[n];
						player[j].playerPrizes[n] = player[j].playerPrizes[n - 1];          //take the prize from inventory and add this prize into playerprize[n-1]
					}
					player[j].prizeCount = player[j].prizeCount - 1;
					for (k = 0; k < 10; k++)
					{
						if (player[i].playerPrizes[k] <= 0){
							player[i].playerPrizes[k] = prize;                              //add the stealing prize into new player's prize
							break;
						}
					}
					player[i].prizeCount = player[i].prizeCount + 1;


					/*printf("\n%c player inventory::", player[i].id);                   //This part check if prizeCount is adding into inventory or not
					for (k = 0; k < 10; k++)                                             //for checking playercount please do commentout this part
					{
					printf(" %d",player[i].playerPrizes[k]);

					}*/

				}
				else{
					printf("You were unable to steal from %c!\n", player[j].id);
				}

			}
		}

	}

}
