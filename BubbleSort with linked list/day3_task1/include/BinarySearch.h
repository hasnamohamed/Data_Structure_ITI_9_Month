#ifndef BINARYSEARCH_H_INCLUDED
#define BINARYSEARCH_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;

struct Node
{
    int Data;
    Node *Prev, *Next;
};

typedef struct LinkedList
{
    Node *head, *tail;

}LinkedList;

Node *head = NULL, *tail = NULL;

//void Add(LinkedList *myList, int data)

void Add(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = newNode->Next = NULL;

    if(head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->Next = newNode;
        newNode->Prev = tail;
        tail = newNode;
    }
}
void Display()
{
    Node* current = head;

    while(current != NULL)
    {
        printf("%d   ", current->Data);
        current = current->Next;
    }
}
void BubbleSort()
{
    int sorted = 0;
    Node *current = head;
    while(current->Next != NULL && sorted == 0)
    {
        sorted = 1;
        Node *another = head;
        while(another->Next != NULL )
        {
            if(another->Data > another->Next->Data)
            {
                int temp=another->Data;
                another->Data=another->Next->Data;
                another->Next->Data=temp;
                sorted = 0;
            }
            another = another->Next;
        }
        current = current->Next;
    }
}
int GetCount(Node *hed,Node *til)
{
    int count=0;
    Node *current=hed;
    while(current!=til)
    {
        count+=1;
        current=current->Next;
    }
    return count+1;
}
Node* GetDataByIndex(int index,Node *hed,Node *til)
{
    int count=0;
    Node *current=hed;
    if(hed==til)
        return hed;
    while(index!=count)
    {
        count++;
        current=current->Next;
    }
    return current;
}
int BinarySearch(int item)
{
    Node *midIndex;
    Node *minIndex = head;
    Node *maxIndex = tail;
    int index=0;
    while(minIndex->Data <= maxIndex->Data)
    {
        int count=GetCount(minIndex,maxIndex);
        midIndex = GetDataByIndex(count/2,minIndex,maxIndex);
        if(item == midIndex->Data)
            return 1;

        if(item > midIndex->Data)
            minIndex = midIndex->Next;
        else
            maxIndex = midIndex->Prev;
    }

    return 0;
}


#endif // BINARYSEARCH_H_INCLUDED
