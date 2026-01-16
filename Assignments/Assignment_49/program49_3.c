////////////////////////////////////////////////////////////////////
// Display element divisible by 3
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

void DisplayDivByThree(PNODE Head)
{
    PNODE temp = Head;

    printf("Elements divisible by 3: ");
    while(temp != NULL)
    {
        if(temp->data %3 == 0)
        {
          printf(" %d",temp->data); 
        }
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
    
    InsertLast(&head,21);
    InsertLast(&head,20);
    InsertLast(&head,30);
    InsertLast(&head,40);
    InsertLast(&head,55);

    DisplayDivByThree(head);
    
    return 0;
}