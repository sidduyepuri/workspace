/*Task#2:
  Write a program with command line arguments that calculates the iage (in number of years) of a 
  number of people based upon their date of birth and the current date.
  - make a text file containing a number of names with their corsresponding dates of birth. Make sure 
  names and dates of birth are always written in the same way in the text file.
  - write a function “read_person” to read the data of 1 person from the file and save that data into a 
  struct of the type “Person”. This struct contains a name field and a field to save the date of birth,
  which is a struct of the type “Date”.
  - call the program from the command line with the current date and the text file as arguments
  - write a function “calculate” that calculates the iage of a person in years, months and days. This 
  function also determines which person is the oldest and which person has the longest name.
  - printing the iages is done in the main function. Print also the names of the oldest person and of the 
  person with the longest name.
 * */
/*
 * Author: Yepuri Siddu
 * Created: 8 May, 2024
 * Modified: 8 May, 2024
 * */

/* REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MACRO DEFINITIONS */
#define SIZE 100

// Define a structure to represent a person's date of birth
struct DateOfBirth {
	int d, m, y; // day, month, year
};

// Define a structure to represent a person
struct Person {
	char name[50]; // name of the person
	struct DateOfBirth dob; // date of birth of the person
};

// Function prototypes
int read_person(struct Person *sper2, FILE *fp);
int calculate(struct Person *sper1, struct Person sper2, struct Person *sres, char *argv[]);

/* MAIN PROGRAM
 * Main: Opening file passed in command line argument and
 * reading the name and DOB from file by calling read_person() function and
 * calucates iage ,compasres DOB and length of the name by calling calucate() funtion
 * The sresult is printed in main() function
 * */

int main(int argc, char *argv[])
{
	int iage, iret = 0, count = 0;
	FILE *fp = fopen(argv[1], "r"); // Open file for reading
	if (fp == NULL) {
		printf("File open failed\n");
		return 0;
	}
	struct Person sper1, sper2, sres;

	// Read each person's information from the file until the end
	while (1) {
		iret = read_person(&sper2, fp); // Read a person's information
		if(iret==-1)
			break; //break the loop if EOF
		iage = calculate(&sper1, sper2, &sres, argv); // Calculate age of the person
		printf("%s is %d years old\n", sper2.name, iage); // Print person's age
		count++; // Increment the count of persons
	}

	printf("%s is the oldest of the %d persons in the file\n", sper1.name, count); // Print the oldest person's name
	printf("The person with the longest name is: %s\n", sres.name); // Print the person with the longest name
	fclose(fp); // Close the file
	return 0;
}

/* *
 * read_person(): Function to read a person's information from a file
 * Author: Yepuri Siddu
 * Created: 8 May, 2024
 * Modified: 8 May, 2024
 * */
int read_person(struct Person *sper2, FILE *fp) {
	static int i = 1;
	// Read name and date of birth from file
	if (fscanf(fp, "%s\t%d-%d-%d\n", sper2->name, &sper2->dob.d, &sper2->dob.m, &sper2->dob.y) == EOF)
		return -1; // Return -1 if end of file is reached
	return 0; // Return 0 if successful
}
/* *
 * read_person(): Function to calculate age and find the oldest person
 * Author: Yepuri Siddu
 * Created: 8 May, 2024
 * Modified: 8 May, 2024
 * */
int calculate(struct Person *sper1, struct Person sper2, struct Person *sres, char *argv[]) {
	static int i = 1;
	int sln1, sln2;

	// If it's the first person encountered, initialize the oldest person and person with longest name
	if (i == 1) 
	{
		*sper1 = sper2;
		*sres = sper2;
		i++;
	}
       	else 
	{
		sln1 = strlen(sres->name); // Length of the name of the person with the longest name
		sln2 = strlen(sper2.name); // Length of the name of the current person

		// Update the person with the longest name if the current person's name is longer
		if (sln2 > sln1)
			*sres = sper2;

		// Update the oldest person based on date of birth
		if ((sper1->dob.y) < (sper2.dob.y))
			*sper1 = *sper1;
		else if ((sper1->dob.y) > (sper2.dob.y))
			*sper1 = sper2;
		else if ((sper1->dob.m) < (sper2.dob.m))
			*sper1 = *sper1;
		else if ((sper1->dob.m) > (sper2.dob.m))
			*sper1 = sper2;
		else if ((sper1->dob.d) < (sper2.dob.d))
			*sper1 = *sper1;
		else if ((sper1->dob.d) > (sper2.dob.d))
			*sper1 = sper2;
	}

	// Calculate and return the age of the current person
	return atoi(argv[4]) - sper2.dob.y;
}

