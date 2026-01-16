////////////////////////////////////////////////////////////////////
//
//  count digit of each node
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


void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    
    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next !=NULL)        
        {
            temp = temp->next;
        }
        temp->next = newn;
        
    }
}

void CountDigits(PNODE Head)
{
    while(Head != NULL)
    {
        int No = Head->data;
        int Count = 0;

        if(No == 0)
        {
            Count = 1;
        }
        else
        {
            if(No < 0)
            {
                No = -No;
            }

            while(No != 0)
            {
                Count++;
                No/=10;
            }
        }
        printf("Number: %d, Digits: %d\n", Head->data, Count);

        Head = Head->next;
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

int main()
{
    PNODE head = NULL;
    
    InsertLast(&head,10);
    InsertLast(&head,200);
    InsertLast(&head,305);
    InsertLast(&head,40345);
    InsertLast(&head,50);

    printf("original Linked List :\n ");
    Display(head);

    printf("\nDigit Count of each node:\n");
    CountDigits(head);
    
    return 0;
}