/*Files: Sum of integers with check and saving sum in a new file*/ 

#include <stdio.h>
int main()
{
	FILE *in = fopen("numbers.txt", "r");
	if (in == NULL) { printf("Error: cannot open file\n"); return 1; }
	
	FILE *out = fopen("sum.txt" , "w");
	
	int a, sum = 0;
	
	while(fscanf(in, "%d", &a) == 1) sum += a;
	fclose(in);
	fprintf(out, "%d\n", sum); 
	fclose(out);
	return 0;
}