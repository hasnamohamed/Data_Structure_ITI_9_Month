#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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

Node* GetNodeByData(int data)
{
    Node *current = head;

    while(current != NULL)
    {
        if(data == current->Data)
            return current;

        current = current->Next;
    }

    return NULL;
}

void Remove(int data)
{
    Node *node = GetNodeByData(data);

    if(node == NULL)
        return;

    if(node == head)
    {
        if(head == tail)
        {
            head = tail = NULL;
        }
        else
        {
           head =  head->Next;
           head->Prev = NULL;
        }
    }
    else if(node == tail)
    {
        tail = tail->Prev;
        tail->Next = NULL;
    }
    else
    {
        node->Prev->Next = node->Next;
        node->Next->Prev = node->Prev;
    }

    free(node);
}

void InsertAfter(int data, int afterData)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data=data;
    Node *current=head;
        while(current!=NULL)
        {
            if(current->Data==afterData)
            {
                if(current==tail)
                {
                    tail->Next=newNode;
                    tail=newNode;
                    newNode->Next=NULL;
                }
                else
                {
                    newNode->Prev=current;
                    Node *B=current->Next;
                    current->Next=newNode;
                    B->Prev=newNode;
                    newNode->Next=B;
                }
                break;
            }
            current=current->Next;

        }
    /*Node *newNode = malloc(sizeof(Node));
    newNode->Data=data;
    Node *node = GetNodeByData(afterData);
    if(node==tail)
    {
        tail->Next=newNode;
        tail=newNode;
        newNode->Next=NULL;
    }
    else
    {
        newNode->Prev=node;
        Node *B=node->Next;
        node->Next=newNode;
        B->Prev=newNode;
        newNode->Next=B;
    }*/
}

int GetDataByIndex(int index)
{
    int count=0;
    Node *current=head;
    while(current!=NULL)
    {
        if(index==count)
            return current->Data;
        count++;
        current=current->Next;
    }
}

int GetCount()
{
    int count=0;
    Node *current=head;
    while(current!=NULL)
    {
        count+=1;
        current=current->Next;
    }
    return count;
}


Node* Reverse()
{

}

void InPlaceReverse()
{

}


#endif // LINKEDLIST_H
