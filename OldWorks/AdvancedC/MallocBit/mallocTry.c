#include <stdio.h>
#include <string.h>
#define SIZE 20000 //size of the memory
#define INIT 0 //'i' if array is initialized, '\0' otherwise
#define I 1 //i to use in for loops, 4 bytes
#define START 5 //actual position that can use to allocate
 
char mem[SIZE] = {'\0'}; //Null all values in the array
 
void * MyMalloc(size_t size){
    printf("Start of mymalloc\n");
 
    if (mem[INIT] == '\0') {
        int i;
        for (i = 0; i < SIZE; ++i)       {           mem[i] = '\0';      }       mem[INIT] = 'i';        mem[START] = 'f';       *(int*)(&mem[START + 1]) = 19994;       printf("Initialized\n");    }   int i = START; //*(int*)(&mem[I])   while (1) {         printf("i:%d\n", i);                if (i > 20000) {
            printf("End of MyMalloc\n");
            return NULL;
        }
        if ((mem[i] == 'f') && (*(int*)(&mem[i + 1]) >= (size))){
            mem[i] = 'a'; // to indicate that this is an allocated block
 
            int curSize = *(int*)(&mem[i+1]);
            int leftSize = curSize - (size + 5);
            //if the left size is < 6B, thw whole block is allocated             if (leftSize > 5) {
                *(int*)(&mem[i+1]) = size; //update the new size
 
                int next = i + 5 + size; //4 bytes to store the size of the block
                printf("next:%d\n", next);
 
                mem[next] = 'f';
                *(int*)(&mem[next + 1]) = leftSize;
            }
            printf("End of MyMalloc\n");
            return (void*)(&mem[i+5]);
        } else {
            i += *(int*)(&mem[i + 1]) + 5;
        }
    }
}
 
void MyFree(void* ptr){
    printf("Start of MyFree\n");
    int i = START;
    int before = 0;
    while (1) {
        printf("i:%d\n", i);
 
        if (i > 20000) {
            printf("End of MyFree\n");
            break;
        }
        if ((void*)(&mem[i+5]) == ptr){
            printf("found\n");
            mem[i] = 'f';
            //check if the slot after is a free one
            int next = i + 5 + *(int*)(&mem[i + 1]);
            if (mem[next] == 'f') {
                //combining two free slots
                *(int*)(&mem[i + 1]) = *(int*)(&mem[i + 1]) + 5 + *(int*)(&mem[next + 1]);
            }
 
            //check if the slot before is a free one
            if (mem[before] == 'f') {
                //combining two free slots
                *(int*)(&mem[before + 1]) = *(int*)(&mem[before + 1]) + 5 + *(int*)(&mem[i + 1]);
            }
            printf("size:%d\n", *(int*)(&mem[before + 1]));
            printf("End of MyFree\n");
            break;
        } else {
            before = i;
            i += *(int*)(&mem[i + 1]) + 5;
        }
    }
}
 
void printer(int size){
    printf("Start of printer\n");
    int i;
    for (i = 0; i < size; ++i)
    {
        //printf("%d\t%s\t%c\n", i, &mem[i], mem[i]);
        printf("%d\t%c\n", i, mem[i]);
    }
    printf("End of printer\n");
}


 
int main(int argc, char const *argv[])
{
    printf("Start of main\n");
 
    char* p1 = (char*)MyMalloc(10);
    //strcpy(p, "Helloaaaa");
    printer(50);
 
    char* p2 = (char*)MyMalloc(10);
    printer(50);
 
    char* p3 = (char*)MyMalloc(10);
    printer(50);
 
    MyFree((void*)p2);
    printer(100);
 
    MyFree((void*)p3);
    printer(100);
    temp(33);
 
    char* p4 = (char*)MyMalloc(11);
    printer(100);
 
    temp(49);
    printf("End of main\n");
    //printer(50);
    return 0;
}
