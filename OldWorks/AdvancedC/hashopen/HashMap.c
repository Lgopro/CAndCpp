#include <stdio.h>
#include <stdlib.h>      /*size_t*/
#include <string.h>      /*memcpy*/
#include "HashMap.h"


#define TRUE 1
#define FALSE 0
#define DELETED ((void*)1)
typedef struct
{
    const void* m_key;
    void* m_value;
}Pair;

struct HashMap
{
    size_t m_capacity;
	size_t m_user_capacity;
    HashFunction m_hashFunc;
    EqualityFunction m_equalFunc;
    size_t m_nElement;
	size_t m_colissions;
	size_t m_maxsteps;
    Pair* m_hastable;
};

static void swapMap(HashMap *_map1, HashMap *_map2);
static size_t FindIndex( HashMap* _map, const void* _key);
static Map_Result CheckNull(HashMap* _map, const void* _key, void* _value);
static void DestroyPairs(HashMap** _map, DestroyFunction _keyDestroy, DestroyFunction _valDestroy);
static size_t isPrime(size_t _num);
static size_t FindNextPrimeNumber(size_t _number);
static size_t FindIndexRemove( HashMap* _map, const void* _key);

HashMap* HashMap_Create(size_t _capacity, HashFunction _hashFunc, EqualityFunction _keysEqualFunc)
{
    
    HashMap* hashmap;
    if( NULL == _hashFunc || NULL == _keysEqualFunc || _capacity<1)
    {
        return NULL;
    }
    if(NULL == (hashmap = calloc(1,sizeof(struct HashMap) )))
 	{
   		return NULL;
    }
	hashmap->m_capacity = FindNextPrimeNumber(_capacity);
    if(NULL == /*(void*)*/(hashmap->m_hastable = calloc(hashmap->m_capacity,sizeof(Pair))))
 	{
        free(hashmap);
   		return NULL;
    }
    hashmap->m_user_capacity = _capacity;
    hashmap->m_hashFunc = _hashFunc;
    hashmap->m_equalFunc = _keysEqualFunc;
    hashmap->m_nElement = 0;
	hashmap->m_maxsteps = 1;
    return hashmap;
}

static size_t isPrime(size_t _num)
{
	size_t i;

	for(i = 2; i * i <= _num; ++i)
	{
		if(_num % i == 0)
		{
			return FALSE;
		}
	}

	return TRUE;
}

static size_t FindNextPrimeNumber(size_t _number)
{
	while(isPrime(_number) != TRUE)
	{
		_number++;
	}

	return _number;
}

void HashMap_Destroy(HashMap** _map, DestroyFunction _keyDestroy, DestroyFunction _valDestroy)
{
	if(NULL == _map  ||  NULL == *_map || (*_map)->m_hastable == NULL)
	{	
		return;
	}

	DestroyPairs(_map, _keyDestroy, _valDestroy);
	
	free((*_map)->m_hastable);
	(*_map)->m_hastable = NULL;
	free(*_map);
	(*_map) = NULL;
}

static void DestroyPairs(HashMap** _map, DestroyFunction _keyDestroy, DestroyFunction _valDestroy)
{
	int i;
	
	
	for(i = 0; i < (*_map)->m_capacity; ++i)
	{
		if((*_map)->m_hastable[i].m_key != NULL && (*_map)->m_hastable[i].m_key != DELETED)
		{
			if(_keyDestroy)
			{
				_keyDestroy((*_map)->m_hastable[i].m_key);
			}
			if(_valDestroy)
			{
				_valDestroy((*_map)->m_hastable[i].m_value);
			}
        	
		}
	}
	
}


 Map_Result HashMap_Find(const HashMap* _map, const void* _key, void** _pValue)
{
	size_t hashNum,i;
	const void* currkey;
	if (_map == NULL)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if (_key == NULL)
	{
		return MAP_KEY_NULL_ERROR;
	}
	hashNum = _map->m_hashFunc(_key) % _map->m_capacity;
	for(i=hashNum ; i <= hashNum + _map->m_maxsteps; i++ )
	{
		currkey = _map->m_hastable[i % _map->m_capacity].m_key;
		if(currkey == NULL)
		{
			break;
		}

		if(currkey != DELETED && _map->m_equalFunc(currkey, _key))
		{
			*_pValue = _map->m_hastable[i % _map->m_capacity].m_value;
			return MAP_SUCCESS;
		}

	}
	return MAP_KEY_NOT_FOUND_ERROR;
}

