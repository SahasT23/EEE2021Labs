/*Print address in variables */
#include <stdio.h>

int main(void)
{
  int var = 5;
  printf("var: %d\n", var);

  // Notice the use of & before var
  //Notice the format specifier 
  printf("address of var: %p", &var);  
  return 0;
}