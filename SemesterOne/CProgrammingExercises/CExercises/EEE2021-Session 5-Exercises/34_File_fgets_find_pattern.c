/* Check if there is the same pattern in the file and print the line */  
#include <stdio.h>
#include <string.h>

#define MAX 200 // We checked that this is enough

int main(void)
{
    // Open the file containing the module catalogue
    FILE *f = fopen("modules.txt", "r");
    if (f == NULL) { printf("Error: cannot open file\n"); return 1; }
    
	char line[MAX], pattern[MAX];
    // Enter a pattern to search for
    printf("Enter your pattern:\n");
	scanf("%s", pattern);
    int n = strlen(pattern);
	int count = 1; 
    // Process each line
    while(fgets(line, MAX, f))
    {
        // Match the pattern with the beginning of current line
        int match = 1;
        for(int i = 0; i < n; i++) if (line[i] != pattern[i]) {
			match = 0;
		}
        if (match) printf("Found in line %d: %s", count, line);
		count++;
    }
    fclose(f);
    return 0;
}