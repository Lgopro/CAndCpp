
#include <stdio.h>
#include <stdlib.h>

void SwapPtr(void** _a, void**_b);
void sort(void* _arr,size_t _size, size_t _elemsize,int(*less)(void*,void*);
void test1(void);
int main()
{
    test1();
    return 0;
}


void SwapPtr(void** _a, void**_b)
{
	void* swap;
	if(NULL == _a || NULL == _b)
	{
		return;
	}
	swap = *_a;
	*_a = *_b;
	*_b = swap;
}

void test1(void)
{
	int num1 = 5;
    int num2 = 55;
    int *pNum1 = & num1;
    int *pNum2 = & num2;

    SwapPtr((void**)&pNum1,(void**)&pNum2);

    if (num1 == *pNum2 && num2 == *pNum1)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
    }


}
