#include <stdio.h>
#include <string.h>

int main()
{
  char alpha1[27];

  for (int i = 0; i < 26; i++)
  {
	char c = 97;
	alpha1[i] = c + i;
  }

  alpha1[26] = '\0';

  char alpha2[] = "abcdefghijklmnopqrstuvwxyz";

  if (strcmp(alpha1, alpha2) == 0)
	printf("strings are the same\n");
  else
	printf("strings are different\n");

  for (int i = 0; i < 26; i++)
  {
	alpha1[i] -= 32;
  }

  if (strcmp(alpha1, alpha2) == 0)
	printf("strings are now the same\n");
  else
	printf("strings are now different\n");

  char alpha3[53];

  strcpy(alpha3, alpha1);
  strcat(alpha3, alpha2);

  printf("alpha1: %s\n", alpha1);
  printf("alpha2: %s\n", alpha2);
  printf("alpha3: %s\n", alpha3);
}
