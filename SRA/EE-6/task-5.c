/* *Task#5
   Now, we want to add the Last name of all people in the file. Ask the names and save them together 
   with the already existing data in a new file. Print the list of data:
 * Author: Yepuri Siddu
 * Created: 8 May, 2024
 * Modified: 8 May, 2024
 * */

/* *REQUIRED HEADER FILES*/
#include <stdio.h>
#include <string.h>

/* *MACRO DEFINITIONS */
#define SIZE 100

// Define a structure to represent a person's record
struct record {
    char name[SIZE]; // name of the person
    int age; // age of the person
    int salary; // salary of the person
};

int main() {
    char lastname[SIZE]; // Declare a variable to store the last name of a person
    struct record person; // Declare a variable to store information about a person
    FILE *fp1 = fopen("peoples.txt", "r"); // Open input file for reading
    FILE *fp2 = fopen("newfile.txt", "a+"); // Open output file for appending and reading

    // Check if file opening failed
    if (fp1 == NULL || fp2 == NULL) {
        printf("Failed to open file\n");
        return 0;
    }

    // Read person's information from input file and append it to output file
    while (fscanf(fp1, "Name:%s age:%d salary:%d\n", person.name, &person.age, &person.salary) != EOF) {
        printf("Enter the last name of %s: ", person.name);
        scanf(" %s", lastname);
        fprintf(fp2, "Name:%s last name:%s age:%d salary:%d\n", person.name, lastname, person.age, person.salary);
    }

    // Move file pointer to the beginning of the output file
    int ret = fseek(fp2, 0, SEEK_SET);
    if (ret != -1) {
        // Read and print person's information from the output file
        while (fscanf(fp2, "Name:%s last name:%s age:%d salary:%d\n", person.name, lastname, &person.age, &person.salary) != EOF) {
            printf("Name: %s\nLast name: %s\nAge: %d\nSalary: %d\n\n", person.name, lastname, person.age, person.salary);
        }
    }

    fclose(fp1); // Close input file
    fclose(fp2); // Close output file

    return 0; // Return success
}
