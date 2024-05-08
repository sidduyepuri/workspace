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
	int n,i,street;
	long int number;
	int postcode;
	char state[50];
	char lastname[50];
	struct record person;
	FILE *fp1=fopen("newfile.txt","r+");
	FILE *fp2=fopen("updatefile.txt","w+");
	if(fp1==NULL||fp2==NULL)
	{
		printf("Failed to open file\n");
		return 0;
	}
	while(fscanf(fp1,"Name:%s	last name:%s	age:%d	salary:%d\n",person.name,lastname,&person.age,&person.salary)!=EOF)
	{
		printf("Enter %s details:\n",person.name);
		printf("Enter street number:");
		scanf("%d",&street);
		printf("Enter mobile number:");
		scanf("%ld",&number);
		printf("Enter postal code:");
		scanf("%d",&postcode);
		printf("Enter state:");
		scanf(" %s",state);
		fprintf(fp2,"Name:%s	last name:%s	age:%d	salary:%d\nAddress:\nstreet:%d	number:%ld	postal code:%d	state:%s\n",person.name,lastname,person.age,person.salary,street,number,postcode,state);
	}
	int ret=fseek(fp2,0,SEEK_SET);
	if(ret!=-1)
	while(fscanf(fp2,"Name:%s	last name:%s	age:%d	salary:%d\nAddress:\nstreet:%d	number:%ld	postal code:%d	state:%s\n",person.name,lastname,&person.age,&person.salary,&street,&number,&postcode,state)!=EOF)
	{
		printf("Name:%s\nlast name:%s\nage:%d\nsalary:%d\nAddress:\nstreet:%d\nnumber:%ld\npostal code:%d\nstate:%s\n\n",person.name,lastname,person.age,person.salary,street,number,postcode,state);
	}
	return 0;
}
