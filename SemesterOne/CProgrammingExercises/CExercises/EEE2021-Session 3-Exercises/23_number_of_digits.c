/* This program tells the number of digits of an integer*/ 
#include <stdio.h>

//Function declaration
int numberOfDigits(int my_x);

int main(void) 
{

  int x = 1237;
  int result;

  result = numberOfDigits(x);
  printf("The number of digit is: %d\n",result);
  return 0;
}

//Function body
int numberOfDigits(int my_x)
{
  // Base case
  if (my_x < 10) return 1;
  // Recursive case
  return numberOfDigits(my_x / 10) + 1;
}