#include <stdlib.h>
#include "MemoryMappingFull.h"





void ExternFunction()
{
    int a = 5;

    /* Cancel "unsused variable" warnings: */
    (void)a;
}
