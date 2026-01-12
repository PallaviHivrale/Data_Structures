////////////////////////////////////////////////////////////////////
//
//  Write a program which Display all elements which are prime from
//  singly linear linked list.
//  
//  Input linked list: |11|->|20|->|17|->|41|->|22|->|89|
//
//  Output: 11  17  41  89
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

int IsPrime(int no)
{
    int i = 0;

    if(no<=1)
    {
        return 0;
    }

    for(i=2; i<= no/2; i++)
    {
        if(no % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void DisplayPrime(PNODE Head)
{
    while(Head!=NULL)
    {
        if(IsPrime(Head->data))
        {
            printf("%d ", Head->data);
        }
        Head = Head->next;
    } 
    printf("\n"); 
}
int main()
{
    PNODE head = NULL;

    InsertLast(&head, 11);
    InsertLast(&head, 20);
    InsertLast(&head, 17);
    InsertLast(&head, 41);
    InsertLast(&head, 22);
    InsertLast(&head, 89);

    Display(head);

    printf("prime number are : ");
    DisplayPrime(head);

    return 0;
}
