/*Example of useing switch...case statement*/ 
#include <stdio.h>

int main(void)
{
	char c = getchar(); // c here is just the name of the variable
                        // you can change it with another name 	
    switch(c)
    {
        case 'Y': printf(    "Yes\n"); break;
        case 'N': printf(     "No\n"); break;
        case 'M': printf(  "Maybe\n"); break;
        default : printf("Unknown\n");
    }
    return 0;
}