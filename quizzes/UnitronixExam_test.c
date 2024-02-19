/*
Rev: Unitronix
Dev: Leonid Golovko
status: In Progress
date: 07/02/2024
*/

#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc, free*/
#include <string.h> /*strcpy*/
#include "UnitronixExam.h"

typedef struct myStruct test;
typedef struct myStructNoPadding NoPaddingtest;

struct myStruct
{
    unsigned char a[8];
    unsigned char b;
    unsigned char bPadding[3];
    short c;
    unsigned char cPadding[2];
    char str[11];
    unsigned char strPadding[1];
};


struct myStructNoPadding
{
    int number;
    char arr[6];
    int number1;
    char ch;
};



void ErrorTesting(test *from_struct, test *to_struct, unsigned char *buffer100, int *padding)
{
    int status1 = 0;
    int status2 = 0;
    int status3 = 0;
    int status4 = 0;
    int status5 = 0;
    int status6 = 0;
    int status7 = 0;
    int status8 = 0;
    int status9 = 0;
    int status10 = 0;

    status1 = StructToBuffer(NULL, (char *)buffer100, 100, sizeof(*from_struct), 5, 5, 5, padding);
    status2 = StructToBuffer((char *)from_struct, NULL, 100, sizeof(*from_struct), 5, 5, 5, padding);
    status3 = StructToBuffer((char *)from_struct, (char *)buffer100, 100, sizeof(*from_struct), 28, 5, 5
                            , padding);
    status4 = StructToBuffer((char *)from_struct, (char *)buffer100, 100, sizeof(*from_struct), 5, 100, 5
                            , padding);
    status5 = StructToBuffer((char *)from_struct, (char *)buffer100, 100, sizeof(*from_struct), 5, 5, 5
                            , padding);

    if(ERROR_ALLOCATION_SRC == status1 && ERROR_ALLOCATION_DEST == status2 
       && ERROR_SIZE_SRC == status3 && ERROR_SIZE_DEST == status4 && 5 == status5)
    {
        printf("Statuses of StructToBuffer PASS\n");
    }
    else
    {
        printf("Status1 = %d, Status2 = %d, Status3 = %d, Status4 = %d, Status5 = %d\n", status1, status2, status3, status4, status5);
        printf("Statuses of StructToBuffer FAIL\n");
    }

    status6 = BufferToStruct(NULL, 5, (char *)to_struct, 100, sizeof(*from_struct), 5, 5
                            , padding);
    status7 = BufferToStruct((char *)buffer100, 5, NULL, 100, sizeof(*from_struct), 5, 5
                            , padding);
    status8 = BufferToStruct((char *)buffer100, 28, (char *)to_struct, 100, sizeof(*from_struct)
                            , 5, 5, padding);
    status9 = BufferToStruct((char *)buffer100, 5, (char *)to_struct, 100, sizeof(*from_struct)
                            , 100, 5, padding);
    status10 = BufferToStruct((char *)buffer100, 5, (char *)to_struct, 100, sizeof(*from_struct)
                             , 5, 5, padding);

    if(ERROR_ALLOCATION_SRC == status6 && ERROR_ALLOCATION_DEST == status7 
       && ERROR_SIZE_SRC == status8 && ERROR_SIZE_DEST == status9 && SUCCESS == status10)
    {
        printf("Statuses of BufferToStruct PASS\n");
    }
    else
    {
        printf("Status6 = %d, Status7 = %d, Status8 = %d, Status9 = %d, Status10 = %d\n", status6, status7, status8, status9, status10);
        printf("Statuses of BufferToStruct FAIL\n");
    }
}

void FromStructToBuffer(test *from_struct, test *to_struct, unsigned char *buffer100, int *padding)
{
    int status1 = 0;
    status1 = StructToBuffer((unsigned char *)from_struct, buffer100, 100, sizeof(*from_struct), 28, 0, 0, padding);
    
    if(status1 == 28 && 0 == strncmp(buffer100, from_struct->a, 8) && from_struct->b == buffer100[8] && *(short *)&buffer100[9] == from_struct->c, 0 == strncmp(&buffer100[10], from_struct->str, 7))
    {
        printf("Statuses of FromStructToBuffer PASS\n");
    }
    else
    {
        printf("status1 == 28 is %d\n", status1);
        printf("0 == strcmp(buffer100, from_struct->a) is %d\n", strcmp(&buffer100[0], from_struct->a));
        printf("from_struct->b == buffer100[9] is %d\n", (from_struct->b == buffer100[9]));
        printf("*(short *)&buffer100[9] == from_struct->c is %d\n", *(short *)&buffer100[9] == from_struct->c);
        printf("0 == strcmp(&buffer100[10], from_struct->str) is %d\n", strncmp(&buffer100[10], from_struct->str , 7));
        printf("Statuses of FromStructToBuffer FAIL\n");
    }
}


void FromStructToBufferNoPadding(NoPaddingtest *from_struct, NoPaddingtest *to_struct, unsigned char *buffer100)
{
    int status1 = 0;
    status1 = StructToBuffer((unsigned char *)from_struct, buffer100, 100, sizeof(*from_struct), 15, 0, 0, NULL);
    
    if(status1 == 15 && *(int *)buffer100 == from_struct->number && 0 == strncmp(&buffer100[4], from_struct->arr, 6) && *(int *)&buffer100[10] == from_struct->number1, from_struct->ch == buffer100[14])
    {
        printf("Statuses of FromStructToBuffer PASS\n");
    }
    else
    {
        printf("status1 == 15 is %d\n", status1);
        printf("*(int *)buffer100 == from_struct->number is %d\n", *(int *)buffer100 == from_struct->number);
        printf("0 == strncmp(&buffer100[4], from_struct->arr, 6) is %d\n", strncmp(&buffer100[4], from_struct->arr, 6));
        printf("*(int *)&buffer100[10] == from_struct->number1 is %d\n", *(int *)&buffer100[10] == from_struct->number1);
        printf("from_struct->ch == buffer100[14] is %d\n", from_struct->ch == buffer100[14]);
        printf("Statuses of FromStructToBuffer FAIL\n");
    }
}

int main()
{
    int padding[30] = {10, 12, 15, 16, 28, 28, -1};
    test *from_struct = (test *)malloc(sizeof(test));
    test *to_struct = (test *)malloc(sizeof(test));
    NoPaddingtest *no_padding_from = (NoPaddingtest *)malloc(sizeof(NoPaddingtest));
    NoPaddingtest *no_padding_to = (NoPaddingtest *)malloc(sizeof(NoPaddingtest));
    unsigned char *buffer100 = (unsigned char *)malloc(sizeof(char) * 100);
    
    /* strcpy(from_struct->a, "abcde");
    from_struct->b = 'T';
    strcpy(from_struct->bPadding, "***");
    from_struct->c = 10;
    strcpy(from_struct->cPadding, "**");
    strcpy(from_struct->str, "its me!");
    strcpy(from_struct->strPadding, "*"); */

    no_padding_from->number = 5;
    no_padding_from->number1 = 6;
    no_padding_from->ch = 'g';
    strcpy(no_padding_from->arr, "hello");

    ErrorTesting(from_struct, to_struct, buffer100, padding);
    FromStructToBufferNoPadding(no_padding_from, no_padding_to, buffer100);

    /* FromStructToBuffer(from_struct, to_struct, buffer100, padding); */



    free(buffer100);
    free(from_struct);
    free(to_struct);
    free(no_padding_from);
    free(no_padding_to);

    return 0;
}