/* prime sieve of Eratosthenes */
// TO DO 1: The program seems to work, but look carefully at the results -> There is a (typical) bug
// TO DO 2: Extend it such that the maximum number n to be calculated can be entered by the user
//          Use scanf("%d", &n)
// TO DO 3: What does this mean for the array? How should the program be adapted to work reliably? 

#include <stdio.h>

int main()
{
   printf("Bis wohin soll gerechnet werden?\n");

   setvbuf (stdout, NULL, _IONBF, 0);

   int i, j, n;
   scanf("%d", &n);
   char is_prime[n];   // For full compatibility (C89, C90, C11) Array size has to be a constant!

   /* Initialize Array */
   for(i=0; i<n; i=i+1) 
      is_prime[i]=1;
	   
   for(i=2; i<n; i=i+1)  
      for(j=2*i; j<n; j=j+i)
         is_prime[j] = 0;

   printf("Prime numbers are: ");
   for(i=2; i<=n; i=i+1)
      if(is_prime[i]>0)
         printf("\n%d ",i);
}