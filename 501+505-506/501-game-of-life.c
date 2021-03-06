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
// TO DO optional 1: extend the program, such that it detects 'stable states', i.e. the system is oscillating between a few states. @Rexphel
// TO DO optional 2: let the program find a start state such that the system stays alive and unstable for as long as possible
// TO DO optional 3: Create a flicker-free output: Do not print each character separately, but write the output into a string, which is printed all at once
// TO DO optional 4: extend the program such that the content of the cells can be edited by the user.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <signal.h>

// Globale Variablen
#define max_active_rand 10 //Max Wert für den Randomgenerator. Wahrscheinlichkeit für 1 = round(max_active_rand - (0.025 * max_active_rand)). Je größer die Konstante, desto weniger 1er kommen vor
#define FieldHeight 30 //Feldgröße Definiert TODO: Beim Start den Nutzer nach feldgröße Fragen?
#define FieldWidth 50
// #define AutoMode 1 //Automatikmodus? ja -> 1, nein -> 0

void initialize_cells();
void display_cells();
void evolution_step();
void check_stable();
int count_cells();
void cancel_handler();
void autoModeHandler();


// Global 2-dim-array which contains the cells
char cells[FieldHeight][FieldWidth];
char last_cell_states[4][FieldHeight][FieldWidth];
char Flag_stable, Flag_oscillating2, Flag_oscillating3;
int cell_generation;
int AutoMode = 0;

static volatile int keepRunning = 1;

// Main program
int main()
{
   int occupied_cells;
   // setvbuf (stdout, NULL, _IONBF, 0);
   cell_generation = occupied_cells = 0;
   Flag_stable = Flag_oscillating2 = Flag_oscillating3 = 0;
   printf("\033[0m"); //reset any console Ootions (eg. color)
   setvbuf (stdout, NULL, _IONBF, 0);
  
   srand(time(0));
   initialize_cells();

    signal(SIGINT, cancel_handler);

    autoModeHandler();

   while (keepRunning)
   {

      occupied_cells = count_cells();
      display_cells(occupied_cells);

      // Leave loop if there are no more free cells or a stable/oscillating state is reached
      if (occupied_cells == (FieldHeight*FieldWidth) || Flag_stable == 1 || Flag_oscillating2 == 1 || Flag_oscillating3 == 1)
         break;


      if (keepRunning) {
        if (AutoMode == 0)
        {   
            printf("Press enter to show next Gen.\n");
            getchar();
        }
        else
        {
            printf("Autoplay... Just sit, have a cup of tea and wait.\n");
            sleep(1);
        }
        evolution_step();
      }

   }
}

void autoModeHandler() {
    printf("Should the programm wait for input? (Y/n)");
    char key = getchar();
    switch (key) {
    case 'n':
    case 'N':
        printf("AutoMode on!\n");
        AutoMode = 1;
        break;
    default:
        printf("AutoMode off!\n");
        AutoMode = 0;
        break;
    }
}

