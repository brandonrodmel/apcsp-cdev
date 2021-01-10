#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

  float d = 5.2346;
  float* ptrtod = &d;

  float e = 4.2064;
  float* ptrtoe = &e;

  printf("The value of d is %f and the address is %p\n", d, (void*)ptrtod);

  printf("The value of e is %f and the address is %p\n", e, (void*)ptrtoe);

  float temp;

  temp = *ptrtod;
  *ptrtod = *ptrtoe;
  *ptrtoe = temp;

  printf("The new value of d is %f\n", d);
  printf("The new value of e is %f\n", e);
}
