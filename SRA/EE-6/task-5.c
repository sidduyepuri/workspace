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
	char lastname[50];
	struct record person;
	FILE *fp1=fopen("peoples.txt","r");
	FILE *fp2=fopen("newfile.txt","a+");
	if(fp1==NULL||fp2==NULL)
	{
		printf("Failed to open file\n");
		return 0;
	}
	while(fscanf(fp1,"Name:%s	age:%d	salary:%d\n",person.name,&person.age,&person.salary)!=EOF)
	{
		printf("Enter the last name of %s:",person.name);
		scanf(" %s",lastname);
		fprintf(fp2,"Name:%s	last name:%s	age:%d	salary:%d\n",person.name,lastname,person.age,person.salary);
	}
	int ret=fseek(fp2,0,SEEK_SET);
	if(ret!=-1)
	while(fscanf(fp2,"Name:%s	last name:%s	age:%d	salary:%d\n",person.name,lastname,&person.age,&person.salary)!=EOF)
	{
		printf("name: %s\nlast name:%s\nage:%d\nsalary:%d\n\n",person.name,lastname,person.age,person.salary);
	}
	return 0;
}
