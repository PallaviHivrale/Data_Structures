////////////////////////////////////////////////////////////////////
//
//  Write a program which returns smallest elements from
//  singly linear linked list.
//  
//  Input linked list: |110|->|230|->|20|->|240|->|640|
//
//  Output: 20
//
////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertLast(PPNODE first, int no)
{
    PNODE temp = NULL;

    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)      //LL is empty
    {
        *first = newn;
    }
    else                     // LL has nodes
    {
        temp = *first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}

int Minimum(PNODE Head)
{
    int Min = Head->data;

    while(Head != NULL)
    {
        if(Head-> data<Min)
        {
            Min = Head->data;
        }
        Head = Head->next;
    }
    return Min;
}
int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertLast(&head, 110);
    InsertLast(&head, 230);
    InsertLast(&head, 20);
    InsertLast(&head, 240);
    InsertLast(&head, 640);

    Display(head);

    iRet = Minimum(head);
    printf("smallest elements is : %d\n", iRet);

    return 0;
}
