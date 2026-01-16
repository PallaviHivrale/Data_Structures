////////////////////////////////////////////////////////////////////
//   Display prime number
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

// Function prototype (IMPORTANT)
bool IsPrime(int num);

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
        while(temp->next != NULL)        
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DisplayPrime(PNODE Head)
{
    printf("Prime numbers in the list: ");
    
    while(Head != NULL)
    {
        if(IsPrime(Head->data))  
        {
            printf("%d ", Head->data);
        }
        Head = Head->next;       
    }
    printf("\n");
}

bool IsPrime(int num)
{
    int i = 0;

    if(num <= 1)
    {
        return false;
    }

    for(i = 2; i <= num / 2; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("|%d|->", Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

int main()
{
    PNODE head = NULL;
    
    InsertLast(&head,10);
    InsertLast(&head,200);
    InsertLast(&head,305);
    InsertLast(&head,403);
    InsertLast(&head,50);
    InsertLast(&head,11);
    InsertLast(&head,17);

    printf("Original Linked List:\n");
    Display(head);

    DisplayPrime(head);
    
    return 0;
}
