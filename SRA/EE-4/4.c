#include <stdio.h>
typedef struct { 
	double x; 
	double y; 
}Point;
int main(void) 
{
	Point test = {.25, .75};
	POINTshow(test);
	return 0;
}
void POINTshow(Point test)
{
	printf("[%f %f]\n",test.x,test.y);
}
