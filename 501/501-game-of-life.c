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

#define FieldHeight 30 //Feldgröße Definiert TODO: Beim Start den Nutzer nach feldgröße Fragen?
#define FieldWidth 50

void initialize_cells();
void display_cells();
void evolution_step();
int count_cells();

// Globale Variablen
#define max_active_rand 50 //Max Wert für den Randomgenerator. Wahrscheinlichkeit für 1 = round(max_active_rand - (0.025 * max_active_rand)). Je größer die Konstante, desto weniger 1er kommen vor


// Global 2-dim-array which contains the cells
char cells[FieldHeight][FieldWidth];
int cell_generation;

// Main program
int main()
{
   int occupied_cells;
   // setvbuf (stdout, NULL, _IONBF, 0);
   cell_generation = occupied_cells = 0;
   printf("\033[0m"); //reset any console Ootions (eg. color)
   setvbuf (stdout, NULL, _IONBF, 0);
  
   srand(time(0));
   initialize_cells();

   while (1)
   {

      occupied_cells = count_cells();
      display_cells(occupied_cells);
      // Leave loop if there are no more occupied cells
      if (occupied_cells == (FieldHeight*FieldWidth))
         break;

      printf("Press enter to show next Gen.");
      getchar();
      evolution_step();
   }
}

// TO DO: initialize cells, set most to 0, some to 1
void initialize_cells()
{
   int i, j, rnd, cntr;
   cntr=0;


   printf("max_active_rand: %i, one_prob: %i\n", max_active_rand, (max_active_rand-1));
   for (i = 0; i < FieldHeight; i++)
   {
      for (j = 0; j < FieldWidth; j++)
      {
         rnd = rand() % max_active_rand;
         if (rnd < (max_active_rand-1))
         {
            cells[i][j] = 0;
         }
         else
         {
            cells[i][j] = 1;
         }
         cntr++;
         printf("Setting up Cell %i of %i \r", cntr, (FieldWidth*FieldHeight));
      }
   }
   printf("\n");
}

// TO DO: Write output function to show the cells
void display_cells(int occupied_cells)
{
   int i, j;
   char str;

   // system("CLS"); // Clear screen - works (at least) on windows console.
   printf("%c",201);
   for (i=0; i<FieldWidth; i++) {
      printf("%c%c%c",205,205,205);
   }
   printf("%c\n",187);
   
   for (i = 0; i < FieldHeight; i++)
   {
      printf("%c",186);
      for (j = 0; j < FieldWidth; j++)
      {
         
         switch(cells[i][j])
         {
            case 0:
            {
               printf("   ");
               break;
            }
            case 1:
            {
               printf(" %c ",248);
               break;
            }
            default:
            {
               printf(" E ");
               break;
            }
         }
      }
      printf("%c\n",186);
      //printf("%s\n", str);
      
   }
   printf("%c",200);
   for (i=0; i<FieldWidth; i++) {
      printf("%c%c%c",205,205,205);
   }
   printf("%c\n",188);
   printf("Currently showing Gen.: %i with %i occupied Cells.\n\n", cell_generation, occupied_cells);
}

// TO DO: Write a function to calculate the next evolution step
void evolution_step()
{
   // TO DO: Use this array for the calculation of the next step
   char NextGen[FieldHeight][FieldWidth];
   int i,j,k,l;
   for (i=0; i < FieldHeight; i++){
      for (j=0; j < FieldWidth; j++){

         int NachbarnLebend = 0;

         for (int k=-1; k<=1; k++){
            for (int l=-1; l <= 1; l++){
               if (i+k !< 0 && i+k !> FieldHeight && j+l !< 0 && j+l !> FieldWidth){
                  NachbarnLebend += cells[i+k][j+l];
               }
            }
         }
         NachbarnLebend -= cells[i][j];

         if ((cells[i][j] == 1 && NachbarnLebend < 2 )|| (cells[i][j] == 1 && NachbarnLebend > 3 ))
         {
            NextGen[i][j] = 0;
         }
         else if (cells[i][j] == 0 && NachbarnLebend == 3)
         {
            NextGen[i][j] = 1;
         }
         else
         {
            NextGen[i][j] = cells[i][j];
         }
      }
   }
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

      
