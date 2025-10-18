/* This program tells which value is the maximum between three integers entered by user*/ 
#include <stdio.h>

//My functions declaration
//You need to declare functions before writing their body (see below)
int max(int my_a, int my_b);
int max3(int my_a, int my_b, int my_c);

int main(void) {
  int a = 10;
  int b = 20;
  int c = 30;
  int result;

  result = max3(a, b, c);

  printf("The max is: %d\n", result);
  return 0;
}

//Functions body
int max(int my_a, int my_b)
{
  if (my_a > my_b) return my_a;
  return my_b;
}

int max3(int my_a, int my_b, int my_c)
{
  return max(my_a, max(my_b, my_c));
}
