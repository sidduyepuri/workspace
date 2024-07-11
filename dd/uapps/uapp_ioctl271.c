/* ioctl() command bitfields
	ex:- 0x80046c01
	Here,
		01	- sequential number	- 8 bit wide	-	0000 0001
		6c	- magic number/type	- 8 bit wide	-	0110 1100
		004	- size			- 14 bit size	-	00 0000 0100(int)
		10	- read operation	- 2 bit size	-	00(none), 10(read), 01(write), 11(both)
*/

#include <stdio.h>
#include <linux/ioctl.h>

#define MAGIC_NUMBER1 'l'
#define MAGIC_NUMBER2 'i'

int main()
{
	printf("_IO(MAGIC_NUMBER1, 1):%x\n",_IO(MAGIC_NUMBER1, 1));
	printf("_IO(MAGIC_NUMBER2, 1):%x\n",_IO(MAGIC_NUMBER2, 1));

	getchar();	
	printf("_IO(MAGIC_NUMBER1, 2):%x\n",_IO(MAGIC_NUMBER1, 2));
	printf("_IO(MAGIC_NUMBER2, 2):%x\n",_IO(MAGIC_NUMBER2, 2));
	
	getchar();	
	printf("_IOR(MAGIC_NUMBER1, 1, int):%lx\n",_IOR(MAGIC_NUMBER1, 1, int));
	printf("_IOR(MAGIC_NUMBER2, 1, int):%lx\n",_IOR(MAGIC_NUMBER2, 1, int));
	
	getchar();	
	printf("_IOW(MAGIC_NUMBER1, 1, int):%lx\n",_IOW(MAGIC_NUMBER1, 1, int));
	printf("_IOW(MAGIC_NUMBER2, 1, int):%lx\n",_IOW(MAGIC_NUMBER2, 1, int));
	
	getchar();	
	printf("_IOWR(MAGIC_NUMBER1, 1):%lx\n",_IOWR(MAGIC_NUMBER1, 1, int));
	return 0;
}

