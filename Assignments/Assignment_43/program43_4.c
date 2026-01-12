////////////////////////////////////////////////////////////////////
//
//  Write a program which return second maximum element  from
//  singly linear linked list.
//  
//  Input linked list: |110|->|230|->|320|->|240|
//
//  Output: 240
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

int SecMaximum(PNODE Head)
{
    int Max = 0;
    int SecMax = 0;

    if(Head == NULL || Head->next == NULL) // LL is empty or only one node
    {
        return -1;
    }
    Max = SecMax = Head->data;
    Head = Head->next;

    while(Head!=NULL)
    {
        if(Head->data>Max)
        {
            SecMax = Max;
            Max = Head->data;
        }
        else if(Head->data > SecMax && Head->data != Max)
        {
            SecMax = Head->data;
        }
        Head = Head->next;
    } 
    return SecMax;
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

    iRet = SecMaximum(head);
    printf("second maximum element is : %d\n ",iRet);

    return 0;
}
