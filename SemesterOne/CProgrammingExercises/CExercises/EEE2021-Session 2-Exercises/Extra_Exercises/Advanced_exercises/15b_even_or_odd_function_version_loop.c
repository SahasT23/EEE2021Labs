/* Enter an integer and print if is even or odd*/
#include <stdio.h>

void MyEvenOdd(int a); 

int main(void){
	
	char car = 'y'; 
	
	do{
		int x;
		printf("Enter an integer: ");
		scanf("%d", &x);	
		
		MyEvenOdd(x);
		printf("Do you want to repeat: y|n: ");
		scanf(" %c", &car);		
	}while(car == 'y'); 
	
	printf("Game Over!!!\n");
	return 0;
}

void MyEvenOdd(int a){	
	int y = a%2;
	if(y==0) printf("The number is even\n");  
	if(y!=0) printf("The number is odd\n");
}  