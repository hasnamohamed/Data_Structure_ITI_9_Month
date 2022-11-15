#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main()
{
    //LinkedList myList = {.head = NULL, .tail = NULL};
    //Add(&myList, 3);
    Add(3);
    Add(5);
    Add(7);
    Add(9);
    InsertAfter(4,9);
    Display();
    int count=GetCount();
    printf("\ncount is %i",count);
    int data= GetDataByIndex(3);
    printf("\nData is %i",data);
    return 0;
}
