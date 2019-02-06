#pragma warning(disable:4996)
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BUFFER_SIZE 100

int boundedRand(int maxNum);
void getRandomWord(char startingChar, char buffer[]);

int randSeed = 11;

int main(void) {
	int i;
	FILE *file = fopen("polski.txt", "r");
	char mainWord[BUFFER_SIZE];
	char buffer[BUFFER_SIZE];

	getRandomWord('b', mainWord);
	printf("%s \n\n", mainWord);

	for (i = 0; i < strlen(mainWord) - 1; i++)
	{
		getRandomWord(mainWord[i], buffer);
		printf("%s\n", buffer);
	}

	getchar();
}

void getRandomWord(char startingChar, char buffer[])
{
	int lines = 0;
	int randomLine;
	FILE *file = fopen("polski.txt", "r");
	long offset;

	while (!feof(file))
	{
		fgets(buffer, BUFFER_SIZE, file);
		if (buffer[0] == startingChar)
		{
			offset = ftell(file);
			break;
		}
	}

	while (!feof(file))
	{
		fgets(buffer, BUFFER_SIZE, file);
		if (buffer[0] != startingChar)
		{
			break;
		}
		lines++;
	}

	randomLine = boundedRand(lines);
	fseek(file, offset, 0);

	while (randomLine > 0)
	{
		fgets(buffer, BUFFER_SIZE, file);
		randomLine--;
	}
}

int boundedRand(int maxNum) {
	//srand(randSeed);
	//randSeed++;
	srand(time(NULL));
	return rand() % maxNum;
}