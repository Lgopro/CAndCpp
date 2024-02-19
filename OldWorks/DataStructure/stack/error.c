
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef enum
{
    
    ERR_OK,
    ERR_GENERAL,
    ERR_NOT_INITIALIZED,
    ERR_ALLOCATION_FAILED,
    ERR_REALLOCATION_FAILED,
    ERR_UNDERFLOW,
    ERR_OVERFLOW,
    ERR_WRONG_INDEX,
           
    ERR_STACK_BBBBB = 30
    
  
}ADTErr ;

void PrintError(ADTErr _error);

void PrintError(ADTErr _error)
{
        if(_error=ERR_OK)
        {
                printf("Operation successful\n\n");
        }
        if(_error=ERR_GENERAL)
        {
                printf("General error.Please try again\n\n");
        }
        if(_error=ERR_NOT_INITIALIZED)
        {
                printf("Not initialized. Please try again\n\n");
        }
        if(_error=ERR_REALLOCATION_FAILED)
        {
                printf("Relocation failed. Please try again\n\n");
        }
        if(_error=ERR_UNDERFLOW)
        {
                printf("There is nothing to remove. Please try again\n\n");
        }
        if(_error=ERR_OVERFLOW)
        {
                printf("Cant add anymore. Please try again\n\n");
        }
        if(_error=ERR_WRONG_INDEX)
        {
                printf("Wrong index\n\n");
        }


}


int main()
{

        return 0;
}
