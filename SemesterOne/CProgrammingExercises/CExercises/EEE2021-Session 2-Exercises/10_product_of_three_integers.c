/*Print the product of three int numbers x, y, z*/ 

#include <stdio.h>

int main(void){
	int x, y, z;
	int result; 

	printf("Enter three integers:\n");
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
	
	result = x*y*z; 

	printf("The product is %d\n", result);
	return 0;
}
