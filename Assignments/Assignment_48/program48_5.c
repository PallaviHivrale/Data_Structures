////////////////////////////////////////////////////////////////////
// Display element at Odd position
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

void DisplayOddPosition(PNODE Head)
{
    PNODE temp = Head;
    int pos = 1;

    while(temp != NULL)
    {
        if(pos%2 != 0)
        {
            printf(" %d",temp->data);
        }    
        pos--;
        temp = temp->next;
    }
    printf("\n");
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("| %d|->", Head->data);
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

    printf("Linked List:\n");
    Display(head);

    printf("Element at odd position:");
    DisplayOddPosition(head);
    
    return 0;
}