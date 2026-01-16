////////////////////////////////////////////////////////////////////
//
//   sum of digit of each node
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

void SumDigits(PNODE Head)
{
    int iNo = 0;
    int Sum = 0;

    
    printf("\nsum of digit of each node:\n");

    while(Head != NULL)
    {
        iNo = Head->data;
        Sum = 0;

        while(iNo != 0)
        {
            Sum = Sum + (iNo % 10);
            iNo = iNo/10;
        }
        printf("Number : %d  Sum of digits : %d\n", Head->data, Sum);
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
    InsertLast(&head,403);
    InsertLast(&head,50);

    
    Display(head);

    SumDigits(head);
    
    return 0;
}