/*Print your name entered from the keyboard */ 

#include <stdio.h>

// Define the string variable 'name'
char name_1[4];
char name_2[4];

int main()
{
	printf("Enter the first name\n");
	scanf("%s", name_1);
	
	printf("Enter the second name\n");
	scanf("%s", name_2);
	
	printf("Name_1 %s and Name_2: %s!\n", name_1, name_2);
	
	printf("%d\n", &name_1[0]);
    printf("%d\n", &name_1[1]);
    printf("%d\n", &name_1[2]);
    printf("%d\n", &name_1[3]);

    printf("%d\n", &name_2[0]);
    printf("%d\n", &name_2[1]);
    printf("%d\n", &name_2[2]);
    printf("%d\n", &name_2[3]);
	
	return 0;
}
