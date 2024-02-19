/*
Rev: Unitronix
Dev: Leonid Golovko
status: In Progress
date: 07/02/2024
*/

#include <stddef.h> /*NULL*/

#include "UnitronixExam.h"


#define END_OF_PADDING -1
#define JUMP_NEXT 2

int StructToBuffer(unsigned char *srcStrcut, unsigned char *dstBuffer, int dstBufferSize, int srcBufferSize, int dataLength, int StartLocationDest, int StartLocationScr, int *padding)
{

    int i = 0;
    int counter = 0;
    int padding_location = 0;
    int padding_counter = 0;

    if(srcStrcut == NULL)
    {
        return ERROR_ALLOCATION_SRC;
    }
    if(dstBuffer == NULL)
    {
        return ERROR_ALLOCATION_DEST;
    }
    if(srcBufferSize < StartLocationScr + dataLength)
    {
        return ERROR_SIZE_SRC;
    }
    if(dstBufferSize < StartLocationDest + dataLength)
    {
        return ERROR_SIZE_DEST;
    }

    if(padding == NULL)
    {
        for(i = 0; i < dataLength; ++i)
        {
            dstBuffer[StartLocationDest + i] = srcStrcut[StartLocationScr + i];
        }
    }
    else
    {
        while(counter < dataLength)
        {
            if((counter + StartLocationScr > padding[padding_location + 1]))
            {
                padding_location += JUMP_NEXT;
            }
            if(padding[padding_location] == END_OF_PADDING)
            {
                dstBuffer[StartLocationDest + i] = srcStrcut[StartLocationScr + i + padding_counter];
                ++counter;
                continue;/*could do memcpy and break*/
            }
            else if((counter + StartLocationScr >= padding[padding_location]) && (counter + StartLocationScr <= padding[padding_location + 1]))
            {
                ++padding_counter;
                ++counter; /*????according to user wish*/
                continue;
            }
            else
            {
                dstBuffer[StartLocationDest + i] = srcStrcut[StartLocationScr + i + padding_counter];
                ++counter;
                continue;
            }
            
        }
    }
    return dataLength;
}

int BufferToStruct(unsigned char * srcBuffer, int dataLength, unsigned char *dsStrcut, int dstBufferSize, int srcBufferSize, int StartLocationDest, int StartLocationScr, int *padding)
{
    int counter = 0;
    int padding_location = 0;
    int padding_counter = 0;
    int i = 0;

    if(srcBuffer == NULL)
    {
        return ERROR_ALLOCATION_SRC;
    }
    if(dsStrcut == NULL)
    {
        return ERROR_ALLOCATION_DEST;
    }
    if(srcBufferSize < dataLength + StartLocationScr)
    {
        return ERROR_SIZE_SRC;
    }
    if(dstBufferSize < dataLength + StartLocationDest)
    {
        return ERROR_SIZE_DEST;
    }

    if(padding == NULL)
    {
        for(i = 0; i < dataLength; ++i)
        {
            dsStrcut[StartLocationDest + i] = srcBuffer[StartLocationScr + i];
        }
    }
    else
    {
        while(counter < dataLength)
        {
            if((counter + StartLocationDest > padding[padding_location + 1]))
            {
                padding_location += JUMP_NEXT;
            }
            if(padding[padding_location] == END_OF_PADDING)
            {
                dsStrcut[StartLocationDest + i + padding_counter] = srcBuffer[StartLocationScr + i + padding_counter];
                ++counter;
                continue;
            }
            else if((counter + StartLocationScr >= padding[padding_location]) && (counter + StartLocationScr <= padding[padding_location + 1]))
            {
                ++padding_counter;
                ++counter; /*????according to user wish*/
                continue;
            }
            else
            {
                dsStrcut[StartLocationDest + i + padding_counter] = srcBuffer[StartLocationScr + i];
                ++counter;
                continue;
            }
        }
    }
    return SUCCESS;
}
