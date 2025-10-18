/*Calculate the sum on the integers contained in a file*/ 
#include <stdio.h>

int main(void)
{
	FILE *f = fopen("numbers.txt", "r");
	
	int a, sum = 0;
	
	while(fscanf(f,"%d", &a) == 1) sum = sum + a;
	
	fclose(f);
	printf("%d\n", sum);
	return 0;
}