#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int row, column;
    double value;
    struct node* rowPtr;
    struct node* colPtr;
} node;

typedef struct matrix {
    node** rowList;
    node** columnList;
    int rows, columns;
} matrix;

node* CreateNode(int i, int j) {
    node* new = (node*)malloc(sizeof(node));
    new->row = i;
    new->column = j;
    scanf("%lf", &new->value);
    new->rowPtr = NULL;
    new->colPtr = NULL;
    return new;
}

void PrintMatrix(matrix* M) {
    node* head = NULL;
    double x = 0;
    for (int i = 0; i < M->rows; i++) {
        head = M->rowList[i];
        for (int j = 0; j < M->columns; j++) {
            if (head == NULL || head->column != j) {
                printf("%lf ", x);
            } else {
                printf("%lf ", head->value);
                head = head->rowPtr;
            }
        }
        printf("\n");
    }
}

int duplicatevalue(matrix* M, double value) {
    node* head = NULL;
    for (int i = 0; i < M->rows; i++) {
        head = M->rowList[i];
        while (head != NULL) {
            if (head->value == value)
                return 1;
            head = head->rowPtr;
        }
    }
    return 0;
}

matrix* CreateMatrix(matrix* Mat) {
    node* new = NULL, * head = NULL;
    Mat->rowList = (node**)malloc(sizeof(node*) * Mat->rows);
    Mat->columnList = (node**)malloc(sizeof(node*) * Mat->columns);
    for (int i = 0; i < Mat->rows; i++) {
        Mat->rowList[i] = NULL;
    }
    for (int i = 0; i < Mat->columns; i++) {
        Mat->columnList[i] = NULL;
    }

    for (int i = 0; i < Mat->rows; i++) {
        for (int j = 0; j < Mat->columns; j++) {
            printf("Enter (%d,%d) value: ", i + 1, j + 1);
            new = CreateNode(i, j);
            if (Mat->rowList[i] == NULL) {
                Mat->rowList[i] = new;
            } else {
                head = Mat->rowList[i];
                while (head->rowPtr != NULL) {
                    head = head->rowPtr;
                }
                head->rowPtr = new;
            }
            if (Mat->columnList[j] == NULL) {
                Mat->columnList[j] = new;
            } else {
                head = Mat->columnList[j];
                while (head->colPtr != NULL) {
                    head = head->colPtr;
                }
                head->colPtr = new;
            }
        }
    }
    return Mat;
}

int resize(matrix** M) {
    matrix* Mat = (matrix*)realloc(*M, sizeof(matrix));
    if (Mat == NULL)
        return 0;

    Mat->rowList = (node**)realloc(Mat->rowList, sizeof(node*) * Mat->rows * 2);
    Mat->columnList = (node**)realloc(Mat->columnList, sizeof(node*) * Mat->columns * 2);
    if (Mat->rowList == NULL || Mat->columnList == NULL)
        return 0;

    for (int i = Mat->rows; i < Mat->rows * 2; i++) {
        Mat->rowList[i] = NULL;
    }
    for (int i = Mat->columns; i < Mat->columns * 2; i++) {
        Mat->columnList[i] = NULL;
    }

    *M = Mat;
    (*M)->rows *= 2;
    (*M)->columns *= 2;
    return 1;
}

int transpose(matrix **Mat) {
    int i, j;
    node *temp = NULL, *current = NULL;

    // Create new matrix dimensions
    int newRows = (*Mat)->columns;
    int newCols = (*Mat)->rows;

    // Create new lists for rows and columns for the transposed matrix
    node** newRowList = (node**)malloc(sizeof(node*) * newRows);
    node** newColList = (node**)malloc(sizeof(node*) * newCols);

    // Initialize new lists
    for (i = 0; i < newRows; i++) {
        newRowList[i] = NULL;
    }
    for (i = 0; i < newCols; i++) {
        newColList[i] = NULL;
    }

    // Iterate over the original matrix to adjust pointers and transpose values
    for (i = 0; i < (*Mat)->rows; i++) {
        current = (*Mat)->rowList[i];
        while (current != NULL) {
            int newRow = current->column;
            int newCol = current->row;

            // Create a new node for the transposed position
            node* newNode = (node*)malloc(sizeof(node));
            newNode->row = newRow;
            newNode->column = newCol;
            newNode->value = current->value;

            // Add the new node to the transposed matrix
            if (newRowList[newRow] == NULL) {
                newRowList[newRow] = newNode;
            } else {
                node* tempNode = newRowList[newRow];
                while (tempNode->rowPtr != NULL) {
                    tempNode = tempNode->rowPtr;
                }
                tempNode->rowPtr = newNode;
            }

            if (newColList[newCol] == NULL) {
                newColList[newCol] = newNode;
            } else {
                node* tempNode = newColList[newCol];
                while (tempNode->colPtr != NULL) {
                    tempNode = tempNode->colPtr;
                }
                tempNode->colPtr = newNode;
            }

            // Move to the next element in the row
            current = current->rowPtr;
        }
    }

    // Free the old matrix
    for (i = 0; i < (*Mat)->rows; i++) {
        current = (*Mat)->rowList[i];
        while (current != NULL) {
            node* next = current->rowPtr;
            free(current);
            current = next;
        }
    }
    free((*Mat)->rowList);
    free((*Mat)->columnList);

    // Update the matrix structure with the transposed values
    (*Mat)->rows = newRows;
    (*Mat)->columns = newCols;
    (*Mat)->rowList = newRowList;
    (*Mat)->columnList = newColList;


    return 1;
}
int main(void) {
	int m, n, choice, ret;
	double value;
	printf("Enter rows and columns: ");
	scanf("%d%d", &m, &n);

	matrix* M = (matrix*)malloc(sizeof(matrix));
	M->rows = m;
	M->columns = n;
	M->rowList = (node**)malloc(sizeof(node*) * m);
	M->columnList = (node**)malloc(sizeof(node*) * n);

	for (int i = 0; i < m; i++) {
		M->rowList[i] = NULL;
	}
	for (int i = 0; i < n; i++) {
		M->columnList[i] = NULL;
	}

	while (1) {
		printf("Options:\n1. CreateMatrix.\n2. PrintMatrix.\n3. DuplicateValue.\n4. Transpose.\n5. Resize.\nChoose your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				M = CreateMatrix(M);
				break;
			case 2:
				PrintMatrix(M);
				break;
			case 3:
				printf("Enter value to check: ");
				scanf("%lf", &value);
				ret = duplicatevalue(M, value);
				printf("%s\n", ret == 1 ? "found" : "Not found");
				break;
			case 4: matrix *M1=(matrix *)malloc(sizeof(matrix));
				M1=M;
				transpose(&M1);
				PrintMatrix(M1);
				break;
			case 5:
				ret = resize(&M);
				printf("%s\n", ret == 1 ? "Resized successfully" : "Not resized");
				break;
			default:
				printf("Invalid choice.\n");
				break;
		}
	}
	return 0;
}

