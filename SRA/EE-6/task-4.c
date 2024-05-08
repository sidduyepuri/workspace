#include <stdio.h>
#include <string.h>
struct record
{
	char name[50];
	int age;
	int salary;
};
int main()
{
	int n,i;
	char man[50];
	struct record person;
	FILE *fp=fopen("peoples.txt","r");
	if(fp==NULL)
	{
		printf("Failed to open file\n");
		return 0;
	}
	printf("What’s the name of the person you want to search for?");
	scanf(" %s",man);
	while(fscanf(fp,"Name:%s	age:%d	salary:%d\n",person.name,&person.age,&person.salary)!=EOF)
	{
		if(strcmp(person.name,man)==0)
		{
			printf("name: %s\nage:%d\nsalary:%d\n",person.name,person.age,person.salary);
			return 0;
		}
	}
	printf("The person you are searching not found the data.\n");
	return 0;
}
