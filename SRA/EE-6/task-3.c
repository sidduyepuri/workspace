/* TASK#4
 * Write a program that reads the data from the file written in the Task#2 . Print the data to the screen 
as follows:
 * Author: Yepuri Siddu
 * Created: 7-may-2024
 * Modified: 7-may-2024
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
    struct record person; // Declare a variable to store information about a person
    FILE *fp = fopen("peoples.txt", "r"); // Open file for reading

    // Check if file opening failed
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 0;
    }

    // Read and print information about each person from the file
    while (fscanf(fp, "Name:%s age:%d salary:%d\n", person.name, &person.age, &person.salary) != EOF) {
        printf("Name: %s\nAge: %d\nSalary: %d\n", person.name, person.age, person.salary);
    }

    fclose(fp); // Close the file

    return 0; // Return success
}

