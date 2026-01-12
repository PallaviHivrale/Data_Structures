////////////////////////////////////////////////////////////////////
//
//  Write a program which return addition of all even element  from
//  singly linear linked list.
//  
//  Input linked list: |11|->|20|->|32|->|41|
//
//  Output: 52
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

int AdditionEven(PNODE Head)
{
    int Sum = 0;

    while(Head!=NULL)
    {
        if(Head->data % 2 == 0)
        {
            Sum = Sum + Head->data;
        }
        Head = Head->next;
    } 
    return Sum;
}
int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertLast(&head, 11);
    InsertLast(&head, 20);
    InsertLast(&head, 32);
    InsertLast(&head, 41);

    Display(head);

    iRet = AdditionEven(head);
    printf("sum of even element are : %d\n ",iRet);

    return 0;
}
