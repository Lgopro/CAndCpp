#include "MemoryMappingFull.h"

void ExternFunctionStatic()
{
    int a = 5;

    /* Cancel "unsused variable" warnings: */
    (void)a;
}
