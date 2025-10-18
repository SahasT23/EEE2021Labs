/*Copy Semantics*/
#include <stdio.h>

//Function declaration
void swap(int *my_a, int *my_b); 

int main(void) 
{
  int a = 10; 
  int b = 56; 
 
  swap(&a, &b); 
  
  printf("a = %d and b = %d\n", a, b); 
  
  return 0;
}

//Function body
void swap(int *my_a, int *my_b)
{
	int temp;
	
	temp = *my_a;
	*my_a = *my_b;
	*my_b = temp; 
	return; 
}