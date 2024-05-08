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
	FILE *fp=fopen("peoples.txt","a+");
	if(fp==NULL)
	{
		printf("Failed to open file\n");
		return 0;
	}
	printf("How many people do you want to enter?");
	scanf("%d",&n);
	struct record persons[n];
	for(i=0;i<n;i++)
	{
		printf("Enter name:");
		scanf("%s",persons[i].name);
		printf("Enter age:");
		scanf("%d",&persons[i].age);
		printf("Enter salary:");
		scanf("%d",&persons[i].salary);
		fprintf(fp,"Name:%s	age:%d	salary:%d\n",persons[i].name,persons[i].age,persons[i].salary);
	}
	return 0;
}
