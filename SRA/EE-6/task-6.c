/* Task#6
   Add each Person also street, number, postal code and state information in file
 * Author: Yepuri Siddu
 * Created: 8 May, 2024
 * Modified: 8 May, 2024
 * */

/* *REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>

/* *MACRO DEFINITIONS */
#define SIZE 100

// Define a structure to represent a person's record including address details
struct record {
    char name[SIZE];
    char lastname[SIZE];
    int age;
    int salary;
    int street;
    long int number;
    int postcode;
    char state[SIZE];
};

int main() {
    int n, i;
    struct record person;
    FILE *fp1 = fopen("newfile.txt", "r+"); // Open input file for reading and writing
    FILE *fp2 = fopen("updatefile.txt", "w+"); // Open output file for reading and writing

    // Check if file opening failed
    if (fp1 == NULL || fp2 == NULL) {
        printf("Failed to open file\n");
        return 0;
    }

    // Read person's information from input file and update with address details
    while (fscanf(fp1, "Name:%s last name:%s age:%d salary:%d\n", person.name, person.lastname, &person.age, &person.salary) != EOF) {
        printf("Enter %s's details:\n", person.name);
        printf("Enter street number: ");
        scanf("%d", &person.street);
        printf("Enter mobile number: ");
        scanf("%ld", &person.number);
        printf("Enter postal code: ");
        scanf("%d", &person.postcode);
        printf("Enter state: ");
        scanf("%s", person.state);
        
        // Write updated person's information including address details to output file
        fprintf(fp2, "Name:%s last name:%s age:%d salary:%d\nAddress:\nstreet:%d  number:%ld postal code:%d state:%s\n", 
                person.name, person.lastname, person.age, person.salary, person.street, person.number, person.postcode, person.state);
    }

    // Reset file pointer to the beginning of the output file
    fseek(fp2, 0, SEEK_SET);

    // Read and print updated person's information from the output file
    while (fscanf(fp2, "Name:%s last name:%s age:%d salary:%d\nAddress:\nstreet:%d number:%ld postal code:%d state:%s\n", 
                  person.name, person.lastname, &person.age, &person.salary, &person.street, &person.number, &person.postcode, person.state) != EOF) {
        printf("Name: %s %s\nAge: %d\nSalary: %d\nAddress:\nStreet: %d\nNumber: %ld\nPostal code: %d\nState: %s\n\n", 
                person.name, person.lastname, person.age, person.salary, person.street, person.number, person.postcode, person.state);
    }

    fclose(fp1); // Close input file
    fclose(fp2); // Close output file

    return 0; // Return success
}

