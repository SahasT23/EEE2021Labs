/*Print first and second digit separately from a two-digit int number */

#include <stdio.h>

int main(void){
	int a, units, tens;
	
	printf("Enter two-digit int number:");
	scanf("%d", &a); // Students can add checking
	                 // on the number, is it really two-digit?
	
	units = (a/1)%10; //Example (34/1)%10=4
	tens=(a/10)%10; //Example (34/10)%10=3
	
	printf("%d and %d \n", tens, units);
	return 0;
}