void cancel_handler() {
    keepRunning = 0;
    printf("Exiting...");
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
         last_cell_states[0][i][j] = last_cell_states[1][i][j] = last_cell_states[2][i][j] = 0;
         rnd = rand() % max_active_rand;
         if (rnd < round(max_active_rand - 1))
         {
            cells[i][j] = last_cell_states[0][i][j] = 0;
         }
         else
         {
            cells[i][j] = last_cell_states[0][i][j] = 1;
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
   char output[5000];
   int outputIndex = 0;

   system("CLS"); // Clear screen - works (at least) on windows console.
//    printf("%c",201);
   output[outputIndex++] = 201;
   for (i=0; i<FieldWidth; i++) {
    //   printf("%c%c%c",205,205,205);
      output[outputIndex++] = 205;
      output[outputIndex++] = 205;
      output[outputIndex++] = 205;
   }
//    printf("%c\n",187);
   output[outputIndex++] = 187;
   output[outputIndex++] = '\n';
   
   for (i = 0; i < FieldHeight; i++)
   {
    //   printf("%c",186);
      output[outputIndex++] = 186;
      for (j = 0; j < FieldWidth; j++)
      {
         
         switch(cells[i][j])
         {
            case 0:
            {
            //    printf("   ");
                output[outputIndex++] = ' ';
                output[outputIndex++] = ' ';
                output[outputIndex++] = ' ';
               break;
            }
            case 1:
            {
            //    printf(" %c ",248);
               
                output[outputIndex++] = ' ';
                output[outputIndex++] = 248;
                output[outputIndex++] = ' ';
               break;
            }
            default:
            {
            //    printf(" E ");
               
                output[outputIndex++] = ' ';
                output[outputIndex++] = 'E';
                output[outputIndex++] = ' ';
               break;
            }
         }
      }
    //   printf("%c\n",186);
      
      output[outputIndex++] = 186;
      output[outputIndex++] = '\n';
      //printf("%s\n", str);
      
   }
//    printf("%c",200);
      output[outputIndex++] = 200; 
   for (i=0; i<FieldWidth; i++) {
    //   printf("%c%c%c",205,205,205);
    
        output[outputIndex++] = 205;
        output[outputIndex++] = 205;
        output[outputIndex++] = 205;
   }
//    printf("%c\n",188);

    output[outputIndex++] = 188;
    output[outputIndex++] = '\n';

    // printf("%s", output);
    puts(output); // Use puts for faster printing. Writing to string and using printf is not faster (not "flicker-free")

   printf("Currently showing Gen.: %i with %i occupied Cells.\n", cell_generation, occupied_cells);
   if (Flag_stable == 1)
   {
      printf("Stable state reached. Cells will move no further.\n");
   }
   if (Flag_oscillating2 == 1)
   {
      printf("Oscillating state reached. Cells will oscillate between current and last state.\n");
   }
   if (Flag_oscillating3 == 1)
   {
      printf("Oscillating state reached. Cells will oscillate between the last three states.\n");
   }
   printf("\n");
}  

void evolution_step()
{
   char NextGen[FieldHeight][FieldWidth];
   int i,j,k,l;
   for (i=0; i < FieldHeight; i++){
      for (j=0; j < FieldWidth; j++){

         int NachbarnLebend = 0;

         for (int k=-1; k<=1; k++){
            for (int l=-1; l <= 1; l++){
               if ((i+k >= 0) && (i+k < FieldHeight) && (j+l >= 0) && (j+l < FieldWidth)){
                     NachbarnLebend += cells[i+k][j+l];
               }
            }
         }
         NachbarnLebend -= cells[i][j];

         if ((cells[i][j] == 1 && NachbarnLebend < 2 ) || (cells[i][j] == 1 && NachbarnLebend > 3 ))
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
   for (i=0; i < FieldHeight; i++){
      for (j=0; j < FieldWidth; j++){
         cells[i][j] = NextGen[i][j];
      }
   }

   check_stable();
   cell_generation++;
}  

void check_stable() //last_cell_states[2] -> Vorletzter Move, last_cell_states[1] -> letzter Move, last_cell_states[0] -> aktueller Move
{   
   int i, j, dif_buffer1, dif_buffer2, dif_buffer3, Difference[1][FieldHeight][FieldWidth]; //Difference[0][][] -> aktueller <> letzter (stable), Difference[1][][] -> aktueller <> vorletzter Move (oscillating)
   dif_buffer1 = dif_buffer2 = dif_buffer3 = 0;
   if (cell_generation >= 3)
   {
      //printf("checking for stable or oscillating states...\n");
      for (i=0; i < FieldHeight; i++)
      {
         for (j=0; j < FieldWidth; j++)
         {
            last_cell_states[3][i][j]=last_cell_states[2][i][j];
            last_cell_states[2][i][j]=last_cell_states[1][i][j];
            last_cell_states[1][i][j]=last_cell_states[0][i][j];
            last_cell_states[0][i][j]=cells[i][j];
         }

      }
      for (i=0; i < FieldHeight; i++)
      {
         for (j=0; j < FieldWidth; j++)
         {
            //printf(" %c ", last_cell_states[2][i][j]);

            if (last_cell_states[0][i][j] == last_cell_states[1][i][j])
               {
                  dif_buffer1++;
               }
            if (last_cell_states[0][i][j] == last_cell_states[2][i][j])
               {
                  dif_buffer2++;
               }

               if (last_cell_states[0][i][j] == last_cell_states[3][i][j])
               {
                  dif_buffer3++;
               }
         }
         
      }
   //printf("dif_buffer1: %i, dif_buffer2: %i\n", dif_buffer1, dif_buffer2);


      if (dif_buffer1 == (FieldHeight*FieldWidth))
      {
         Flag_stable = 1;
      }

      if (dif_buffer2 == (FieldHeight*FieldWidth))
      {
         Flag_oscillating2 = 1;
      }

      if (dif_buffer3 == (FieldHeight*FieldWidth))
      {
         Flag_oscillating3 = 1;
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

      
