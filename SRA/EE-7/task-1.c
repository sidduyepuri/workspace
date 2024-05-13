/* *
 * Task#1 :
 Write a program with command line arguments that compares two text files. If the files are identical,
 the program will print an appropriate message. If not, all lines containing differences must be printed
 to the screen with their line numbers. If the files differ in more than 10 lines, the program can stop
 printing after the 10th line.
 Good to have try to redirect the screen output to a text file without changing the source code.
 
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */

/* *REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* *MACRO DEFINITIONS */
#define SIZE 100

/* *MAIN PROGRAM 
 * main(): main program with command line arguments that compares two text files. If the files are identical,
 the program will print an appropriate message. If not, all lines containing differences must be printed
 to the screen with their line numbers. If the files differ in more than 10 lines, the program can stop
 printing after the 10th line.
 * */

int main(int argc, char *argv[]) 
{
    int lc = 0, count = 0, flag = 0, ret1, ret2; // Initialize variables for line count, count of differences, and flag
    char ch1[SIZE], ch2[SIZE]; // Declare character arrays to store lines from files
    FILE *fp1 = fopen(argv[1], "r"); // Open first file for reading
    FILE *fp2 = fopen(argv[2], "r"); // Open second file for reading

    // Check if file opening failed
    if (fp1 == NULL || fp2 == NULL) {
        printf("File open failed\n");
        return 0;
    }

    // Read lines from both files until end of file or 10 differences are found
    while ((fgets(ch1, sizeof(ch1), fp1)) != NULL && (fgets(ch2, sizeof(ch2), fp2)) != NULL) {
        lc++; // Increment line count

        // Compare lines from both files
        if (strcmp(ch1, ch2) != 0) {
            count++; // Increment count of differences
            flag = 1; // Set flag to indicate differences found
            printf("%d. %s%d. %s\n", lc, ch1, lc, ch2); // Print differing lines with line numbers
        }

        // Break the loop if 10 differences are found
        if (count >= 10)
            break;
    }

    // If no differences are found, print a message
    if (flag == 0)
        printf("Two files are identical\n");

    // Close both files
    fclose(fp1);
    fclose(fp2);

    return 0; // Return success
}

