#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/
#include <ctype.h>
#include <assert.h>

void SwapOneChar(char *p_a, char *p_b);
void Swap(void *p_a, void *p_b, size_t size);


int main()
{
	char string1[] = "Lgo";
    char string2[] = "Pro";

    Swap(string1, string2, 3);
	printf("New string1 is %s\n", string1);
    printf("New string2 is %s\n", string2);
	return 0;
}


void Swap(void *p_a, void *p_b, size_t size)
{
    assert(p_a);
    assert(p_b);
    assert(0 < size);

    while(0 != size)
    {
        SwapOneChar(p_a, p_b);
        --size;
        p_a = (char *)p_a + 1;
        p_b = (char *)p_b + 1;
    }
}

void SwapOneChar(char *p_a, char *p_b)
{
    *p_a = *p_a ^ *p_b;
    *p_b = *p_b ^ *p_a;
    *p_a = *p_a ^ *p_b;
}