#include <stdio.h>

typedef struct tree {
	int num;
	struct tree *left;
	struct tree *right;
} BinTree;

BinTree *Node1=NULL;

void CreateTree(int n)
{
	BinTree *new;
	int i,j,l=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<l;j++)
		{
			new=(BinTree *)malloc(sizeof(BinTree));
			scanf("%d",&new->num);
			new->next=NULL;
			new->
		}
	}
}
