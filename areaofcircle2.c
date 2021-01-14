#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, float* b)
{
  if (argc >= 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%f", b);
  }
}

// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main
float areaOfCircle(float radius)
{
  float area;
  float pi = M_PI;
  area = radius*radius*pi;
  return area;
}

int main(int argc, char* argv[])
{
  char input[256];
  float start;
  float end;

  int reps = 3;
  float inc;

  getTestInput(argc, argv, &start, &end);

  if (argc <= 2)
  {
  	printf("Enter Start Radius:\n");
	while (1)
	{
		fgets(input, 256, stdin);
     		if (sscanf(input, "%f", &start) == 1 && start > 0) break;
	  	printf("ERROR - TRY AGAIN\n");
  	}

  	printf("Enter End Radius:\n");
  	while (1)
  	{
		fgets(input, 256, stdin);
		if (sscanf(input, "%f", &end) == 1 && end > start) break;
		printf("ERROR - TRY AGAIN\n");
	}
  }

  inc = (end - start) / reps;
  // for testing only - do not change
  //getTestInput(argc, argv, &start, &reps);

  printf("Calculating area of circle starting at %f, and ending at %f\n", start, end);

  // add your code below to call areaOfCircle function with values between
  // start and end
  for (float i = 0; i <= reps; i++)
  {
	printf("Radius: %f -> Area: %f\n", start+(i*inc), areaOfCircle(start+(i*inc)));
  }

}
