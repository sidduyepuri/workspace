/* *
 * In a circular linked list, the next pointer of the last node points to the starting
 node of the list* Author: Yepuri Siddu
 * Created: 13 May, 2024
 * Modified: 13 May, 2024. Write a recursive C function that prints the elements of a circular
 linked list of integers in the reverse order (that is, from end to beginning).
 Use the following function prototype:
 void printCList ( clist l, const clist h );
 Here the second parameter points to the beginning of the list and is kept constant
 across the calls. Assume that no dummy header node is used in the circular linked list.

 * Author: Yepuri Siddu
 * Created: 13 May, 2024
 * Modified: 13 May, 2024
 * */

/* *REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>

// Define structure for circular linked list
typedef struct circular_list
{
    int num;
    struct circular_list *next;
} clist;

// Function prototypes
void create_list(clist **head, clist **last);
void printClist(clist *last, const clist *head);
void printlist(clist *head);

/* Main program */
int main()
{
    clist *head = NULL, *last = NULL;
    int choice;
    
    // Infinite loop for user interaction
    while (1)
    {
        printf("Options:\n1.create list.\n2.print list reverse order.\n3.Print list\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                create_list(&head, &last);
                break;
            case 2:
                printClist(last, head);
                break;
            case 3:
                printlist(head);
                break;
            default:
                printf("Choose correct option...\n");
                break;
        }
    }
}

/*
 * printClist(): Function to print circular list in reverse order
 * Author: Yepuri Siddu
 * Created: 13 May, 2024
 * Modified: 13 May, 2024
 */
void printClist(clist *last, const clist *head)
{
    // Move to the next node in the circular list
    last = last->next;
    
    // Recursive call until last node is reached
    while (last->next != head)
    {
        printClist(last, head);
        break;
    }
    
    // Print the number in the current node
    printf(" %d\n", last->num);
}

/*
 * printlist(): Function to print circular list
 * Author: Yepuri Siddu
 * Created: 13 May, 2024
 * Modified: 13 May, 2024
 */
void printlist(clist *head)
{
    clist *temp = head;
    
    // Traverse the circular list and print each node's number
    while (temp->next != head)
    {
        printf("%d\n", temp->num);
        temp = temp->next;
    }
    printf("%d\n", temp->num);
}

/*
 * create_list(): Function to create circular list
 * Author: Yepuri Siddu
 * Created: 13 May, 2024
 * Modified: 13 May, 2024
 */
void create_list(clist **head, clist **last)
{
    clist *new = NULL;
    char ch = 'y';
    
    // Loop to add nodes to the circular list
    while (ch == 'y')
    {
        // Allocate memory for new node
        new = (clist *)malloc(sizeof(clist));
        printf("Enter number: ");
        scanf("%d", &new->num);
        
        // If it's the first node, update head
        if (*head == NULL)
            *head = new;
        else
            (*last)->next = new;
        
        // Update last node and make the list circular
        *last = new;
        new->next = *head;
        
        // Prompt user to create one more node
        printf("If you want to create one more node (y/n)? ");
        scanf(" %c", &ch);
    }
}

