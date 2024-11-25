#include <stdio.h>
#include <assert.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int IsRotation(char *s1, char *s2)
{
    assert(s1);
    assert(s2);

    size_t length_s1 = strlen(s1);
    size_t length_s2 = strlen(s2);

    if(length_s1 < length_s2)
    {
        return FALSE;
    }

    for(size_t i = 0; i < length_s1; ++i)
    {
        if(s1[i] == s2[0])
        {
            for(size_t j = 1; j < length_s2; ++j)
            {
                if(s1[(i + j) % length_s1] != s2[j])
                {
                    break;
                }

                if(j + 1 == length_s2 && s1[(i + j) % length_s1] == s2[j])
                {
                    return TRUE;
                }
            }
        }
    }

    return FALSE;

}


int main()
{
    char arr1[] = "defghabc";
    char arr2[] = "abcde";

    int result = IsRotation(arr1, arr2);
    if(result == TRUE)
    {
        printf("Its true\n");
    }
    else
    {
        printf("Its false\n");
    }

    return 0;
}