/* Task#4
   Searches the age and wages of a person based upon a name entered by the user
 * Author: Yepuri Siddu
 * Created: 8 May, 2024
 * Modified: 8 May, 2024
 * */

/* *REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>

/* *MACRO DEFITIONS */
#define SIZE 100

// Define a structure to represent a person's record
struct record 
{
    char name[SIZE]; // name of the person
    int age; // age of the person
    int salary; // salary of the person
};

int main() 
{
    char man[SIZE]; // Declare a variable to store the name of the person to search for
    struct record person; // Declare a variable to store information about a person
    FILE *fp = fopen("peoples.txt", "r"); // Open file for reading

    // Check if file opening failed
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 0;
    }

    // Input the name of the person to search for
    printf("What’s the name of the person you want to search for? ");
    scanf(" %s", man);

    // Search for the person in the file
    while (fscanf(fp, "Name:%s age:%d salary:%d\n", person.name, &person.age, &person.salary) != EOF) {
        if (strcmp(person.name, man) == 0) { // Check if the name matches
            printf("Name: %s\nAge: %d\nSalary: %d\n", person.name, person.age, person.salary); // Print person's information
            fclose(fp); // Close the file
            return 0; // Exit the program
        }
    }

    // If the person is not found, print a message
    printf("The person you are searching for is not found in the data.\n");

    fclose(fp); // Close the file

    return 0; // Return success
}

