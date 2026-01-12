////////////////////////////////////////////////////////////////////
//
//  count elements greater than given number
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

int CountGreater(PNODE head, int no)
{
    PNODE temp = head;
    int iCount = 0;

    while (temp != NULL)
    {
        if(temp->data>no)
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
    int iRet = 0;
    int no = 0;

    InsertLast(&head,10);
    InsertLast(&head,20);
    InsertLast(&head,30);
    InsertLast(&head,20);
    InsertLast(&head,40);

    printf("Linked List : ");
    Display(head);

    printf("Enter number: ");
    scanf("%d", &no);

    iRet = CountGreater(head, no);
    printf("Count of element greater than %d is: %d\n",no,iRet);
    

    return 0;
}