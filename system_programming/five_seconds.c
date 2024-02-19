
#include <stdio.h> /*printf*/
#include <unistd.h> /*sleep*/

#define FAIL (1)
#define SUCCESS (0)

void SmashThisStackHehe()
{
    int i = 0;
    int sum = 2;
    sum *= 1 - i;
    SmashThisStackHehe();
}

/*int main()
{
    int i = 0;
    printf("Sleeping\n");
    for(i = 0;i < 5; ++i)
    {
        sleep(1);
    }
    printf("Good Morning\n");
    return 0;
}*/


/*int main()
{
    
    SmashThisStackHehe();
    return 0;
}*/



int main()
{
    int *i = NULL;
    printf("%d\n", *i);
    return 0;
}

