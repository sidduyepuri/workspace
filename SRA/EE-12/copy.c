/*Task to perform : Write Unit Test Case, Apply coding standards and implement following task.
1. Suppose M is a matrix*, where matrix is as defined above. Write code to allocate enough space to initialize a matrix of n by m. 
2. Given a pointer to a node called ptr (assume all memory is allocated and node  initialized), write code to insert the node to the beginning of the each list.
3. Write a function int duplicatevalue(matrix* M, double value) that returns 1 if a  node with the value exists in the matrix. Return 0 if not.
4. Write a function int resize(matrix**) that doubles the rows and columns of the matrix. The old nodes need to be copied to the new matrix. Return 0 if success, 1 
if failure.
5. Write a function int transpose(matrix**) that takes the transpose of the matrix. Transpose of a matrix M is defined as a matrix M1 where rows of M are equivalent to columns of M1 and columns of M are equivalent to rows of M1. For example the transpose of M = {{1,2},{3,4}} is M1 = {{1,3},{2,4}}.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node { 
	int row, column;
	double value; 
	struct node* rowPtr; 
	struct node* colPtr; 
} node;

typedef struct matrix {
	node** rowList; // rowList is a pointer to the array of rows
	node** columnList; // column list is a pointer to the array of columns.
	int rows, columns; // store the number of rows and columns of the matrix
} matrix;

node* CreateNode(int i,int j)
{
        node *new=(node *)malloc(sizeof(node));
        new->row=i;
        new->column=j;
        scanf("%lf",&new->value);
        new->rowPtr=NULL;
        new->colPtr=NULL;
        return new;
}

matrix* PrintMatrix(matrix *M)
{
	node *head=NULL;
	double x=0;
	int i,j;
	for(i=0;i<M->rows;i++)
	{
		head=M->rowList[i];
		for(j=0;j<M->columns;j++)
		{
			if(head==NULL || head->column != j)
				printf("%lf ",x);
			else {
				printf("%lf ",head->value);
				head=head->rowPtr;
			}
		}
		printf("h\n");
	}
}

int duplicatevalue(matrix* M, double value)
{
	node *head=NULL;
        int i,j;
        for(i=0;i<M->rows;i++)
        {
                head=M->rowList[i];
                while(head!=NULL)
                {
			if(head->value==value)
				return 1;
                        head=head->rowPtr;
                }
        }
	return 0;
}

matrix* CreateMatrix(matrix *Mat)
{
	node *new=NULL,*head=NULL;
	Mat->rowList = (node **)malloc(sizeof(node *) * Mat->rows);
	Mat->columnList = (node **)malloc(sizeof(node *) * Mat->columns);
	for (int i = 0; i < Mat->rows; i++) {
		Mat->rowList[i] = NULL;
	}
	for (int i = 0; i < Mat->columns; i++) {
		Mat->columnList[i] = NULL;
	}
	int i,j;
	for(i=0;i<Mat->rows;i++)
	{
		for(j=0;j<Mat->columns;j++)
		{
			printf("Enter (%d,%d) value:",i+1,j+1);
			new=CreateNode(i,j);
			if(Mat->rowList[i]==NULL)
				Mat->rowList[i]=new;
			else{
				head=Mat->rowList[i];
				while(head->rowPtr!=NULL)
					head=head->rowPtr;
				head->rowPtr=new;
			}
			if(Mat->columnList[i]==NULL)
				Mat->columnList[i]=new;
			else{
				head=Mat->columnList[i];
				while(head->colPtr!=NULL)
					head=head->colPtr;
                                head->colPtr=new;
                        }
		}
	}
	return Mat;
}
int duplicatevalue(matrix* M, double value);
int resize(matrix **M)
{
	int i;
	matrix *Mat = (matrix *)realloc(*M, sizeof(matrix));
	if (Mat == NULL) 
		return 0;
	Mat=(matrix *)realloc(*M,sizeof(matrix));
	Mat->columnList=(node **)realloc((*M)->columnList,sizeof(node *)*(*M)->columns*2);
	if (Mat->rowList == NULL || Mat->columnList == NULL) 
		return 0;
	for(i=Mat->rows;i<Mat->rows*2;i++)
		Mat->rowList[i] = NULL;
	for(i=Mat->columns;i<Mat->columns*2;i++)
		Mat->columnList[i] = NULL;
	*M=Mat;
	(*M)->rows*=2;
	(*M)->columns*=2;
	return 1;
}
/*int transpose(matrix **M)
{
	int i,j,k;
	node *temp=NULL,*current=NULL;
	for(i=0;i<(*M)->rows;i++)
	{
		current=(*M)->rowList[i];
		while(current!=NULL)
		{
			printf("val %lf\n",current->value);
			temp=current->rowPtr;
			current->rowPtr=current->colPtr;
			current->colPtr=temp;
			current=temp;
		}
	}

	// Swap rowList and columnList
	node** tempList = (*M)->rowList;
	(*M)->rowList = (*M)->columnList;
	(*M)->columnList = tempList;

	int tempDim = (*M)->rows;
	(*M)->rows = (*M)->columns;
	(*M)->columns = tempDim;
	
	return 1;
}*/
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
int main(void)
{
	int m,n,choice,ret;
	double value;
	printf("Enter rows and columns:");
	scanf("%d%d",&m,&n);
	matrix *M=(matrix *)malloc(sizeof(matrix));
	M->rows=m,M->columns=n;
	M->rowList=(node **)malloc(sizeof(node *)*M->rows);
	M->columnList=(node **)malloc(sizeof(node *)*M->columns);
	for (int i = 0; i < m; i++) {
		M->rowList[i] = NULL;
	}
	for (int i = 0; i < n; i++) {
		M->columnList[i] = NULL;
	}
	node *N=NULL;
	while(1)
	{
		printf("Options:\n1.CreateMatrix.\n2.PrintMatrix.\n3.DuplicateValue.\n4.Transpose.\n5.resize.\nChoose your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			
			case 1: M=CreateMatrix(M);
				break;
			case 2: PrintMatrix(M);
				break;
			case 3: printf("Enter value for check:");
				scanf("%lf",&value);
				ret=duplicatevalue(M,value);
				if(ret==1)
					printf("found\n");
				else
					printf("Not found\n");
				break;
			case 4:	//matrix *M1=(matrix *)malloc(sizeof(matrix));
				matrix *M1=NULL;
				M1=M;
				transpose(&M1);
				PrintMatrix(M1);
				break;
			case 5: ret=resize(&M);
				if(ret==1)
					printf("Resized successfully\n");
				else
					printf("Not resized\n");
				break;
			default: printf("Invalid choice.");
				 break;
		}

	}
}
