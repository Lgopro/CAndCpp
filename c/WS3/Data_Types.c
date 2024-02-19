/*
Rev: Ido Peled
Dev: Leonid Golovko
status: finished
date:23/03/23
*/
#include <stdio.h> /*fprintf*/






int main()
{
	int a = 0;
	size_t b = 0;
	float c = 0;
	double d = 0;
	long e = 0;
	char f = 'a';
	long int g = 0;
	long double h = 0;
	int *pointer;
	fprintf(stdout, "Size of int is:%ld \nSize of size_t is:%ld \nSize of float is:%ld\n", sizeof(a), sizeof(b),sizeof(c));
	fprintf( stdout, "Size of double is:%ld \nSize of long is:%ld \nSize of char is:%ld \nSize of long int is:%ld \n", sizeof(d),sizeof(e),(long int)sizeof(f),sizeof(g));
	fprintf( stdout, "Size of long double is:%ld \nSize of pointer is:%ld \n", sizeof(h), (long int)sizeof(pointer));
	return 0;
}
