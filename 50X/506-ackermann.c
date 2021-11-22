// Ackermann: calculate the Ackermann function 
// The mathematical Ackermann function is defined as follows:
//
//    A(m,n) =   n+1              if m=0
//               A(m-1,1)         if m>0 and n=0
//               A(m-1, A(m,n-1)) if m>0 and n>0
//
// TO DO 1: Write a function that calculates the Ackermann function according to the definition above DONE
//          Test the program with very small values first!
// TO DO 2: Extend the function such that it counts the number of functions calls (use a global variable counter) DONE
//          Print the function arguments and current count every x function calls. 
// TO DO 3: Count the amount of recursively called functions (which are not yet completed) and print them as well DONE
// TO DO 4: Use static variables in ackermann for counting rather than global variables.
// TO DO 5: Optional: Visualize the current recursion depth with bars of ascii-characters: xxxxxxxxxxxxxxxxxx
// TO DO 6: Optional: Provide values m and n via the command line
//          Allow in addition the option '-v' (verbose), to switch on output of intermediate results

#include <stdio.h>
#include <stdlib.h>

#define MAX_TIMER 20

int Ackermann(int m, int n);


int main()
{
   system("cls");

   int n, m, result;

   printf("Value for m: ");
   scanf("%d", &m);
   printf("Value for n: ");
   scanf("%d", &n);
 
   // TO DO: Call ackermann function
   result = Ackermann(m, n);
   printf("Ergebniss: %d, Anzahl der Calls: %d, Anzahl der Recursionen: %d\n", result, calls, recalls);

}

int Ackermann(int m, int n){

   static int calls = 0;
   static int recalls = 0;
   static int timer = 0;
   static int result = 0;

   calls++;
   if(timer == 0){
      printf("Arg m: %d n: %d Anzahl der Calls: %d \n", m, n, calls);
      timer = MAX_TIMER;
   }
   else{
      timer--;
   }
   recalls ++;
   if(m==0){
      result = n+1;
   }
   if(m>0 && n==0){
      result = Ackermann(m-1,1);
   }
   if(m>0 && n>0){
      result = Ackermann(m-1, Ackermann(m,n-1));
   }
   recalls --;
   
return result;
}