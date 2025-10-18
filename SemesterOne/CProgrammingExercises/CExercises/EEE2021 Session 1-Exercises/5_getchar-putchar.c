/*Print a sigle character entered from the keyboard */ 

#include <stdio.h>

// Define the char variable 
char c;

int main()
{
 
	c = getchar(); 
	printf("Character entered: ");
    putchar(c);
    putchar('\n');

	return 0;
}
