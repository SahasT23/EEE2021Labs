/*Print your name*/ 

#include <stdio.h>

// Define the string variable 'name'
  char first_name[5] = "Fred"; 
  
  
  char first_name_alt[5] = {'F', 'r', 'e', 'd', '\0'}; 
  //char first_name_alt[5] = {'F', 'r', '\0', 'd', '\0'}; 
  //a null-terminated string is a null character 
  //a null-terminated string is a null character 
  //('\0', called NULL in ASCII).
  // Example: add another character after '\0'. 
  
int main(void)
{
	printf("Hello, %s!\n", first_name);
	printf("Hello, %s!\n", first_name_alt);
	return 0;
}