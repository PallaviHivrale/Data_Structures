////////////////////////////////////////////////////////////////////
//
//  return position of first occurance
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
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = (*first);
        *first = newn;
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

int FirstOccurance(PNODE Head, int no)
{
    PNODE temp = Head;
    int iCount = 1;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            return iCount;
        }
        iCount++;
        temp = temp->next;
    }
    return -1;
}

int main()
{
    PNODE head = NULL;
    int no = 0;
    int iPos = 0;

    InsertFirst(&head,11);
    InsertFirst(&head,22);
    InsertFirst(&head,17);
    InsertFirst(&head,51);
    InsertFirst(&head,88);

    printf("Linked List : ");
    Display(head);

    printf("Enter element to find first occurrence: ");
    scanf("%d", &no);

    iPos = FirstOccurance(head,no);
    
    if(iPos == -1)
    {
        printf("Element %d not found in the linked list\n", no);
    }
    else
    {
        printf("First occurrence of %d is at position %d\n", no, iPos);
    }


    return 0;
}