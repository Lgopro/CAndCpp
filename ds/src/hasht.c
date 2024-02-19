

#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/
#include <stdio.h> /*FILE*/
#include <string.h> /*strtok*/

#include "hasht.h" 

#define FAIL 1
#define SUCCESS 0

typedef void * key_t;

struct Hash_Table
{
    size_t capacity;
    size_t (*hash_func)(void *key);
    int (*compare_func)(const void *, const void*);
    dlist_t *table[1];
};

typedef struct InputData
{
    void *name;
    void *definition;
}input_data;


typedef struct ForEach
{
    void *data;
    int(*call)(void *,void *);
}for_each_data;


static int GetRightData(void *var1, void *var2);

hasht_t *HashTCreate(size_t (*hash_func)(void *data), int (*compare_func)(const void *, const void*), size_t capacity)
{
    hasht_t * hash_table = NULL;
    size_t i = 0;
    size_t j = 0;

    assert(hash_func);
    assert(compare_func);
    assert(0 < capacity);

    hash_table = (hasht_t *)malloc(sizeof(hasht_t) + sizeof(dlist_t *) * capacity);
    if(NULL == hash_table)
    {
        return NULL;
    }
    
    hash_table->hash_func = hash_func;
    hash_table->compare_func = compare_func;
    hash_table->capacity = capacity;

    for(i= 0;i < capacity; ++i)
    {
        hash_table->table[i] = DListCreate();
        if(NULL == hash_table->table[i])
        {
            for(j = 0;j < i; ++j)
            {
                DListDestroy(hash_table->table[j]);
            }
            free(hash_table);
            return NULL;
        }
    }
    
    return hash_table;

}

void HashTDestroy(hasht_t *hash)
{
    size_t index = 0;
    size_t i = 0;
    input_data *input = NULL;
    dlist_iter_t iterator = NULL;

    assert(hash);

    for(index = 0; index < hash->capacity; ++index)
    {
        if(1 == DListIsEmpty((const dlist_t *)hash->table[index]))
        {
           DListDestroy(hash->table[index]);
           continue;
        }
        else
        {
            iterator = DListBegin((const dlist_t *)hash->table[index]);
           
        
            for(i = 0; i < DListSize((const dlist_t *)hash->table[index]); ++i)
            {
                input = (input_data *)DListGetData(iterator);
                free(input);
                iterator = DListNext(iterator);
            }
            DListDestroy(hash->table[index]);
        }
    }
    free(hash);
}

size_t HashTSize(const hasht_t *hash)
{
    size_t i = 0;
    size_t total_size = 0;
    assert(hash);

    for(i = 0; i < hash->capacity; ++i)
    {
        total_size += DListSize((const dlist_t *)(hash->table[i]));
    }

    return (total_size);
}


int HashTIsEmpty(hasht_t *hash)
{
    size_t i = 0;
    size_t total_size = 0;

    assert(hash);

    for(i = 0; i < hash->capacity; ++i)
    {
        total_size += DListSize((const dlist_t *)(hash->table[i]));
        if(0 < total_size)
        {
            return 0;
        }
    }

    return 1;
}

int HashTInsert(hasht_t * hash, void *key, void* data)
{
    size_t index = 0;
    input_data *input = NULL;

    assert(key);
    assert(hash);

    input = (input_data *)malloc(sizeof(input_data));
    if(NULL == input)
    {
        return (FAIL);
    }

    input->name = key;
    input->definition = data;

    index = hash->hash_func(key);
    index %= hash->capacity;

    
    DListPushFront(hash->table[index], (void *)input); 

    return (SUCCESS);
}


void *HashTFind(hasht_t *hash, void *key)
{

    size_t index = 0;
    size_t i = 0;
    input_data *input = NULL;
    dlist_iter_t iterator = NULL;

    assert(key);
    assert(hash);    

    index = hash->hash_func(key);
    index %= hash->capacity;

    if(DListIsEmpty((const dlist_t *)hash->table[index]))
    {
        return (NULL);
    }
    else
    {
        iterator = DListBegin((const dlist_t *)hash->table[index]);
        input = (input_data *)DListGetData(iterator);

        
        for(i = 0; i < DListSize((const dlist_t *)hash->table[index]); ++i)
        {
            if(0 == hash->compare_func(key, ((input_data *)input)->name))
            {
                return (((input_data *)input)->definition);
            }
            iterator = DListNext(iterator);
            input = (input_data *)DListGetData(iterator);

        }
        return (NULL);
        
    }
}


void HashTRemove(hasht_t *hash, void *key)
{

    size_t index = 0;
    size_t i = 0;
    input_data *input = NULL;
    dlist_iter_t iterator = NULL;
    
    assert(key);
    assert(hash);    

    index = hash->hash_func(key);
    index %= hash->capacity;

    if(DListIsEmpty((const dlist_t *)hash->table[index]))
    {
        return;
    }
    else
    {
        iterator = DListBegin((const dlist_t *)hash->table[index]);

        for(i = 0; i < DListSize((const dlist_t *)hash->table[index]); ++i)
        {
            input = (input_data *)DListGetData(iterator);
            if(0 == hash->compare_func(key, input->name))
            {
                free(input);
                iterator = DListRemove(iterator);
                return;
            }
            iterator = DListNext(iterator);
        }
    }
}



int HashTForEach(hasht_t *hash, int (*call_back)(void *in_table, void *action_param), void *action_param)
{
    size_t index = 0;
    
    dlist_iter_t begin = NULL;
    dlist_iter_t end = NULL;
    for_each_data get_data = {0};

    assert(hash); 
    assert(call_back);
    assert(hash);

    get_data.data = action_param;
    get_data.call = call_back;

    for(index = 0;index < hash->capacity; ++index)
    {
        begin = DListBegin(hash->table[index]);
        end = DListEnd(hash->table[index]);
        if (FAIL == DListForEach(begin, end, GetRightData, (void *)&get_data))
        {
            return (FAIL);
        }
    }
    return (SUCCESS);
}



static int GetRightData(void *var1, void *var2)
{
    void *param = ((input_data *)var1)->definition;
    return (((for_each_data *)var2)->call(param, ((for_each_data *)var2)->data));
}

