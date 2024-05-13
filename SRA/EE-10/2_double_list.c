/* *
 * 2. Implement search function for doubly link list.
 * Author: Yepuri Siddu
 * Created: 13 May, 2024
 * Modified: 13 May, 2024
 * */

/* *REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>

// Define structure for doubly linked list
typedef struct double_list
{
    int num;                    // Data stored in each node
    struct double_list *next;   // Pointer to the next node
    struct double_list *prev;   // Pointer to the previous node
} dlist;

// Function prototypes
void create_list(dlist **head, dlist **last);
void printlist(dlist *head);
int search_element(dlist *head, int num);

/*
 * Main program
 */
int main()
{
    dlist *head = NULL, *last = NULL;   // Head and last pointers for the list
    int choice, ret, num;               // Variables for user input and return value
    
    // Infinite loop for user interaction
    while (1)
    {
        // Display menu options
        printf("Options:\n1. Create list.\n2. Search element.\n3. Print list.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Switch case based on user choice
        switch (choice)
        {
            case 1:
                create_list(&head, &last);  // Create the doubly linked list
                break;
            case 2:
                printf("Enter number to search: ");
                scanf("%d", &num);
                ret = search_element(head, num);    // Search for element in the list
                if (ret == 1)
                    printf(">>>>>>> Element found in doubly linked list\n");
                else
                    printf(">>>>>>> Element not found\n");
                break;
            case 3:
                printlist(head);    // Print the doubly linked list
                break;
            default:
                printf("Choose correct option...\n");
                break;
        }
    }
}

/*
 * Function to search for an element in the doubly linked list
 * Author: Yepuri Siddu
 * Created: 13 May, 2024
 * Modified: 13 May, 2024
 */
int search_element(dlist *head, int num)
{
    dlist *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->num == num)
            return 1;   // Element found
        tmp = tmp->next;
    }
    return 0;   // Element not found
}

/*
 * Function to print the doubly linked list
 * Author: Yepuri Siddu
 * Created: 13 May, 2024
 * Modified: 13 May, 2024
 */
void printlist(dlist *head)
{
    dlist *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->num);
        temp = temp->next;
    }
}

/*
 * Function to create a doubly linked list
 * Author: Yepuri Siddu
 * Created: 13 May, 2024
 * Modified: 13 May, 2024
 */
void create_list(dlist **head, dlist **last)
{
    dlist *new = NULL;  // Pointer to a new node
    char ch = 'y';      // Variable for user choice
    
    // Loop to add nodes to the doubly linked list
    while (ch == 'y')
    {
        new = (dlist *)malloc(sizeof(dlist));    // Allocate memory for a new node
        printf("Enter number: ");
        scanf("%d", &new->num); // Read data for the new node
        
        if (*head == NULL)
        {
            *head = new;    // Set the new node as the head if the list is empty
            (*head)->prev = NULL;   // Update previous pointer of the head to NULL
        }
        else
        {
            new->prev = *last;  // Update previous pointer of the new node
            (*last)->next = new;    // Update next pointer of the last node
        }
        
        *last = new;    // Update last pointer to the new node
        
        printf("If you want to create one more node (y/n)? ");
        scanf(" %c", &ch);  // Prompt user for continuation
    }
}

