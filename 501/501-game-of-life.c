/* Game of life
The "game of life" is an old and very simple approach of simulating evolution 
A 2-dimensional field of cells is regarded with a cell being either empty/dead (0) or occupied/alive (1)
The intial state can be chosen e.g. manually or using some random operations.

The further evolution is governed by the following rules:

Every cell interacts with its eight neighbours, which are the cells that are directly horizontally, vertically, or diagonally adjacent. 
At each step in time, the following transitions occur:
   1. Any live cell with fewer than two live neighbours dies, as if by needs caused by underpopulation.
   2. Any live cell with more than three live neighbours dies, as if by overcrowding.
   3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
   4. Any empty/dead cell with exactly three live neighbours cells will be populated with a living cell.

The initial pattern constitutes the 'seed' of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed � births and deaths happen simultaneously, and the discrete moment at which this happens is sometimes called a tick. (In other words, each generation is a pure function of the one before.)  The rules continue to be applied repeatedly to create further generations.

see: http://en.wikipedia.org/wiki/Conway's_Game_of_Life
*/

// TO DO: Complete the programm such that it simulates the game of life.
//        Do this as teamwork (e.g. in teams with 2 or 3)
//        and benefit from the fact the functions can developed separately and then integrated into the final program.
// TO DO optional 1: extend the program, such that it detects 'stable states', i.e. the system is oscillating between a few states.
// TO DO optional 2: let the program find a start state such that the system stays alive and unstable for as long as possible
// TO DO optional 3: Create a flicker-free output: Do not print each character separately, but write the output into a string, which is printed all at once
// TO DO optional 4: extend the program such that the content of the cells can be edited by the user.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_cells();
void display_cells();
void evolution_step();
int count_cells();

// Globale Variablen
#define FieldHeight 30 //Feldgröße Definiert TODO: Beim Start den Nutzer nach feldgröße Fragen?
#define FieldWidth 50

// Global 2-dim-array which contains the cells
char cells[FieldHeight][FieldWidth];

// Hello, World 23

// Main program
int main()
{
   setvbuf (stdout, NULL, _IONBF, 0);

   srand(time(0));
   initialize_cells();

   while (1)
   {
      display_cells();

      // Leave loop if there are no more occupied cells
      if (count_cells() == 0)
         break;

      printf("Press enter");
      getchar();
// scudnfruidi
      evolution_step();
   }
}

// TO DO: initialize cells, set most to 0, some to 1
void initialize_cells()
{
   int i, j, rnd, cntr;
   cntr=0;
   for (i = 0; i < FieldHeight; i++)
   {
      for (j = 0; j < FieldWidth; j++)
      {
         rnd = rand() % 10;
         if (rnd < 9)
         {
            cells[i][j] = 0;
         }
         else
         {
            cells[i][j] = 1;
         }
         cntr++;
         system("clear");
         printf("Setting up Cell %i of %i Cells", cntr, (FieldWidth*FieldHeight));
      }
   }
}

// TO DO: Write output function to show the cells
void display_cells()
{
   int i, j;
   // system("CLS"); // Clear screen - works (at least) on windows console.
   for (i = 0; i < FieldHeight; i++)
   {
      for (j = 0; j < FieldWidth; j++)
      {
         switch(cells[i][j])
         {
            case 0:
            {
               printf("\033[0;31m");
               printf(" %d ", cells[i][j]);
               printf("\033[0m");
               break;
            }
            case 1:
            {
               printf("\033[0;32m");
               printf(" %d ", cells[i][j]);
               printf("\033[0m");
               break;
            }
            default:
            {
               printf("\033[0;33m");
               printf(" %d ", cells[i][j]);
               printf("\033[0m");
               break;
            }
         }
      }
      printf("\n");
   }
}

// TO DO: Write a function to calculate the next evolution step
void evolution_step()
{
   // TO DO: Use this array for the calculation of the next step
   char cells_helper[FieldHeight][FieldWidth];
}

// TO DO: Write a function that counts the occupied cells
int count_cells()
{
   int i, j;
   int count = 0;
   for (i = 0; i < FieldHeight; i++)
   {
      for (j = 0; j < FieldWidth; j++)
      {
         if (cells[i][j] == 1)
            count++;
      }
   }
   return count;
}

      