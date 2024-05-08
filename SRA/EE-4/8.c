#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
	int ID;
	char name[10];
	struct student *next;
}stu;

stu *traversal(stu *T)
{
	while(T)
	{
		printf("ID:%d name:%s\n",T->ID,T->name);
		T=T->next;
	}
}

stu *createnode()
{
	stu *N=malloc(sizeof(stu));
	printf("Enter id and name:");
	scanf("%d%s",&N->ID,N->name);
	N->next=NULL;
	return N;
}

stu *createlist()
{
	stu *H=NULL,*N=NULL,*L=NULL;
	char ch='y';
	while(ch == 'y')
	{
		N=createnode();
		if(H==NULL)
			H=N;
		else
			L->next=N;
		L=N;
		printf("Create another? (y/n)");
		scanf(" %c",&ch);
	}
	return H;
}
int countOccurrences(stu *list,int n)
{
	int count=0;
	while(list!=NULL)
	{
		if(list->ID==n)
			count++;
		list=list->next;
	}
	return count;
}

int main()
{
	int count;
	stu *H;
	H=createlist();
	traversal(H);
	count=countOccurrences(H,5);
	printf("count=%d\n",count);
	return 0;
}
