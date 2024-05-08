#include <stdio.h>
struct time{
	int *day;
	int *month;
	int *year;
};
void main()
{
	struct time *sample[10];
	int x=10;
	sample[0]->month=&x;
	//*(sample[2]->month)=12;
	printf("%d\n",*(sample[0]->month));
}
