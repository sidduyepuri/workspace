#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each node in the binary tree
typedef struct Node {
	char str[100];          // String to store question or answer
	struct Node* left;      // Pointer to the left child
	struct Node* right;     // Pointer to the right child
} Node;

// Global variables
FILE *fp = NULL;            // File pointer to read the questions file

// Function to create a new node
Node* createNode(void) {
	Node* newNode = (Node*)malloc(sizeof(Node));  // Allocate memory for the new node
	if (newNode == NULL) {                        // Check if memory allocation was successful
		printf("Memory allocation failed.\n");
		exit(EXIT_FAILURE);                       // Exit program if memory allocation fails
	}
	newNode->left = NULL;                         // Initialize left child to NULL
	newNode->right = NULL;                        // Initialize right child to NULL
	return newNode;                               // Return the created node
}

// Function to add new questions and answers to the tree
void addNewNode(Node* leaf) {

	Node *node1 = NULL, *node2 = NULL;            // Temporary nodes for new branches
	char answer[50], question[50], tmp[50],choice;       // Buffers to store answer, question, and temporary string

	printf("What is your answer? ");
	scanf(" %49s", answer);                       // Read the new answer from the user (width specifier for safety)

	printf("What is the question? ");
	scanf(" %[^\n]49s", question);                // Read the new question from the user (width specifier for safety)

	printf("Y/N? ");
	scanf(" %c", &choice);                        // Read user's choice (y/n)

	node1 = createNode();                         // Create first new node
	node2 = createNode();                         // Create second new node

	// Copy existing leaf data to temporary buffer and then to first new node
	strcpy(tmp, leaf->str);
	strcpy(leaf->str, question);
	strcpy(node1->str, tmp);
	strcpy(node2->str, answer);

	// Link new nodes based on user's choice
	if (choice == 'y') {
		leaf->left = node2;
		leaf->right = node1;
	} else if (choice == 'n') {
		leaf->left = node1;
		leaf->right = node2;
	}
}

// Function to perform preorder traversal of the binary tree
void preorderTraversal(Node* root)
{
	char choice;
	if (root != NULL) {                           // Check if the current node is not NULL
		printf("%s", root->str);                  // Print the current node's string
		scanf(" %c", &choice);                    // Read user's choice (y/n)

		// If the node contains an answer
		if (root->str[0] == 'A') {
			if (choice == 'y') {
				printf("Hey, I win!\n");          // If user says yes, the program wins
			} else if (choice == 'n') {
				printf("Drat, I lost.\n");        // If user says no, the program loses
				addNewNode(root);                 // Add new question and answer to the tree
			}
			return;                               // Return to stop further traversal
		} 
		// If the node contains a question
		else if (choice == 'y' && root->str[0] == 'Q') {
			preorderTraversal(root->left);        // Traverse the left subtree if user says yes
		} else if (choice == 'n' && root->str[0] == 'Q') {
			preorderTraversal(root->right);       // Traverse the right subtree if user says no
		}
	}
}

// Function to create the binary tree from a file using preorder traversal
Node* preorderCreation() {
	char str[100];

	if (fgets(str, sizeof(str), fp) == NULL) {    // Read a line from the file
		return NULL;                              // Return NULL if end of file is reached or error occurs
	}

	Node* newNode = createNode();                 // Create a new node
	strcpy(newNode->str, str);                    // Copy the read string into the node's string

	// If the node is an answer
	if (newNode->str[0] == 'A') {
		newNode->left = NULL;                     // Set left child to NULL
		newNode->right = NULL;                    // Set right child to NULL
		return newNode;                           // Return the created node
	} 
	// If the node is a question
	else if (newNode->str[0] == 'Q') {
		newNode->left = preorderCreation();       // Recursively create the left subtree
		newNode->right = preorderCreation();      // Recursively create the right subtree
	} else {
		return NULL;                              // Return NULL if the node is neither question nor answer
	}

	return newNode;                               // Return the created node
}

// Main function
int main() {
	Node* root = NULL;                            // Initialize root node

	fp = fopen("questions.txt", "r");             // Open the file containing questions and answers
	if (fp == NULL) {                             // Check if file opening failed
		perror("File open failed");
		return EXIT_FAILURE;                      // Return failure status
	}

	root = preorderCreation();                    // Create the binary tree from the file
	printf("\n");

	// Perform the preorder traversal and interaction
	while (1) {                                   // Loop indefinitely for user interaction
		printf("Preorder traversal:\n");
		preorderTraversal(root);                  // Perform preorder traversal and interact with user
		printf("\n");
	}

	return 0;                                     // Return success status
}

