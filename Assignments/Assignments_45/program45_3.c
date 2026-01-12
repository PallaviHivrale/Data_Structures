////////////////////////////////////////////////////////////////////
//
//  return position of last occurrence
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

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = *first;
    *first = newn;
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

int LastOccurance(PNODE Head, int no)
{
    int iPos = -1;
    int iCount = 1;

    while(Head != NULL)
    {
        if(Head->data == no)
        {
            iPos = iCount;
        }
        iCount++;
        Head = Head->next;
    }
    return iPos;
}

int main()
{
    PNODE head = NULL;
    int no = 0;
    int iPos = 0;

    InsertFirst(&head,11);
    InsertFirst(&head,22);
    InsertFirst(&head,17);
    InsertFirst(&head,22);
    InsertFirst(&head,88);

    printf("Linked List : ");
    Display(head);

    printf("Enter element to find last occurrence: ");
    scanf("%d", &no);

    iPos = LastOccurance(head, no);

    if(iPos == -1)
    {
        printf("Element %d not found in the linked list\n", no);
    }
    else
    {
        printf("Last occurrence of %d is at position %d\n", no, iPos);
    }

    return 0;
}
