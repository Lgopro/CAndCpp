#include "MemoryMappingFull.h"

void ExternFunctionExplicit()
{
    int a = 5;

    /* Cancel "unsused variable" warnings: */
    (void)a;
}
