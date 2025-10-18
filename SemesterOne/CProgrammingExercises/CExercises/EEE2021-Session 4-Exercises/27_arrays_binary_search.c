/* Array binary search*/
#include <stdio.h>

#define MAX 6

//Function declaration
int binarySearch(const int a[], int start, int end, int value);

int main(void) 
{
  int a[MAX]={12, 23, 32, 37, 45, 89}; 
  int value = 32; 
  
  int result;
  result = binarySearch(a, 0 , MAX, value); 

  printf("The index is: %d\n", result);
  return 0;
}

//Function body
int binarySearch(const int a[], int start, int end, int value)
{
    if (start > end) return -1;
    int middle = (start + end) / 2;
    if (a[middle] == value) return middle;
    if (a[middle] > value)
        return binarySearch(a, start, middle - 1, value);
    else
        return binarySearch(a, middle + 1, end, value);
}