double Hash_AverageCollisions(const HashMap* _hash)
{
	if (_hash == NULL)
	{
		return -1;
	}
	return (double)_hash->m_colissions/(double)_hash->m_capacity;

}


static size_t FindIndex( HashMap* _map, const void* _key)
{
	size_t nCollisions=0;
	size_t i = _map->m_hashFunc(_key) % _map->m_capacity;
	
	while(_map->m_hastable[i].m_key != NULL && (size_t)_map->m_hastable[i].m_key != 1)
	{
		i = (i + 1) % _map->m_capacity;
		nCollisions++;
	}
	_map->m_colissions += nCollisions;
	if(_map->m_maxsteps < nCollisions)
	{
		_map->m_maxsteps = nCollisions;
	}
	return i;
}

static size_t FindIndexRemove( HashMap* _map, const void* _key)
{
	size_t steps=0,j;
	size_t i = _map->m_hashFunc(_key) % _map->m_capacity;
	j=i;
	while(_map->m_hastable[j].m_key != _map->m_hastable[i].m_key)
	{
		if(steps == _map->m_capacity)
		{
			break;
		}
		i = (i + 1) % _map->m_capacity;
		steps++;
		j++;	
	}
	return j;
}






Map_Result HashMap_Insert(HashMap* _map, const void* _key, void* _value)
{
	void* val;
	Map_Result result;
	size_t index;
	result = CheckNull(_map, _key, _value);
	if (result != MAP_SUCCESS)
	{
		return result;
	}
	if(_map->m_nElement == _map->m_user_capacity)
	{
		return MAP_OVERFLOW_ERROR;
	}
	result = HashMap_Find(_map, _key, &val);
	if (result != MAP_KEY_NOT_FOUND_ERROR)
	{
		return MAP_KEY_DUPLICATE_ERROR;
	}
	index = FindIndex(_map, _key);
	_map->m_hastable[index].m_key = _key;
	_map->m_hastable[index].m_value = _value;
	_map->m_nElement++;
	return MAP_SUCCESS;
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
size_t HashMap_Size(const HashMap* _map)
{
    if(NULL == _map)
    {
        return 0;
    }
    return _map->m_nElement;
}

Map_Result HashMap_Remove(HashMap* _map, const void* _searchKey, const void** _pKey, void** _pValue)
{
	size_t hashNum;
	void* value;
	Map_Result status;
	if(_map == NULL)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if (_searchKey == NULL)
	{
		return MAP_KEY_NULL_ERROR;
	}
	
	status = HashMap_Find(_map, _searchKey, &value);
	if (status == MAP_KEY_NOT_FOUND_ERROR)
	{
		return status;
	}
	/* hashNum = _map->m_hashFunc(_searchKey) % _map->m_capacity; */
	/*TODO find function*/
	hashNum = FindIndexRemove( _map, _searchKey);  /*TODO the change*/
	*_pValue = _map->m_hastable[hashNum].m_value;
	*_pKey = _map->m_hastable[hashNum].m_key;
	_map->m_hastable[hashNum].m_key = DELETED;
	_map->m_nElement--;
	return MAP_SUCCESS;
}

size_t HashMap_ForEach(const HashMap* _map, KeyValueActionFunction _action, void* _context)
{
	int i;
	size_t count = 0;
	
	if (_map == NULL || _action == NULL || _map->m_nElement == 0 || _context == NULL)
	{
		return count;
	}
	for (i = 0; i < _map->m_capacity; ++i)
	{	
		if(_map->m_hastable[i].m_key == NULL || *(int*)_map->m_hastable[i].m_key == 1)
		{
			continue;
		}
		if (!_action(_map->m_hastable[i].m_key, _map->m_hastable[i].m_value, _context))
		{
			break;
		}
		count++;
	}
	return count;
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
	size_t i;
	if (_map == NULL)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if (_map->m_nElement > newCapacity)
	{
		return MAP_OVERFLOW_ERROR;
	}
	newMap = HashMap_Create(newCapacity, _map->m_hashFunc, _map->m_equalFunc);
	if (newMap == NULL)
	{
		return MAP_ALLOCATION_ERROR;
	}
	for(i=0;i<_map->m_capacity;i++)
	{
		HashMap_Insert(newMap,_map->m_hastable[i].m_key,_map->m_hastable[i].m_value );
	
	}
	swapMap(_map, newMap);
	HashMap_Destroy(&newMap,NULL, NULL);
	
	return MAP_SUCCESS;
}


