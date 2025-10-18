/* Enter two integers and print the largest*/
#include <stdio.h>
int main(void){
	int x, y;
	printf("Enter the first integer:\n");
	scanf("%d", &x);
	
	printf("Enter the second integer:\n");
	scanf("%d", &y); 
	
	if(x==y)printf("These numbers are equal.\n");
	if(x>y) printf("%d is the largest.\n", x);
	if(y>x) printf("%d is largest.\n", y);
	
	return 0;
}