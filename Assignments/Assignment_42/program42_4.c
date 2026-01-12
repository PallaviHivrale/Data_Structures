////////////////////////////////////////////////////////////////////
//
//  Write a program which returns largest elements from
//  singly linear linked list.
//  
//  Input linked list: |110|->|230|->|320|->|240|
//
//  Output: 320
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

int Maximum(PNODE Head)
{
    int Max = Head->data;

    while(Head != NULL)
    {
        if(Head-> data>Max)
        {
            Max = Head->data;
        }
        Head = Head->next;
    }
    return Max;
}
int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertLast(&head, 110);
    InsertLast(&head, 230);
    InsertLast(&head, 320);
    InsertLast(&head, 240);

    Display(head);

    iRet = Maximum(head);
    printf("largest elements is : %d\n", iRet);

    return 0;
}
