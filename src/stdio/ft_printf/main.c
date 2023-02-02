#include <stdio.h>
#include <limits.h>
#include <libc.h>

int main()
{
	char *s[INT_MAX];

	bzero(s,INT_MAX);
	//printf("%ld\n", sizeof(long int));
}
