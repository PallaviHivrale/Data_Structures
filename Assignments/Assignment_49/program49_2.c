////////////////////////////////////////////////////////////////////
// Check Whether all elements are positive
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

bool CheckAllPositive(PNODE Head)
{
    while(Head != NULL)
    {
        if(Head->data < 0)
        {
           return false; 
        }
        Head = Head->next;
    }
    return true;
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
    bool bRet = false;
    
    InsertLast(&head,11);
    InsertLast(&head,20);
    InsertLast(&head,31);
    InsertLast(&head,40);
    InsertLast(&head,55);

    printf("Linked List:\n");
    Display(head);

    bRet = CheckAllPositive(head);
    
    if(bRet == 1)
    {
        printf("All elements are positive\n");
    }
    else
    {
        printf("all elements are Not positive\n");
    }
    
    return 0;
}