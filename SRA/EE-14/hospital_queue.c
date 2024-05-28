#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each node in the priority queue
typedef struct PQ {
    char name[100];          // Name of the patient
    int priority;            // Priority of the patient (lower value means higher priority)
    struct PQ* next;         // Pointer to the next node in the list
} PTNode;

PTNode *front = NULL, *rear = NULL;  // Pointers to the front and rear of the priority queue

// Function to add/enqueue a new patient to the priority queue
void pq_newPT(char *name, int priority) {
    PTNode *new = NULL, *tmp = NULL, *dup = front;
    new = (PTNode *)malloc(sizeof(PTNode));  // Allocate memory for the new node
    strcpy(new->name, name);                 // Copy the patient's name to the new node
    new->priority = priority;                // Set the patient's priority in the new node
    new->next = NULL;                        // Initialize the next pointer to NULL

    if (front == NULL) {                     // If the queue is empty
        front = new;                         // The new node becomes the front node
        return;
    }

    if ((front->priority) > (new->priority)) {  // If the new node has higher priority than the front node
        tmp = dup;
        dup = new;
        dup->next = tmp;
        front = dup;                         // The new node becomes the front node
        return;
    }

    // Traverse the list to find the correct position for the new node
    while (dup->next != NULL) {
        if ((dup->next->priority) > (new->priority)) {
            new->next = dup->next;
            dup->next = new;                 // Insert the new node in the correct position
            return;
        }
        dup = dup->next;
    }

    dup->next = new;                         // Insert the new node at the end of the list
    return;
}

// Function to remove/dequeue the patient with the most urgent priority from the queue
void pq_processPT(void) {
    if (front == NULL)
        return;

    PTNode *tmp = NULL;
    tmp = front;
    front = front->next;                     // Move the front pointer to the next node
    free(tmp);                               // Free the memory of the removed node
    return;
}

// Function to return the name of the most urgent patient without removing it
char *pq_frontName() {
    if (front == NULL) {
        printf("Queue doesn't have patients..\n");
        return 0;
    } else {
        return front->name;
    }
}

// Function to return the priority of the most urgent patient without removing it
int pq_frontPriority() {
    if (front == NULL) {
        printf("Queue doesn't have patients..\n");
        return 0;
    } else {
        return front->priority;
    }
}

// Function to upgrade the priority of an existing patient in the queue
void pq_upgradePT(char *name, int newPriority) {
    PTNode *tmp = front, *T = NULL;

    // Check if the front node has the given name
    if (strcmp(tmp->name, name) == 0) {
        T = front;
        front = front->next;                // Remove the node from the list
        free(T);
        return;
    }

    // Traverse the list to find the node with the given name
    while (tmp->next != NULL) {
        if (strcmp(tmp->next->name, name) == 0) {
            T = tmp->next;
            tmp->next = tmp->next->next;    // Remove the node from the list
            free(T);
            return;
        }
        tmp = tmp->next;
    }
}

// Function to clear all elements from the patient queue
void pq_clear(void) {
    PTNode *tmp = NULL;
    while (front != NULL) {
        tmp = front;
        front = front->next;                // Move the front pointer to the next node
        free(tmp);                          // Free the memory of the removed node
    }
    return;
}

// Function to check if the patient queue is empty
int pq_isEmpty() {
    if (front == NULL)
        return 0;                           // Return 0 if the queue is empty
    else
        return 1;                           // Return 1 if the queue is not empty
}

// Function to print the patient queue to the console
void toString(void) {
    PTNode *tmp = front;
    printf("Current patient queue:{");
    if (tmp == NULL) {
        printf("} (empty)\n");
        return;
    }
    while (tmp != NULL) {
        printf("%d:%s", tmp->priority, tmp->name);
        tmp = tmp->next;
        if (tmp != NULL)
            printf(", ");
    }
    printf("} (not empty)\n");
}

// Main function to interact with the user and perform queue operations
int main() {
    char choice;
    char name[100];
    int priority;
    char *nam;

    while (1) {
        toString();  // Print the current state of the queue
        printf("N)ew, F)ront, U)pgrade, P)rocess, B)ulk, C)lear, Q)uit?");
        scanf(" %c", &choice);  // Read the user's choice

        switch (choice) {
            case 'N': 
                printf("Name?");
                scanf(" %s", name);  // Read the name of the new patient
                printf("Priority?");
                scanf("%d", &priority);  // Read the priority of the new patient
                pq_newPT(name, priority);  // Add the new patient to the queue
                break;
            case 'F': 
                nam = pq_frontName();  // Get the name of the front patient
                priority = pq_frontPriority();  // Get the priority of the front patient
                printf("Front of the patient in the line %s with the priority is %d\n", nam, priority);
                break;
            case 'U': 
                printf("Name?");
                scanf(" %s", name);  // Read the name of the patient to upgrade
                printf("New priority?");
                scanf("%d", &priority);  // Read the new priority
                pq_upgradePT(name, priority);  // Upgrade the patient's priority
                pq_newPT(name, priority);  // Reinsert the patient with the new priority
                break;
            case 'P': 
                pq_processPT();  // Process the front patient
                break;
            case 'B':
            case 'C': 
                pq_clear();  // Clear the patient queue
                break;
            case 'Q': 
                printf("\nExiting.\n");
                return 0;  // Exit the program
        }
    }
}

