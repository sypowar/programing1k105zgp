#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isUpper(char letter);
int isLower(char letter);
char encryption(char letter, int key);

int main()
{
	char text;
	char string[10];
	int key;
	printf("Enter string: ");
	gets(string);
	printf("Enter key: ");
	scanf("%d", &key);

	text = string[10];

	int i;
	for (i = 0; i < 50; i++)
	{
		string[i] = encryption(string[i], key);
	}
	printf("\nYour encrypted string: ");
	puts(string);

	return 0;
}

int isUpper(char letter)
{
	int result = 0;
	if (letter >= 'A' && letter <= 'Z')
		result = 1;

	return result;
}

int isLower(char letter)
{
	int result = 0;
	if (letter >= 'a' && letter <= 'z')
		result = 1;

	return result;
}

char encryption(char letter, int key)
{
	if (isUpper(letter))
	{
		letter += key;
		if ((int)letter > 90)
		{
			key = letter - 90;
			letter = 65 + key - 1;
		}
	}
	if (isLower(letter))
	{
		letter += key;
		if ((int)letter > 122)
		{
			key = letter - 122;
			letter = 97 + key - 1;
		}
	}
	return letter;
}
