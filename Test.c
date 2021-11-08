#include <stdio.h>

int main() 
{
	setvbuf (stdout, NULL, _IONBF, 0);

	unsigned int n = 11;
    printf("\n Binary representation: ");   
	while(n>0) {
		printf("%d", n&1 );     
		n=n >> 1;
	}
}