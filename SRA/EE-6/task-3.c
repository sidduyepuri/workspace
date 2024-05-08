#include <stdio.h>
struct record
{
	char name[50];
	int age;
	int salary;
};
int main()
{
	int n,i;
	struct record person;
	FILE *fp=fopen("peoples.txt","r");
	if(fp==NULL)
	{
		printf("Failed to open file\n");
		return 0;
	}
	while(fscanf(fp,"Name:%s	age:%d	salary:%d\n",person.name,&person.age,&person.salary)!=EOF)
	{
		printf("name: %s\nage:%d\nsalary:%d\n",person.name,person.age,person.salary);
	}
	return 0;
}
