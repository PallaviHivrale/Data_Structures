////////////////////////////////////////////////////////////////////
//
//  Write a program which search Last occurrence of particular 
//       element from singly linear linked list.
//  
//  Input linked list: |10|->|20|->|30|->|40|->|50|->|30|->|70|
//  Input element: 30
//
//  Output: 6
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

    if(*first == NULL)
    {
        *first = newn;
    }
    else
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
        printf("|%d|->", first->data);
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

int SearchLastOcc(PNODE first, int no)
{
    int iPos = 0;
    int iCnt = 1;

    while(first != NULL)
    {
        if(first->data == no)
        {
            iPos = iCnt;   // Correct variable name
        }
        iCnt++;
        first = first->next;
    }
    return iPos;           // Correct variable name
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertLast(&head,10);
    InsertLast(&head,20);
    InsertLast(&head,30);
    InsertLast(&head,40);
    InsertLast(&head,50);
    InsertLast(&head,30);
    InsertLast(&head,70);

    Display(head);

    iRet = SearchLastOcc(head,30);

    printf("Last occurrence position is : %d\n", iRet);


    return 0;
}

