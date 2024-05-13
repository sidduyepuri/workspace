/* *Task #1 
   Write a program that asks the user to enter the name and the home town of 3 persons. Name and 
   home town are stored in a structure Person. The 3 persons are stored in an array. Afterwards, the 
   program asks the user to enter a name and searches the town that person lives in.
   Use the functions readPerson and searchTown
   The function searchTown has 2 arguments:
   - the array that needs to be searched
   - a variable of the type Person that contains the name that needs to be searched. The town member 
   of that variable needs to be filled with the town found by the function searchTown.
   Reading the name of the person you want to search for is done in the main function. Printing the 
   resulting town can also be done in the main function. If the name entered is not present in the array, 
   an appropriate message needs to be printed.

  * Author: Yepuri Siddu
  * Created: 7-may-2024
  * Modified: 7-may-2024
  * */

/* *REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>

/* *MACRO DEFINITIONS */
#define SIZE 100
#define PERSONS 3

// Define a structure to represent a person
struct Person {
	char name[SIZE]; // name of the person
	char town[SIZE]; // town or city where the person lives
};

// Function prototypes
char* readPerson(void);
int searchTown(struct Person persons[], char person[]);

/* *MAIN PROGRAM 
 * main(): program that asks the user to enter the name and the home town of 3 persons. Name and
   home town are stored in a structure Person. The 3 persons are stored in an array. Afterwards, the
   program asks the user to enter a name and searches the town that person lives in.
   By using the functions readPerson() and searchTown()
 * */

int main() 
{
	int i;
	char *per; // Pointer to store the name of the person to search for
	struct Person persons[PERSONS]; // Array to store information about 3 persons

	// Input information about each person
	for (i = 0; i < PERSONS; i++) {
		printf("Enter name: ");
		scanf("%s", persons[i].name);
		printf("Enter town or city: ");
		scanf("%s", persons[i].town);
	}

	per = readPerson(); // Get the name of the person to search for
	i = searchTown(persons, per); // Search for the person in the list

	// Print the town or city where the person lives, if found
	if (i != -1)
		printf("This person lives in: %s\n", persons[i].town);
	else
		printf("This person's details were not found in the list.\n");

	return 0;
}
/* *
 * readPerson(): Function to read the name of the person to search for
 * Author: Yepuri Siddu
 * Created: 7-may-2024
 * Modified: 7-may-2024
 * */
char* readPerson(void) {
	static char name[50]; // Static array to store the name of the person
	printf("Enter the name of the person you want to search for: ");
	scanf("%s", name);
	return name; // Return the name of the person
}

/* *
 * readPerson():  Function to search for a person's details by name 
 * Author: Yepuri Siddu
 * Created: 7-may-2024
 * Modified: 7-may-2024
 * */
int searchTown(struct Person persons[], char per[]) {
	int i = 0;
	for (; i < 3; i++) {
		// Compare the given name with each person's name in the list
		if (strcmp(persons[i].name, per) == 0)
			return i; // Return the index of the person if found
	}
	return -1; // Return -1 if the person is not found in the list
}

