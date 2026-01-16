////////////////////////////////////////////////////////////////////
//   Count prime number
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

void InsertLast(PPNODE first, int no);
bool IsPrime(int no);
int CountPrime(PNODE Head);

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

bool IsPrime(int no)
{
    int i = 0;

    if(no < 2)
        return false;

    for(i = 2; i * i <= no; i++)
    {
        if(no % i == 0)
            return false;
    }
    return true;
}

int CountPrime(PNODE Head)
{
    int iCount = 0;

    while(Head != NULL)
    {
        if(IsPrime(Head->data))
        {
            iCount++;
        }
        Head = Head->next;
    }
    return iCount;
}

int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertLast(&first, 11);
    InsertLast(&first, 20);
    InsertLast(&first, 17);
    InsertLast(&first, 21);
    InsertLast(&first, 23);

    iRet = CountPrime(first);
    printf("Number of prime elements are: %d\n", iRet);

    return 0;
}
