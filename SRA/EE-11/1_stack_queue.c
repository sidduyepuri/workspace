/*
 * 1. Employees and BreakFast
 At the EIC Cafeteria, n employees are standing in the queue. Today, on the menu, we have
 either a plain dosa or a masala dosa. Each employee has a preference. He/She either want to
 eat a sada dosa or a masala dosa. At the front end of the queue, there is a stack of dosas, a
 mix of sada and masala dosas. A employee at the front of the queue performs the following
 operation
 1. If the employee likes a sada dosa and the top of the stack is a sada dosa, then the
 employee takes the sada dosa and leaves the queue.
 2. If the employee likes a masala dosa and the top of the stack is a masala dosa, then the
 employee takes the masala dosa and leaves the queue.
 3. Else the employee leaves the front of the queue and goes to end of the queue.
 
 * Author: Yepuri Siddu
 * Created: 15 May, 2024
 * Modified: 15 May, 2024
 * */


/* *REQUIRED HEADER FILES*/
#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node in the stack and queue
typedef struct Cafeteria {
    int data;
    struct Cafeteria *next;
} Dosa,Employee;

// Declare global variables for the stack and queue heads and tails
Dosa *shead = NULL, *stail = NULL;
Employee *qhead = NULL, *qtail = NULL;

/*
 * CreateQueue(): Function to create a queue of Employees
 * * Author: Yepuri Siddu
 * Created: 15 May, 2024
 * Modified: 15 May, 2024
 * */
void CreateQueue(int n) {
    Employee *new = NULL;
    int i, val;
    printf("Enter the elements for the queue:\n");
    for (i = 0; i < n; i++) {
        new = (Employee *)malloc(sizeof(Employee));
        new->next = NULL;
        scanf("%d", &val);
        new->data = val;
        if (qhead == NULL) {
            qhead = new;
        } 
	else {
            qtail->next = new;
        }
        qtail = new;
    }
}

/*
 * CreateStack(): Function to create a stack of dosas
 * Author: Yepuri Siddu
 * Created: 15 May, 2024
 * Modified: 15 May, 2024
 * */
void CreateStack(int n) {
    Dosa *new = NULL;
    int i, val;
    printf("Enter the elements for the stack:\n");
    for (i = 0; i < n; i++) {
        new = (Dosa *)malloc(sizeof(Dosa));
        new->next = NULL;
        scanf("%d", &val);
        new->data = val;
        if (shead == NULL) {
            shead = new;
        } else {
            stail->next = new;
        }
        stail = new;
    }
}

/*
 * printStack(): Function to print the elements of the stack
 * Author: Yepuri Siddu
 * Created: 15 May, 2024
 * Modified: 15 May, 2024
 * */
void printStack() {
    Dosa *head = shead;
    printf("Dosa Stack: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to print the elements of the queue
/*
 * printQueue(): Function to print the elements of the queue
 * Author: Yepuri Siddu
 * Created: 15 May, 2024
 * Modified: 15 May, 2024
 * */
void printQueue() {
    Employee *head = qhead;
    printf("Employee Queue: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n\n");
}

/*
 * Pop(): Function to pop an element from the stack
 * Author: Yepuri Siddu
 * Created: 15 May, 2024
 * Modified: 15 May, 2024
 * */
void Pop(void) {
    Dosa *tmp = NULL;
    tmp = shead;
    shead = shead->next;
    free(tmp);
    return;
}

/*
 * DeQueue(): Function to dequeue an element from the queue
 * * Author: Yepuri Siddu
 * Created: 15 May, 2024
 * Modified: 15 May, 2024
 * */
void Dequeue(void) {
    Employee *tmp = NULL;
    tmp = qhead;
    qhead = qhead->next;
    free(tmp);
    return;
}

/*
 * Enqueue():Function to enqueue an element into the queue
 * Author: Yepuri Siddu
 * Created: 15 May, 2024
 * Modified: 15 May, 2024
 * */
void Enqueue(void) {
    Employee *tmp = NULL;
    tmp = qhead;
    qhead = qhead->next;
    tmp->next = NULL;
    qtail->next = tmp;
    qtail = tmp;
    return;
}
/*
 * MAIN FUNCTION
 * main(): Main read no of persons n.
 * creating stack of dosas and queue of Employees by calling createStack() and createQueue() functionsi ,n as an argument.
 *  1. If the employee likes a sada dosa and the top of the stack is a sada dosa(0), then the employee takes the sada dosa and leaves the queue.
 *  2. If the employee likes a masala dosa and the top of the stack is a masala dos(1)a, then the employee takes the masala dosa and leaves the queue.
 *  3. Else the employee leaves the front of the queue and goes to end of the queue,by calling Enqueue().
 *  */
int main() 
{
    int n, i, j,flag=0;
    printf("Enter the number of people: ");
    scanf("%d", &n);

    // Create the stack and queue
    CreateStack(n);
    CreateQueue(n);

    // Print initial stack and queue
    printf("Initial ");
    printStack();
    printQueue();

    // Matching dosas and removing from both stack and queue
    for (i = 0; i < n; i++) {
        for (j = 0; j < n * n; j++) {
            if (shead->data == qhead->data) {
		flag=1;
                Pop();
                Dequeue();
                //printf("Match found! ");
                printStack();
                printQueue();
                n--; // Decrement count since one person ate
                i--; // Recheck current person as one person was removed
                break;
            } 
	    else{
                Enqueue();
	    }
        }
	if(flag!=1)
		break;
	else
		flag=0;
    }
    printf("Remaining people who have not eaten: %d\n", n);
    return 0;
}

