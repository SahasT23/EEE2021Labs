/* This program reads a positive integer*/
#include <stdio.h>

//Function declaration
int readPostiveInteger(void);

int main(void) 
{
  int x;
  x = readPostiveInteger();

  printf("The positive integer is: %d\n", x);
  return 0;
}

//Function body
int readPostiveInteger(void)
{ 
  int result;
  while(1){
    scanf("%d", &result);
    if (result > 0) return result;
    printf("Error: the value must be positive, please try again\n");
  }
}