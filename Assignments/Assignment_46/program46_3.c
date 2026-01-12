////////////////////////////////////////////////////////////////////
//
//  check whether list is empty (return true if list is empty)
//
////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool IsEmpty(PNODE head)
{
    if(head == NULL)
    {
        printf("Linked List is Empty\n");
        return true;
    }
    else
    {
        printf("Linked List is not empty\n");
        return false;
    }
}

int main()
{
    PNODE head = NULL;

    InsertLast(&head,10);
    InsertLast(&head,20);
    InsertLast(&head,30);
    InsertLast(&head,20);
    InsertLast(&head,40);

    printf("Linked List : ");
    Display(head);
    
    IsEmpty(head);
   
    return 0;
}