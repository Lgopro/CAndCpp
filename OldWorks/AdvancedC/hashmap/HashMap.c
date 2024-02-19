#include <stdio.h>
#include <stdlib.h>      /*size_t*/
#include <string.h>      /*memcpy*/
#include "HashMap.h"
#include "ListStructs.h"
#include "ListIt.h"
#include "List.h"

#define PERCENT(x)	((x) + ((x)/6))

struct FindAndKey
{
    EqualityFunction m_isEqualOfUser;
    const void* m_key;
};
struct HashMap
{
    size_t m_capacity;
    HashFunction m_hashFunc;
    EqualityFunction m_equalFunc;
    size_t m_nElement;
    List** m_pair;
};

typedef struct
{
   const void* m_key;
    void* m_value;
}Pair;


static void DestroyPairList(List* _list, DestroyFunction _keyDestroy, DestroyFunction _valDestroy);
static void DestroyPairs(HashMap* _map, DestroyFunction _keyDestroy, DestroyFunction _valDestroy);
static ListItr HelpHashMap_Find(const HashMap* _map, const void* _key);
static int HashIsEqual(void* _context, void* _listValue);
static ListItr isFound(const HashMap* _map, const void* _key, size_t hashNum);
static void swapMap(HashMap *_map1, HashMap *_map2);


HashMap* HashMap_Create(size_t _capacity, HashFunction _hashFunc, EqualityFunction _keysEqualFunc)
{
    int i;
    HashMap* hashmap;
    if( NULL == _hashFunc || NULL == _keysEqualFunc || _capacity<1)
    {
        return NULL;
    }
    if(NULL == (hashmap = malloc(sizeof(struct HashMap) + _capacity*sizeof(List*))))
 	{
   		return NULL;
    }
    if(NULL == (hashmap->m_pair = malloc(_capacity*sizeof(List*))))
 	{
        free(hashmap);
   		return NULL;
    }
    hashmap->m_capacity = PERCENT(_capacity);
    hashmap->m_hashFunc = _hashFunc;
    hashmap->m_equalFunc = _keysEqualFunc;
    hashmap->m_nElement = 0;
    for(i=0;i<_capacity;i++)
    {
        hashmap->m_pair[i] = List_Create();
    }
    return hashmap;
}


void HashMap_Destroy(HashMap** _map, DestroyFunction _keyDestroy, DestroyFunction _valDestroy)
{
	if(NULL == _map  ||  NULL == *_map )
	{	
		return;
	}

	DestroyPairs(*_map, _keyDestroy, _valDestroy);
	
	free(*_map);

	*_map = NULL;
}

static void DestroyPairs(HashMap* _map, DestroyFunction _keyDestroy, DestroyFunction _valDestroy)
{
	int i;

	for(i = 0; i < _map->m_capacity; ++i)
	{
		if(_map->m_pair[i] == NULL)
		{
			continue;
		}

		DestroyPairList(_map->m_pair[i], _keyDestroy, _valDestroy);
	}
	free(_map->m_pair);

	_map->m_pair = NULL;
}

static void DestroyPairList(List* _list, DestroyFunction _keyDestroy, DestroyFunction _valDestroy)
{
	int i;
	Pair* listdata = NULL;
	for(i = 0; i < List_Size(_list); ++i)
	{
		List_PopTail(_list, (void**) &listdata);
		_keyDestroy(listdata->m_key);
        _valDestroy(listdata->m_value);
	}

	List_Destroy(&_list, NULL);
}

Map_Result HashMap_Find(const HashMap* _map, const void* _key, void** _pValue)
{
	ListItr itr, end;
	size_t hashNum;
	
	if (_map == NULL)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if (_key == NULL)
	{
		return MAP_KEY_NULL_ERROR;
	}
	
	hashNum = _map->m_hashFunc(_key) % _map->m_capacity;
	if(_map->m_pair[hashNum])
	{
		itr = isFound(_map, _key, hashNum);
		end = ListItr_End(_map->m_pair[hashNum]);
		if (itr != end)
		{
			*_pValue = ((Pair*)ListItr_Get(itr))->m_value;
			return MAP_SUCCESS;
		}
	}
	return MAP_KEY_NOT_FOUND_ERROR;
}
static Map_Result CheckNull(HashMap* _map, const void* _key, void* _value)
{
	if(_map == NULL)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if (_key == NULL)
	{
		return MAP_KEY_NULL_ERROR;
	}
	if (_value == NULL)
	{
		return MAP_VALUE_NULL_ERROR;
	}
	return MAP_SUCCESS;
}

