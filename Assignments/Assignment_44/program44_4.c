////////////////////////////////////////////////////////////////////
//
//  count frequency of given number
//  (count how many times a number appears)
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

int Frequency(PNODE Head, int no)
{
    int iCount = 0;
    PNODE temp = Head;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            iCount++;
        }
        temp = temp->next;
    }
    return iCount;
}

int main()
{
    PNODE head = NULL;
    int no = 0;

    InsertLast(&head,11);
    InsertLast(&head,22);
    InsertLast(&head,17);
    InsertLast(&head,11);
    InsertLast(&head,22);

    printf("Linked list: ");
    Display(head);

    printf("Enter element to count frequency : ");
    scanf("%d",&no);

    int Freq = Frequency(head, no);
    
    printf("Frequency of element %d in the list: %d\n", no, Freq);

    return 0;
}