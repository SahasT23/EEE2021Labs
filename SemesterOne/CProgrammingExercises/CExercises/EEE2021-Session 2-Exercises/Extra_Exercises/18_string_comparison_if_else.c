/*Strings comparison*/ 
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[50], s2[50];
    scanf("%s %s", s1, s2);
    int result = strcmp(s1, s2);
    if (result == 0) printf("Equal\n"); else
    {
        if (result < 0) printf("Lower\n"); else printf("Greater\n");
    }
    return 0;
}