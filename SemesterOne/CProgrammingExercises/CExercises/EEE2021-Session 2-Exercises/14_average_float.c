/* Given two float numbers, calculate their average */
#include <stdio.h>

int main(){
	float num1, num2;
	float avg;
	
	printf("Enter first float number: ");
	scanf("%f",&num1);
	
	printf("Enter second float number: ");
	scanf("%f",&num2);
	
	avg= (num1+num2)/2; 

	printf("Average of %f and %f is: %f",num1, num2, avg);
	return 0;
}