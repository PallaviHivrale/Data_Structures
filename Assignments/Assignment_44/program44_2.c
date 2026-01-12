////////////////////////////////////////////////////////////////////
//
//  count nodes containing even values
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
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = (*Head);
        (*Head) = newn;
    }
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf(" |%d|-> ", Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

int CountEven(PNODE Head)
{
    int Count = 0;
    PNODE temp = Head;

    while(temp != NULL)
    {
        if(temp->data %2 == 0)
        {
            Count++;
        }
        temp = temp->next;
    }
    return Count;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,11);
    InsertFirst(&head,22);
    InsertFirst(&head,17);
    InsertFirst(&head,40);
    InsertFirst(&head,78);

    Display(head);

    iRet =CountEven(head);
    printf("Number of nodes with even values : %d\n",iRet);

    return 0;
}