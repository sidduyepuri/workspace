main()
{
	typedef struct a aType; 
	aType someVariable; 
	struct a
	{
		int x;
		aType *b;
	};
}

