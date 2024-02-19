#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/
#include <ctype.h>
#include <assert.h>



int main()
{
	int status1 = 0;
    int status2 = 0;
    char str[] ="hello world";
    char a = 'a';
    char b = 'o';
    status1 = Find(str, a);
    status2 = Find(str, a);
    printf("status 1 is: %d", status1);
    printf("status 2 is: %d", status2);
	return 0;
}

int Find(char *str,char find)
{
    size_t counter = 0;
    int result = 0;

    assert(str);

    while(counter < strlen(str))
    {
        result *= *(str + counter)^find;

        ++counter;
    }

    return result;
}
