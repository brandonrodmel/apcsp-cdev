#include <stdio.h>



// student structure
//struct Student...
struct Student {
	char firstname[25];
	char lastname[25];
	int age;
	int id;
};

void printStudent(struct Student* student)
{
	printf("---- STUDENT ----\n");
	printf("Student: %s %s\n", student->firstname, student->lastname);
	printf("Age: %d\n", student->age);
	printf("ID: %d\n", student->id);
}


void printAllStudents(struct Student students[], int num)
{

  // call printStudent for each student in students
  //if (numStudents > 0)
  //{
	for (int i = 0; i < num; i++)
	{
		printStudent(students+i);
 	}
  //}
}


int main()
{

  // an array of students
  //xxx students;
  int numStudents = 0;
  struct Student students[5];

  char input[256];
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q')
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student

	printf("First Name: ");
	fgets(input, 256, stdin);
	sscanf(input, "%s", &students[numStudents].firstname);

	printf("Last Name: ");
	fgets(input, 256, stdin);
	sscanf(input, "%s", &students[numStudents].lastname);

	printf("Enter Age: ");
	fgets(input, 256, stdin);
	sscanf(input, "%d", &students[numStudents].age);

	printf("Enter ID: ");
	fgets(input, 256, stdin);
	sscanf(input, "%d", &students[numStudents].id);

	numStudents++;
    }
  }
  printf("\nGoodbye!\n");
}
