/*Print the corresponding uppercase character*/
#include <stdio.h>

int main(void){
	
	char c; // c here is just the name of the variable 
	
	printf("Enter the character\n");
	scanf("%c", &c);
	
	c = 'A' + (c-'a');
	printf("The corresponding uppercase character is %c", c);
	return 0;
}