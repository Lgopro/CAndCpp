
#include "hasht.h" 

#include <string.h> /*malloc*/
#include <stdio.h> /*printf*/
typedef struct InputData
{
    void *name;
    void *definition;
}input_data;

static size_t HashFunction(void *data)
{
    size_t i = 0;
    size_t index = 0;
    size_t num = 1;
    int var = 0;
    char *array = (char *)data;
    
    while(i < strlen(array))
    {
        var = (*(array + i) - 'A');
        if(0 > (*(array + i) - 'A'))
        {
            var *= -1;
        }
        index += (size_t)var * num;
        ++num;
        ++i;
    } 
    return index;
}

static int CompareFunction(const void *value1, const void*value2)
{
    return strcmp((const char *)value1, (const char *)value2);
}


int CallBack(void *in_table, void *action_param)
{
    printf("%s\n", (char *)in_table);    /*MUST INPUT arr[] to change value!!!*/
    (void)action_param;
    return 0;
}

static void Printf()
{
    FILE* filePointer;
    char buffer[120000][30]; 
    char *here= "hello";
    char *here1= "hemorrhoids";
    char *here2= "111111111111111";
    int i = 0;
    hasht_t * hashmap = HashTCreate(HashFunction, CompareFunction, 50000);
    filePointer = fopen("/usr/share/dict/american-english", "r");
    
    while(fgets(buffer[i], 100, filePointer)) 
    {
        HashTInsert(hashmap,buffer[i], buffer[i]);
        ++i;
    }
    printf("Hash size is : %ld\n", HashTSize(hashmap));

    HashTForEach(hashmap, CallBack, NULL);
    
    if(NULL == HashTFind(hashmap, (void *)here) && NULL == HashTFind(hashmap, (void *)here1) && NULL != HashTFind(hashmap, (void *)here2))
    {
        printf("Problem\n");
    }
    fclose(filePointer);
    HashTDestroy(hashmap);
}

void HashTCreateTest();
void HashTInsertTest();
void HashTFindTest();
void HashTRemoveTest();
void HashTForEachTest();



int main()
{	
    HashTCreateTest();
    HashTInsertTest();
    HashTFindTest();
    HashTRemoveTest();
    HashTForEachTest();
    Printf();
	return 0;
}

void HashTCreateTest()
{
    size_t size = 1000;
    hasht_t * hashmap = HashTCreate(HashFunction, CompareFunction, size);
    if(NULL != hashmap && 1 == HashTIsEmpty(hashmap) && 0 == HashTSize((const hasht_t *)hashmap))
	{
		printf("HashTCreateTest pass\n");
	}
	else
	{
		printf("HashTCreateTest fail\n");
	
	}
   
    HashTDestroy(hashmap);

}


void HashTInsertTest()
{
    size_t size = 1000;
    char *key1 = "dad";
    char *key2 = "me";
    char *key3 = "mom";
    char *data1 = "100 kilos";
    char *data2 = "94 kilos";
    char *data3 = "64 kilos";
    int status1 = 0;
    int status2 = 0;
    int status3 = 0;
    hasht_t * hashmap = HashTCreate(HashFunction, CompareFunction, size);

    status1 = HashTInsert(hashmap, (void *)key1, (void *)data1);
    status2 = HashTInsert(hashmap, (void *)key2, (void *)data2);
    status3 = HashTInsert(hashmap, (void *)key3, (void *)data3);

    if(0 == status1 && 0 == status2 && 0 == status3 && NULL != hashmap && 0 == HashTIsEmpty(hashmap) && 3 == HashTSize((const hasht_t *)hashmap))
	{
		printf("HashTInsertTest pass\n");
	}
	else
	{
		printf("HashTInsertTest fail\n");
	
	}
    HashTDestroy(hashmap);
}

void HashTFindTest()
{
    size_t size = 1000;
    char *key1 = "dad";
    char *key2 = "me";
    char *key3 = "mom";
    char *key4 = "heheh";
    char *data1 = "100 kilos";
    char *data2 = "94 kilos";
    char *data3 = "64 kilos";
    void * status1 = NULL;
    void * status2 = NULL;
    void * status3 = NULL;
    void * status4 = NULL;
    hasht_t * hashmap = HashTCreate(HashFunction, CompareFunction, size);

    HashTInsert(hashmap, (void *)key1, (void *)data1);
    HashTInsert(hashmap, (void *)key2, (void *)data2);
    HashTInsert(hashmap, (void *)key3, (void *)data3);

    status1 = HashTFind(hashmap, (void *)key1);
    status2 = HashTFind(hashmap, (void *)key2);
    status3 = HashTFind(hashmap, (void *)key3);
    status4 = HashTFind(hashmap, (void *)key4);

    if(0 == strcmp(status1, data1) && 0 == strcmp(status2, data2) && 0 == strcmp(status3, data3) && status4 == NULL)
	{
		printf("HashTFindTest pass\n");
	}
	else
	{
		printf("HashTFindTest fail\n");
	
	}
    HashTDestroy(hashmap);

}



void HashTRemoveTest()
{

    size_t size = 1000;
    char *key1 = "dad";
    char *key2 = "me";
    char *key3 = "mom";
    char *data1 = "100 kilos";
    char *data2 = "94 kilos";
    char *data3 = "64 kilos";
    size_t status1 = 0;
    size_t status2 = 0;
    size_t status3 = 0;
    hasht_t * hashmap = HashTCreate(HashFunction, CompareFunction, size);

    HashTInsert(hashmap, (void *)key1, (void *)data1);
    HashTInsert(hashmap, (void *)key2, (void *)data2);
    HashTInsert(hashmap, (void *)key3, (void *)data3);

    HashTRemove(hashmap, (void *)key1);
    status1 = HashTSize((const hasht_t *)hashmap);
    HashTRemove(hashmap, (void *)key2);
    status2 = HashTSize((const hasht_t *)hashmap);
    HashTRemove(hashmap, (void *)key3);
    status3 = HashTSize((const hasht_t *)hashmap);
    if(2 == status1 && 1 == status2 && 0 == status3)
	{
		printf("HashTRemoveTest pass\n");
	}
	else
	{
		printf("HashTRemoveTest fail\n");
        printf("status1 = HashTSize((const hasht_t *)hashmap);%ld\n", status1);
        printf("status2 = HashTSize((const hasht_t *)hashmap);%ld\n", status2);
        printf("status3 = HashTSize((const hasht_t *)hashmap);%ld\n", status3);
	}
    HashTDestroy(hashmap);

}


void HashTForEachTest()
{

    size_t size = 1000;
    char *key1 = "dad";
    char *key2 = "me";
    char *key3 = "mom";
    char *data1 = "100 kilos";
    char *data2 = "94 kilos";
    char *data3 = "64 kilos";
    char *action = "hello";
    hasht_t * hashmap = HashTCreate(HashFunction, CompareFunction, size);

    HashTInsert(hashmap, (void *)key1, (void *)data1);
    HashTInsert(hashmap, (void *)key2, (void *)data2);
    HashTInsert(hashmap, (void *)key3, (void *)data3);

    HashTFind(hashmap, (void *)key1);
    HashTFind(hashmap, (void *)key2);
    HashTFind(hashmap, (void *)key3);

    HashTForEach(hashmap, CallBack, action);
	
	printf("HashTForEachTest pass\n");
	
	
    HashTDestroy(hashmap);

}


