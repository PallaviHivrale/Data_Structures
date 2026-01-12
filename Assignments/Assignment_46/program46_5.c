////////////////////////////////////////////////////////////////////
//
//  Increment each node value by 1
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

void IncrementAll(PNODE Head)
{
    while (Head != NULL)
    {
        Head->data++;
        Head = Head->next; 
    }
}

int main()
{
    PNODE head = NULL;
    

    InsertLast(&head,10);
    InsertLast(&head,20);
    InsertLast(&head,30);
    InsertLast(&head,5);
    InsertLast(&head,40);

    printf("original Linked List :\n ");
    Display(head);

    IncrementAll(head);

    printf("After Incrementing:\n");
    Display(head);
    
    return 0;
}