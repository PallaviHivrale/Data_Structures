////////////////////////////////////////////////////////////////////
//
//  print only even elements
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

void InsertLast(PPNODE Head, int no)
{
    PNODE temp = NULL;
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        temp = *Head;

        while(temp->next!= NULL)
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

void DisplayEven(PNODE Head)
{
    PNODE temp = Head;

    while(temp != NULL)
    {
        if(temp->data %2 == 0)
        {
            printf("%d\n",temp->data);
        }
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    PNODE head = NULL;

    InsertLast(&head,11);
    InsertLast(&head,22);
    InsertLast(&head,17);
    InsertLast(&head,11);
    InsertLast(&head,78);

    printf("Linked list: ");
    Display(head);

    printf("Even elements:\n");
    DisplayEven(head);

    return 0;
}