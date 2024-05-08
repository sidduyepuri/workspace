struct point {
	int x;
	int y;
};
struct rectangle {
	struct point upperLeft;
	struct point lowerRight;
};
float area(struct rectangle r);
int main()
{
	struct rectangle r;
	r.upperLeft.x=4;
	r.upperLeft.y=2;
	r.lowerRight.x=4;
	r.lowerRight.y=2;
	float ar=area(r);
	printf("area=%f\n",ar);
	return 0;
}
float area(struct rectangle r)
{
	return r.upperLeft.x*r.lowerRight.y;
}
