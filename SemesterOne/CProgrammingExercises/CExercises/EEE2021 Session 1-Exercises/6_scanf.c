/*Print your name entered from the keyboard */ 

#include <stdio.h>

// Define the string variable 'name'
char name[50];

int main(void)
{
	scanf("%s", name);
	printf("Hello, %s!\n", name);
	return 0;
}