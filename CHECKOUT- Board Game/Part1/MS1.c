/*I declare that the attached assignment is wholly my own work in accordance with
Seneca Academic Policy. No part of this assignment has been copied manually or
electronically from any other source (including web sites) or distributed to
other students.
Name _______Manali Amin_________________ Student ID _____119679157____________
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char getTileType(unsigned int index){
	int i = index;
	char res;
	if (i == 0){ 
       res = 'C';
	}
	else if (i % 3 == 0)
	{
		res = 'W';

	if (i % 7 == 0)
	{
		res = 'G';
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
		 res = '   ';
	 }
	return res;
}
void displayBoard(unsigned int size){

	int i, j, k, S, n;
	char c;


	S = 4 * size - 5;                              // tiles are counted in a clockwise order starting from the top left
	n = size;

	// Printing for Only size 1
	if (size==1){
	for (i = 0; i < size; i++){

		printf(" ___ ");
	}
	printf("\n");
	for (i = 0; i < size; i++){

		c = getTileType(i);

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

			c = getTileType(i);

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

			c = getTileType(S);

			printf("| %c |", c);

			for (j = 1; j <= size - 2; j++){

				printf("     ");
			}

			c = getTileType(n);

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

			c = getTileType(S);

			printf("| %c |", c);

			S = S - 1;

		}
		printf("\n");

		for (i = 0; i < size; i++){

			printf("|___|");

		}printf("\n");
	}
}
	

int main() {
	int s = 1;
	printf("---Program starts---\n");
	// checking Tile condition 

	if (getTileType(153) != 'W') printf("153 should return W");
	else if (getTileType(65) != 'L') printf("65 should return L");
	else if (getTileType(49) != 'G') printf("49 should return G");
	else if (getTileType(0) != 'C') printf("0 should return C");
	else if (getTileType(105) != 'G') printf("105 should be G");
	else if (getTileType(79) != ' ') printf("79 should be space");
	else {
		printf("getTileType test passed!\nEnter board size: ");
		scanf_s("%d", &s);
		displayBoard(s);                                                                 // Calling displayBoard function
		printf("---End Program---\n");
	}
                                                   
	return 0;
}