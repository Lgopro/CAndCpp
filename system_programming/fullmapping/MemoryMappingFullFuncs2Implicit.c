#include "MemoryMappingFull.h"

void ExternFunctionImplicit()
{
    int a = 5;

    /* Cancel "unsused variable" warnings: */
    (void)a;
}
