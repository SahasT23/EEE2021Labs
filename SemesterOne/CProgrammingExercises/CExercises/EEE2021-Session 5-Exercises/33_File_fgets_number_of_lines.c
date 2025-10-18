/* Files: example of using fgets function and calculate the number of lines*/ 

#include <stdio.h>
#include <string.h>
#define MAX 200

int main(void)
{
    FILE *f = fopen("modules.txt", "r");
    if (f == NULL) { printf("Error: cannot open file\n"); return 1; }
	char s[MAX];
    int count = 0;
    
	while(fgets(s, MAX, f))
    {
        if (strlen(s) == MAX - 1 && s[MAX - 2] != '\n')
        {
            printf("Error: buffer overflow\n");
            fclose(f); 
			return 1;
        }
        count++;
    }
	
    printf("Number of lines: %d\n", count);
    fclose(f);
    return 0;
}