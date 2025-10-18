/*This program calculates and prints user’s age*/
#include <stdio.h>

int main(void){
	// Variable Declaration
	// input
	char x[30]; //name of user
	
	int day_of_birth; // day of birth
	int month_of_birth; // month or birth
	int year_of_birth; // year of birth
	int TodaysDay; // current day
	int TodaysMonth; // current month
	int CurrentYear; // current year
	
	//output
	float age = 0;
	
	printf("Enter your name:");
	fgets(x, 30, stdin); // This reads a string until user inputs a new
						// line character, considering the white spaces
						// also as string. Other option: use gets function
						
	printf("Hello, %s \n", x);
	
	printf("Please enter your DOB in the format dd mm yyyy:\n");
	scanf("%d %d %d", &day_of_birth, &month_of_birth, &year_of_birth);
	
	printf("Please enter current date in the format dd mm yyyy:\n");
	scanf("%d %d %d", &TodaysDay, &TodaysMonth, &CurrentYear);
	
	// We consider each month with an average of 30.4 days (≈365/12) to
	// reach 365 days. To avoid using floats we can multiply these values 
	// for 10
	age = ((CurrentYear*365 + TodaysMonth*30.4 + TodaysDay) - (year_of_birth*365 + month_of_birth*30.4 + day_of_birth))/365;
	
	printf("You are %d years old today!\n",(int) age);
	return 0;
}