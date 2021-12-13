/* address_list.c */
// This program should be completed such that it maintains a list of students
// **TO DO 1: Write a function inputStudent(int i), which allows the user to enter first name and last name and stores it at position i in the array.
// **TO DO 2: Use a variable to count the number of students stored in the array.
// **TO DO 3: Write a function printStudent(i), which prints student i stored in the array
// **TO DO 4: Write functions addStudent(), for adding a student at the end of the array, and printAllStudents() for printing all students stored.
// **TO DO 5: Write a function menu(), which allows the user to select one of the actions
//            - add Student
//            - print all students
//            - quit program
// TO DO 6: Extend the student data and the corresponding functions with the gender male/female (using "enum").
// TO DO 7: Create a structure for handling dates (day, month, year) and use it for birth date, date of enrollment etc. 
// TO DO 8: Extend the program such it also handles address information (street, number, zip-code and city).
// TO DO 9: optional: Add a function and menu item for deleting a selected student.
// TO DO 10: optional: Add a function to sort the data according to given criteria

#include <stdio.h>
#include <stdlib.h>

#define MAX_IDS 100

void inputStudent(int i);
void initializeArrays();
void printStudent(int i);
void addStudent();
void printAllStudents();
void menu();

int used_ids[MAX_IDS];
int last_id;
enum gender{
   male,
   female,
   diverse,
};
struct person
{
   char first_name[30];
   char last_name[30];
   int id;
   enum gender student_gender;
};

struct person students[MAX_IDS];

int main()
{
   initializeArrays();
   menu();
   printf("Bye");
}

void menu(){
   int input;
   while(1){
      system("cls");
      printf("Welcome to your personal Student Manager.\n");
      printf("Please enter the Number for what you would like to do\n");
      printf("1. Add a Student\n");
      printf("2. Print a Student\n");
      printf("3. Print all Students\n");
      printf("4. Exit the Programm\n");
      scanf("%d", &input);
      system("cls");

      switch (input)
      {
      case 1:
         addStudent();
         break;
      case 2:
         printf("What's the Students ID?");
         scanf("%d", &input);
         printStudent(input);
         break;
      case 3:
         printAllStudents();
         break;
      case 4:
         exit(0);
         break;
      default:
         printf("error");
         break;
      }
   }
}

void initializeArrays(){

   int k=0,l=0;
   for (k; k<MAX_IDS; k++){
      used_ids[k] = 0;
   }

}

void addStudent(){
   int i = 0;
   while (used_ids[i] != 0){
      i++;
   }
   used_ids[i] = 1;
   last_id = i;
   inputStudent(i);
   students[i].id = i;
}

void inputStudent(int i){

   printf("Please enter the Students first name:"); //WTF Ich weiß nicht warum, aber der erste wird immer übersprungen???
   gets(students[i].first_name);

   system("cls");

   printf("Please enter the Students first name:");
   gets(students[i].first_name);

   system("cls");

   printf("Please enter the Students last name:");
   gets(students[i].last_name);

   system("cls");

   int g;
   printf("Please enter the Students Gender\n");
   printf("1. Male 2.Female 3.Diverse:");
   scanf("%d", g);

   switch (g)
   {
   case 1:
      students[i].student_gender = male;
      break;
   
   case 2:
      students[i].student_gender = female;
      break;
   
   case 3:
      students[i].student_gender = diverse;
      break;
   
   default:
      students[i].student_gender = male;
      break;
   }

   system("cls");
}

void printStudent(int i){
   system("cls");
   printf("Here you go:\n");
   printf("ID: %d First Name: %s Last Name: %s Gender:%s\n",students[i].id, students[i].first_name, students[i].last_name, students[i].student_gender);
   system("pause");
}

void printAllStudents(){
   system("cls");
   printf("Here you go:\n");
   for (int k=0; k<=last_id; k++){
      printf("ID: %d First Name: %s Last Name: %s Gender:%s\n",students[k].id, students[k].first_name, students[k].last_name, students[k].student_gender);
   }
   system("pause");
}