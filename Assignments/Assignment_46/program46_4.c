////////////////////////////////////////////////////////////////////
//
//  replace negative number with zero
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

void ReplaceNegative(PNODE Head)
{
    PNODE temp = Head;

    while (temp != NULL)
    {
        if(temp->data<0)
        {
            temp->data = 0;
        }  
        temp = temp->next;
    }
}

int main()
{
    PNODE head = NULL;

    InsertLast(&head,10);
    InsertLast(&head,-20);
    InsertLast(&head,30);
    InsertLast(&head,-5);
    InsertLast(&head,40);

    printf("original Linked List : ");
    Display(head);

    ReplaceNegative(head);

    printf("Modified List:");
    Display(head);
    
    return 0;
}