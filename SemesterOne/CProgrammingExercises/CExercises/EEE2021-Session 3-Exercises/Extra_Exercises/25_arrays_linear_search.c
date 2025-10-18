/* Array linear search*/
#include <stdio.h>

#define MAX 6

//Function declaration
int linearSearch(const int a[], int size, int value);

int main(void) 
{
  int a[MAX]={32, 45, 23, 37, 12, 89}; 
  int value = 89;
  
  int result;
  result = linearSearch(a,MAX, value);

  printf("The index is: %d\n", result);
  return 0;
}

//Function body
int linearSearch(const int a[], int size, int value)
{
    for(int i = 0; i < size; i++) if (a[i] == value) return i;
    return -1;
}