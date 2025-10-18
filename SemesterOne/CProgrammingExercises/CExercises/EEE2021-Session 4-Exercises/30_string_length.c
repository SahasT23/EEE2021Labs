#include <stdio.h>

int main(void)
{
    char str[100]; /* Declares a string of size 100 */
    int l=0;
	
       printf("\n\nFind the length of a string :\n");
       printf("---------------------------------\n"); 	
       printf("Input the string : ");
       scanf("%s", str); 
    while(str[l]!='\0')
    {
        l++;
    }
    printf("Length of the string is : %d\n\n", l);
    return 0; 
}