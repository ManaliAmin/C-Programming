#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int wordCount(char string[]);
int main()
{
	FILE *file = NULL;                                                           //File creating
	char text[100], t[100];
	int num = 0, n = 0;
	fopen_s(&file, "stringCount.txt", "w+");                                   //File Opening Inser text and read text
	if (file == NULL)
	{
		printf("File not Found\n");
	}

	else{
		printf("Enter a string:");
		gets_s(text, 100);

		num = wordCount(text);
		fprintf(file, "Word Counter\n");
		fprintf(file, "================\n");
		fprintf(file, "Text to be analyzed : %s\n", text);                   //User Prompt a text of string
		fprintf(file, "Word count          : %d\n", num + 1);

	}

	fclose(file);

	fopen_s(&file, "stringCount.txt", "r");
	if (file == NULL)
	{
		printf("File not Found\n");
	}

	else{
		//For zz

		fscanf(file, "Word Counter");
		fscanf(file, "================");
		fscanf(file, "Text to be analyzed : %s", t);
		fscanf(file, "Word count          : %d", &n);


		printf("Word Counter\n");
		printf("================\n");
		printf("Text to be analyzed : %s\n", text);

		printf("Word count          : %d\n", num+1);

	}
	fclose(file);	
	return 0;
}
int wordCount(char string[]){
	int words = 0;
	for (int j = 0; j < 100; j++){
		if (string[j] == ' ')
			words++;
	}
	return words;

}