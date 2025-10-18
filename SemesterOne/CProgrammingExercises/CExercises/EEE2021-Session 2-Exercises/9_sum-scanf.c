/*Print the sum of two int numbers a, b*/ 

#include <stdio.h>

int main(void){
	int a;
	int b; 
	int c;
	
	printf("Enter 2 int values:\n");	
	scanf("%d", &a); 
	scanf("%d", &b); 
	
	c=a+b; 
	
	printf("The sum of %d and %d is %d.\n", a, b, c);
	return 0;
}

