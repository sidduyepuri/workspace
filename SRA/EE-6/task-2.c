/* Task #2
 Extend task#1 that further reads name, age and salary of a chosen number of people and stores
 that information into a file. All data of 1 person is stored in a structure. Once the data of 1 person is 2
 read, the structure containing that data is written to a file at once. Afterwards, the data of the next
 person is read, … Make sure the names can contain spaces!
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */

/* *REQUIRED HEADER FILES */
#include <stdio.h>

/* *MACRO DEFINITIONS */
#define SIZE 100

// Define a structure to represent a person's record
struct record {
    char name[SIZE]; // name of the person
    int age; // age of the person
    int salary; // salary of the person
};

int main() {
    int n, i;
    FILE *fp = fopen("peoples.txt", "a+"); // Open file for appending and reading

    // Check if file opening failed
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 0;
    }

    // Input the number of people
    printf("How many people do you want to enter? ");
    scanf("%d", &n);

    // Create an array of 'n' records to store information about 'n' people
    struct record persons[n];

    // Input information about each person and write it to the file
    for (i = 0; i < n; i++) {
        printf("Enter name: ");
        scanf("%s", persons[i].name);
        printf("Enter age: ");
        scanf("%d", &persons[i].age);
        printf("Enter salary: ");
        scanf("%d", &persons[i].salary);

        // Write person's information to the file
        fprintf(fp, "Name: %s\tAge: %d\tSalary: %d\n", persons[i].name, persons[i].age, persons[i].salary);
    }

    fclose(fp); // Close the file

    return 0; // Return success
}

