////////////////////////////////////////////////////////////////////
//
//  print elements less than X
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

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf(" |%d|-> ", Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

void DisplayLess(PNODE head, int X)
{
    PNODE temp = head;

    while (temp != NULL)
    {
        if(temp->data<X)
        {
            printf("%d ",temp->data);
        }  
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    PNODE head = NULL;
    int X   = 0;

    InsertLast(&head,10);
    InsertLast(&head,20);
    InsertLast(&head,30);
    InsertLast(&head,20);
    InsertLast(&head,40);

    printf("Linked List : ");
    Display(head);

    printf("Enter number: ");
    scanf("%d", &X);

    printf("Elements less than %d are: ", X);
    DisplayLess(head, X);

    return 0;
}