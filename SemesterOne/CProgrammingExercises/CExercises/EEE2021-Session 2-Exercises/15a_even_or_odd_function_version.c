/* Enter an integer and print if is even or odd*/
#include <stdio.h>

void MyEvenOdd(int a); 

int main(void){
	int x;
	printf("Enter an integer:\n");
	scanf("%d", &x);	
	
	MyEvenOdd(x);	
	return 0;
}

void MyEvenOdd(int a){	
	int y = a%2;
	if(y==0) printf("The number is even\n");  
	if(y!=0) printf("The number is odd\n");
	return; 
}  