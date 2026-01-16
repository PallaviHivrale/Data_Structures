////////////////////////////////////////////////////////////////////
// count two digit number
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

int CountTwoDigit(PNODE Head)
{
    PNODE temp = Head;
    int iCount = 0;

    while(temp != NULL)
    {
        if(temp->data >10 && temp->data<=99)
        {
          iCount++; 
        }
        temp = temp->next;
    }
    return iCount;
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
    int iCount = 0;
    
    InsertLast(&head,21);
    InsertLast(&head,20);
    InsertLast(&head,105);
    InsertLast(&head,40);
    InsertLast(&head,555);

    Display(head);

    iCount = CountTwoDigit(head);
    printf("Number of Two digit element : %d\n", iCount);
    
    return 0;
}