
#include "MyMalloc.h"

static void* Insert(void*  _memory, size_t _blockSize);
static void* FindFirstFree(void* _memory);

void MyMallocInit(void* _memory, size_t _memorySize)
{
    *(int*)_memory =  (int)_memorySize - (int)_memorySize % 4 - (int)sizeof(BYTE)*4 + 1;
}

void* MyMalloc(void* _memory, size_t _requiredBlockSize)
{
	int flag=0;
    void* nextPtr;
    if (_memory == NULL)
    {
        return NULL;
    }
    _requiredBlockSize = _requiredBlockSize + (sizeof(BYTE) - _requiredBlockSize % 4 );
    while ((*(int*)_memory & 1) == 0 || (*(size_t*)_memory < _requiredBlockSize))
    {
        nextPtr = (BYTE*)_memory + *((int*)_memory) + 4 * sizeof(BYTE);
        if (*(int*)nextPtr & 1)
        {
            flag = 1;
            *(int*)_memory += *(int*)nextPtr + 4 * (int)sizeof(BYTE);
        }
        if(flag == 0)
        {
            _memory = (BYTE*)_memory + *((int*)_memory) + 4 * sizeof(BYTE);
        }
    }
    return Insert(_memory, _requiredBlockSize);
}

void MyFree(void* _myBlock)
{
    *(int*)_myBlock= *(int*)_myBlock & 0;
}

static void* Insert(void*  _memory, size_t _blockSize)
{
    _memory = (BYTE*)_memory + _blockSize + sizeof(int);
    _memory = FindFirstFree(_memory);
    return _memory;
}

static void* FindFirstFree(void* _memory)
{
    while (!*(int*)_memory & 1)
    {
        _memory = (void*)((BYTE*)_memory + *((int*)_memory) + 4 * sizeof(BYTE));
    }
    return _memory;
}


