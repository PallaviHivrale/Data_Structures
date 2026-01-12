////////////////////////////////////////////////////////////////////
//
//  Write a program which returns addition of all elements from
//  singly linear linked list.
//  
//  Input linked list: |10|->|20|->|30|->|40|
//
//  Output: 100
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

int Addition(PNODE first)
{
    int Sum = 0;

    while(first != NULL)
    {
        Sum = Sum + first->data;
        first = first->next;
    }
    return Sum;
}
int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertLast(&head, 10);
    InsertLast(&head, 20);
    InsertLast(&head, 30);
    InsertLast(&head, 40);

    Display(head);

    iRet = Addition(head);
    printf("Addition of all elements is : %d\n", iRet);

    return 0;
}
