#include <stdio.h>
#include <stdlib.h>
#include "BinarySearch.h"

int main()
{
   Add(7);
   Add(4);
   Add(5);
   Add(3);
   Add(1);
   Display();
   printf("\n");
   BubbleSort();
   Display();
  int index= BinarySearch(9);
  printf("\nindex = %i",index);
    return 0;
}
