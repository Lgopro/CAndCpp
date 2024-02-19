
#include <stdio.h>
#include <string.h>

#include "shell.h"
#define FAIL (1)
#define SUCCESS (0)


int main(int argc, char const *argv[])
{
    int status = 0;
    if(2 > argc)
    {
        printf("No option selected\n");
        status = FAIL;
    }
    else if(0 == strcmp(argv[1], "fork"))
    {
        status = Fork();
    }
    else if(0 == strcmp(argv[1], "system"))
    {
        status = System();
    }
    else
    {
        printf("Wrong option selected\n");
        status = FAIL;
    }
        
    return status;
}


