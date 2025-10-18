/* Pointers*/ 
#include <stdio.h>

int main(void)
{
	int vet[5] = {10, 20, 30, 40, 50};
	int *pi = vet; //vet its equal to &vet[0] 
	int offset = 2;

	*(pi + offset) = 80;
	
	for(int i=0; i<5; i++) printf("%d\n", vet[i]); 
	return 0; 
}