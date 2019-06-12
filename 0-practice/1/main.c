#include <stdio.h>
#include <stdlib.h>

#include "add.h"

int main()
{
  int a = 10, b = 5;
  int c = add(a, b);

  printf("c = %d\n", c);

  return 0;
}
