 /* number_puzzle.c 
   Write a number puzzle program by completing the TO DOs
   TO DO 1: Initialize the puzzle, such that the numbers 1 to 15 are randomly distributed in the array.
            -1 should mark the empty field.
   TO DO 2: get key and move pieces accordingly (if keystroke is valid)
   TO DO 3: Check, if puzzle is in correct order -> set sorted=1
   TO DO 4: Create a more fancy output, e.g. by creating frames around the numbers
                (Use a special character e.g. a block rather than '*')
                (Also, mark the empty field rather than showing -1)

            *********************
            *  1 *  2 *  3 *  4 *
            *********************
            *  5 *  6 *  7 *  8 *
            *********************
            *  9 * 10 * 11 * 12 *
            *********************
            * 13 * 14 * 15 ******
            *********************

   TO DO 5, optional: created an automatic, intelligent puzzle solver, which solves the puzzle without user interaction.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void IniFeld();
void RandFeld();

int puzzle[4][4];
char key;            // This holds the current key entered by the player.
char sorted=0;       // This flag marks, if the field is sorted.  
int i= 0, j = 0;

int main()
{
   srand(time(NULL));
   IniFeld();
   while(!sorted) {

      /* Output */
      for(i=0; i<4; i++) {
         for(j=0; j<4; j++) {
             printf("%2d ", puzzle[i][j]);
         }
         printf("\n");
      }
    





      printf("move into direction?");
     
   }
}

void IniFeld(){

   for(i=0; i<4; i++) {
         for(j=0; j<4; j++) {
            if (i == 3 && j == 3){
               puzzle[i][j] = -1;
            }
            else{
               puzzle[i][j] = 1 + j + i*4; // Formel mit der die Werte für die Generierung
            }
         }
   }
   RandFeld();
}

void RandFeld(){
   
   for (i = 0; i < 69; i++)
   {
      int r1 = rand()%4;
      int r2 = rand()%4;
      int r3 = rand()%4;
      int r4 = rand()%4;
      int temp = puzzle[r1][r2];
      puzzle[r1][r2] = puzzle[r3][r4];
      puzzle[r3][r4] = temp;
   }
   
}