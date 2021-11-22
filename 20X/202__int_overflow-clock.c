/* check_int_overflow.c Check when integer numbers are overflowing */
// TO DO 1: complete the overflow detecion for other types 
// TO DO 2: extend this to unsigned integers 
// TO DO 3: stop counting after first overflow 
// TO DO 4: estimate how many operations are performed per second.
// TO DO 5 (optional): Use this program as benchmark for your CPU performance and compare it with other students' computers,
// TO DO 6 (optional): Check the CPU load when running the programm. What do you observe? 

#include <stdio.h>
#include <time.h>

char c, old_c, flag_c;
__int16 i16, old_i16, flag_i16;
short s, old_s, flag_s;
int i, old_i,flag_i;
unsigned int ui, old_ui,flag_ui;
long l, old_l, flag_l;
int done=0;
clock_t t1, t2;

void OVFLC();

int main() 
{
   setvbuf (stdout, NULL, _IONBF, 0);

   c=i16=i=l=s=ui=0;
   t1=clock();

   while(done < 6) {

      OVFLC();

   }

   t2=clock();
   printf("%g seconds\n", (double)(t2-t1) / CLOCKS_PER_SEC);
	getchar();
}

void OVFLC(){
   old_c=c; old_i16=i16; old_i=i; old_l=l; old_s=s; old_ui=ui;
   c++; i16++; i++; l++; s++; ui++;
   if (done < 1 && old_c>c){printf("char  overflow %d -> %d \n", old_c, c); done++;}
   if (done < 2  && old_i16>i16){printf("int16  overflow %d -> %d \n", old_i16, i16); done++;}
   if (done < 3 && old_s>s){printf("short  overflow %d -> %d \n", old_s, s); done++;}
   if (done < 4  && old_i>i){printf("int  overflow %d -> %d \n", old_i, i); done++;}
   if (done < 5 && old_l>l){printf("long  overflow %d -> %d \n", old_l, l); done++;}
   if (done < 6 && old_ui>ui){printf("unsigned int  overflow %u -> %u \n", old_ui, ui); done++;}
}