Map_Result HashMap_Insert(HashMap* _map, const void* _key, void* _value)
{
	size_t hashNum;
	Pair* pair;
	void* val;
	Map_Result result;
	ListItr end;
	
	result = CheckNull(_map, _key, _value);
	if (result != MAP_SUCCESS)
	{
		return result;
	}

	result = HashMap_Find(_map, _key, &val);
	if (result != MAP_KEY_NOT_FOUND_ERROR)
	{
		return MAP_KEY_DUPLICATE_ERROR;
	}

	hashNum = _map->m_hashFunc(_key) % _map->m_capacity;
	if (_map->m_pair[hashNum] == NULL)
	{
		_map->m_pair[hashNum] = List_Create();
		if (_map->m_pair[hashNum] == NULL)
		{
			return MAP_ALLOCATION_ERROR;
		}
	}

	pair = (Pair*)malloc(sizeof(Pair));
	if (pair == NULL)
	{
		return MAP_ALLOCATION_ERROR;
	}
	pair->m_key = _key;
	pair->m_value = _value;

	end = ListItr_End(_map->m_pair[hashNum]);
	ListItr_InsertBefore(end, pair);
	++_map->m_nElement;

	return MAP_SUCCESS;
}


static int HashIsEqual(void* _context, void* _listValue)
{
    struct FindAndKey* findInfo = (struct FindAndKey*)_context;
    Pair* current = (Pair*)_listValue;
    return findInfo->m_isEqualOfUser(current->m_key, findInfo->m_key);
}

size_t HashMap_Size(const HashMap* _map)
{
    if(NULL == _map)
    {
        return 0;
    }
    return _map->m_nElement;
}


    

static ListItr isFound(const HashMap* _map, const void* _key, size_t hashNum)
{
	ListItr begin, end;
	struct FindAndKey context;
	
	if (_map->m_pair[hashNum] == NULL)
	{
		return NULL;
	}
	
	context.m_isEqualOfUser = _map->m_equalFunc;
	context.m_key = _key;

	begin = ListItr_Begin(_map->m_pair[hashNum]);
	end = ListItr_End(_map->m_pair[hashNum]);
	return ListItr_FindFirst(begin, end, HashIsEqual, &context);
}

Map_Result HashMap_Remove(HashMap* _map, const void* _searchKey, const void** _pKey, void** _pValue)
{
	size_t hashNum;
	ListItr itr, end;
	Pair* pair;
	if(_map == NULL)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if (_searchKey == NULL)
	{
		return MAP_KEY_NULL_ERROR;
	}
	hashNum = _map-> m_hashFunc(_searchKey) % _map->m_capacity;
	end = ListItr_End(_map->m_pair[hashNum]);
	
	itr = isFound(_map, _searchKey, hashNum);
	if (ListItr_Equals(itr, end))
	{
		return MAP_KEY_NOT_FOUND_ERROR;
	}
	pair = (Pair*)ListItr_Remove(itr);
	--_map->m_nElement;
	*_pValue = pair->m_value;
	*_pKey = pair->m_key;
	free(pair);
	return MAP_SUCCESS;
}



size_t HashMap_ForEach(const HashMap* _map, KeyValueActionFunction _action, void* _context)
{
	int i;
	Pair* pair;
	ListItr begin, end;
	size_t count = 0;
	
	if (_map == NULL || _action == NULL)
	{
		return count;
	}
	for (i = 0; i < _map->m_capacity; ++i)
	{
		if(_map->m_pair[i])
		{
			begin = ListItr_Begin(_map->m_pair[i]);
			end = ListItr_End(_map->m_pair[i]);
			while (begin != end)
			{
				++count;
				pair = (Pair*)ListItr_Get(begin);
				if (!_action(pair->m_key, pair->m_value, _context))
				{
					return count;
				}
				begin = ListItr_Next(begin);
			}
		}
	}
	return count;
}

int	Add(const void* _key, void* _value, void* _context)
{
	HashMap_Insert((HashMap*)_context, _key, _value);
	return 1;
}

static void swapMap(HashMap *_map1, HashMap *_map2)
{
	HashMap temp;
	memcpy(&temp, _map1, sizeof(HashMap));
	memcpy(_map1, _map2, sizeof(HashMap));
	memcpy(_map2, &temp, sizeof(HashMap));
}


Map_Result HashMap_Rehash(HashMap *_map, size_t newCapacity)
{
	HashMap* newMap;
	
	if (_map == NULL)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	newMap = HashMap_Create(newCapacity, _map->m_hashFunc, _map->m_equalFunc);
	if (newMap == NULL)
	{
		return MAP_ALLOCATION_ERROR;
	}
	    HashMap_ForEach(_map, Add, newMap);
	    swapMap(_map, newMap);
	    HashMap_Destroy(&newMap, NULL, NULL);
	
	return MAP_SUCCESS;
}