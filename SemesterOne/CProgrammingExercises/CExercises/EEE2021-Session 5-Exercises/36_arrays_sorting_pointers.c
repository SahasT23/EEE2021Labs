/*Array Sorting*/
#include <stdio.h>

#define MAX 6

//Function declaration
void selectionSort(int *a, int size); 

int main(void) 
{
  int a[MAX]={23, 37, 32, 45, 12, 89}; 
 
  selectionSort(a, MAX); // a coincides with the address of the first element &a[0]  
  
  for(int i=0; i< MAX; i++){
    printf("%d\n", a[i]);
  }
  return 0;
}

//Function body
void selectionSort(int *a, int size)
{
    for(int i = 0; i < size; i++)
    {
        int k = i;
        for(int j = i + 1; j < size; j++) if (a[j] < a[k]) k = j;
        int tmp = a[i];
        a[i] = a[k];
        a[k] = tmp;
    }
}