#include <stdio.h>

struct EmptyStruct 
{ 

}; 
struct NotEmptyStruct 
{
    int a; 
    int b;
}; 
int main() 
{
    printf("Size of EmptyStruct: %ld\n", sizeof(struct EmptyStruct));
    printf("Size of NotEmptyStruct: %ld\n", sizeof(struct NotEmptyStruct));
    return 0;
}
