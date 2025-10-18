/*Calculate circumference and area for a given radius*/
#include <stdio.h>
#define Pi 3.1415926

int main(){
	float rad, ci;
	
	printf("Enter radius of circle:\n");
	scanf("%f", &rad);
	
	ci = 2 * Pi * rad;
	printf("Circumference : %f \n", ci);
	
	// Additional to the exercise: calculate area 
	// ...
	return 0;
}