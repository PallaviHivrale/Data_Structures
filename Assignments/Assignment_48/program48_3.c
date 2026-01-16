////////////////////////////////////////////////////////////////////
//  Multiply Each element by 2 
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

void MultiplyByTwo(PPNODE Head)
{
    PNODE temp = *Head;

    while(temp != NULL)
    {
        temp->data = temp->data*2;    
        temp = temp->next;
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
    
    InsertLast(&head,11);
    InsertLast(&head,20);
    InsertLast(&head,31);
    InsertLast(&head,40);
    InsertLast(&head,55);

    printf("Before replace:\n");
    Display(head);

    MultiplyByTwo(&head);

    printf("After Replace:\n");
    Display(head);
    
    return 0;
}