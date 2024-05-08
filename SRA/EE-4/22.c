#include <stdio.h>
struct time{
	int *day;
	int *month;
	int *year;
};
void main()
{
	struct time *times;
	*(times->day)=10;
}
