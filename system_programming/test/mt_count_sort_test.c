/*
Rev: Etai Shimoni.
Dev: Leonid Golovko
status: finished
date: 24/07/2023
*/


#include <stdio.h> /*printf*/
#include <string.h> /*fseek*/
#include <stdlib.h> /*malloc*/

#include "mt_count_sort.h"
#define FAIL (1)
#define SUCCESS (0)

static void LUTForDictionary()
{
    FILE* filePointer;
    long length = 0;
    unsigned char *buffer = NULL; 
    unsigned char *buffer1 = NULL; 
    unsigned char *buffer2 = NULL; 
    unsigned char *buffer3 = NULL; 
    filePointer = fopen("/usr/share/dict/american-english", "r");
    if (filePointer)
    {
        fseek (filePointer, 0, SEEK_END);
        length = ftell (filePointer);
        fseek (filePointer, 0, SEEK_SET);
        buffer = malloc(length);
        buffer1 = malloc(length);
        buffer2 = malloc(length);
        buffer3 = malloc(length);
        if (buffer)
        {
            fread (buffer, 1, length, filePointer);
            fseek (filePointer, 0, SEEK_SET);
            fread (buffer1, 1, length, filePointer);
            fseek (filePointer, 0, SEEK_SET);
            fread (buffer2, 1, length, filePointer);
            fseek (filePointer, 0, SEEK_SET);
            fread (buffer3, 1, length, filePointer);
        }
    
        fclose(filePointer);
    }
   
    MTCountSort(buffer, length, 1);
    MTCountSort(buffer1, length, 2);
    MTCountSort(buffer2, length, 4);
    MTCountSort(buffer3, length, 8);
    free(buffer);
    free(buffer1);
    free(buffer2);
    free(buffer3);
}

int main()
{
    LUTForDictionary();
    return 0;
}


