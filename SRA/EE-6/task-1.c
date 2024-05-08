#include <stdio.h>
#include <string.h>
struct Person
{
	char name[50];
	char town[50];
};
char name[50];
char* readPerson(void);
int searchTown(struct Person persons[],char person[]);
int main()
{
	int i;
	char *per;
	struct Person persons[3];
	for(i=0;i<3;i++)
	{
		printf("Enter name:");
		scanf("%s",persons[i].name);
		printf("Enter town or city:");
		scanf("%s",persons[i].town);
	}
	per=readPerson();
	i=searchTown(persons,per);
	if(i!=-1)
		printf("This person lives in:%s\n",persons[i].town);
	else
		printf("This person details not found in the list.\n");
	return 0;
}
char* readPerson(void)
{
	printf("Enter the name of the person you want to search for:");
	scanf(" %s",name);
	return name;
}
int searchTown(struct Person persons[],char per[])
{
	int i=0;
	for(;i<3;i++)
	{
		if(strcmp(persons[i].name,per)==0)
			return i;
	}
	return -1;
}
