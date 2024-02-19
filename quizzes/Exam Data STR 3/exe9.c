#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <stdio.h> /*printf*/
#include "dlist.h"
#define SUCCESS 0
#define FAIL 1
#define EMPTY 1










int PivotSort(dlist_t *list, void *number);

int Action(void *val1, void *val2)
{
    (void)val2;
    printf("%d ", *(int *)val1);
    return SUCCESS;
}


int main()
{
    int number1 = 1;
    int number2 = 2;
    int number3 = 3;
    int number4 = 4;
    int number5 = 55;
    int number6 = 6;
    int number7 = 7;
    int number = 5;
    dlist_t *list = DListCreate();
    DListInsert(DListBegin(list), &number1);
    DListInsert(DListBegin(list), &number2);
    DListInsert(DListBegin(list), &number3);
    DListInsert(DListBegin(list), &number4);
    DListInsert(DListBegin(list), &number5);
    DListInsert(DListBegin(list), &number6);
    DListInsert(DListBegin(list), &number7);
    PivotSort(list, &number);
    DListForEach(DListBegin(list), DListEnd(list), Action, &number);
    DListDestroy(list);
    return 0;

}

int PivotSort(dlist_t *list, void *number)
{
    node_t *iter = NULL;
    dlist_t *help_list = NULL;
    assert(list);
    assert(number);
    help_list = DListCreate();
    if(NULL == help_list)
    {
        return (FAIL);
    }
    DListInsert(DListBegin(list), number);
    
    while(EMPTY != DListIsEmpty(list))
    {
        iter = DListBegin(list);
        if(*(int *)number <= *(int *)DListGetData(iter))
        {
            DListPushBack(help_list, DListGetData(iter));
            DListPopFront(list);
        }
        else
        {
            DListPushFront(help_list, DListGetData(iter));
            DListPopFront(list);
        }
    }
    while(EMPTY != DListIsEmpty(help_list))
    {
        iter = DListBegin(help_list);
        DListPushBack(list, DListGetData(iter));
        DListPopFront(help_list);
    }
    free(help_list);
    return (SUCCESS);
}