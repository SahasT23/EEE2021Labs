/* Enter an integer and print if is even or odd*/
#include <stdio.h>

int main(void){
	int x, y;
	printf("Enter an integer:\n");
	scanf("%d", &x);
	y= x%2;
	
	if(y==0) printf("The number is even\n");
	if(y!=0) printf("The number is odd\n");
	return 0;
}