
//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{

  Student* st = (Student*)malloc(sizeof(Student));

  st->firstName = (char*)malloc(strlen(fname)+1);
  st->lastName = (char*)malloc(strlen(lname)+1);

  strcpy(st->firstName, fname);
  strcpy(st->lastName, lname);
  st->age = age;
  st->id = id;

  students[numStudents] = st;

  numStudents++;

  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student->firstName);
  free(student->lastName);
  free(student);

}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0

  for(int i = 0; i < numStudents; i++)
  {
	deleteStudent(students[i]);
	students[i] = 0;
  }
  numStudents = 0;
}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234
  //       james dean 21 2345
  //       katy jones 18 4532
  // the best way to do this is to convert the student data to a string using sprintf and then
  // (optionally) encrypt the whole string before writing it to disk (see cdemo/fileio3.c)

  char* FILE_NAME = "studentdata.txt";
  FILE* fp;

  fp = fopen(FILE_NAME, "w");
  if(fp)
  {
    for (int i = 0; i < numStudents; i++)
    {
	int k[1];
	k[0] = key;

	encrypt(students[i]->firstName, k, 1);
	encrypt(students[i]->lastName, k, 1);

	char age[256];
	char id[256];

	sprintf(age, "%d", students[i]->age);
	sprintf(id, "%ld", students[i]->id);

	encrypt(age, k, 1);
	encrypt(id, k, 1);

	printf("saving: %s %s %s %s\n", students[i]->firstName, students[i]->lastName, age, id);
	fprintf(fp, "%s %s %s %s\n", students[i]->firstName, students[i]->lastName, age, id);
    }

  fclose(fp);
  }
}

void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory
  //  - make sure you first deleteStudents before loading new ones
  //  - when loading it is best to load data into four strings and then (optionally) decrypt the
  //    strings
  //  - call createStudent to correctly create the students

  if (numStudents > 0)
  {
  	deleteStudents();
  }

  char* FILE_NAME = "studentdata.txt";
  FILE* fp;
  fp = fopen(FILE_NAME, "r");

  if (fp)
  {
    char b1[256];
    char b2[256];
    char b3[256];
    char b4[256];
    int age;
    long int id;
    numStudents = 0;
    int match;
    do
    {

    	  match = fscanf(fp, "%s %s %s %s", b1, b2, b3, b4);

	  if (match > 0)
	  {

	  int k[1];
	  k[0] = key;

	  decrypt(b1, k, 1);
	  decrypt(b2, k, 1);
	  decrypt(b3, k, 1);
	  decrypt(b4, k, 1);

	  sscanf(b3, "%d", &age);
	  sscanf(b4, "%ld", &id);
	  createStudent(b1, b2, age, id);
	  }
    }
    while (match > 0);
	fclose(fp);
  }
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}
