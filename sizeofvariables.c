#include<stdio.h>

int main()
{
  int a = 545;
  char c = 'b';
  float f = 54.35;
  double d = 563.426;
  unsigned int i = -7;
  short int j = 5400;

  // print value and size of an int variable
  printf("int a value: %d and size: %d bytes\n", a, sizeof(a));

  printf("char c value: %c, and size: %lu bytes\n", c, sizeof(c));

  printf("float f value: %f, and size: %lu bytes\n", f, sizeof(f));

  printf("double d value: %f, and size: %lu bytes\n", d, sizeof(d));

  printf("unsigned int i value: %d, and size %d bytes\n", i, sizeof(i));

  printf("short int j value: %d, and size %d bytes\n", j, sizeof(j));

}

