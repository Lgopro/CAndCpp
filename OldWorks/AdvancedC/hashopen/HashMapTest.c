
#include <stdio.h>
#include "mu_test.h"
#include "HashMap.h"


size_t HashFunc(const void* _key)
{
	return *(size_t*)_key;
}
int Equality(const void* _firstKey,const void* _secondKey)
{
	return (*(int*)_firstKey == *(int*)_secondKey);
}

void DestroyPart(const void* _item)
{
	if(NULL == _item)
	{
		return;
	}
	_item = NULL;
}



int	Action(const void* _key, void* _value, void* _context)
{
	return (*(int*)_value < *(int*)_context);
}

UNIT(Hash_Create_Null)

	ASSERT_THAT(HashMap_Create(10, NULL, Equality) == NULL);
	ASSERT_THAT(HashMap_Create(10, HashFunc, NULL) == NULL);

END_UNIT


UNIT(Hash_Create_Not_Null)
	HashMap* map;
	map = HashMap_Create(10, HashFunc, Equality);
	ASSERT_THAT(map != NULL);
	HashMap_Destroy(&map, DestroyPart, DestroyPart);

END_UNIT

UNIT(Hash_Delete_Not_Null)
	HashMap* map;
	map = HashMap_Create(10, HashFunc, Equality);
	ASSERT_THAT(map != NULL);
	HashMap_Destroy(&map, DestroyPart, DestroyPart);

END_UNIT


UNIT(Hash_Insert_Not_Null)
	HashMap* map;
	int a=5,b=6,c=7,d=8;
	map = HashMap_Create(10, HashFunc, Equality);
	ASSERT_THAT(map != NULL);
	HashMap_Insert(map, (const void*)&a,  (void*)&b);
	ASSERT_THAT(HashMap_Size(map)==1);
	HashMap_Insert(map, (const void*)&c,  (void*)&d);
	ASSERT_THAT(HashMap_Size(map)==2);
	HashMap_Destroy(&map, DestroyPart, DestroyPart);

END_UNIT



UNIT(Hash_Find_Null)
	HashMap* map;
	const int b=4;
	void * a;
	Map_Result status;
	map = HashMap_Create(10, HashFunc, Equality);
	ASSERT_THAT(map != NULL);
	status = HashMap_Find(NULL, (void*)&b, (void**)&a);
	ASSERT_THAT(status == MAP_UNINITIALIZED_ERROR);
	status = HashMap_Find(map, NULL, (void**)&a);
	ASSERT_THAT(status == MAP_KEY_NULL_ERROR);
	HashMap_Destroy(&map, DestroyPart, DestroyPart);

END_UNIT

UNIT(Hash_Insert_Null)
	HashMap* map;
	int b=4;
	void * a;
	Map_Result status;
	a = &b;
	map = HashMap_Create(10, HashFunc, Equality);
	ASSERT_THAT(map != NULL);
	status = HashMap_Insert(NULL, (void*)&b, a);
	ASSERT_THAT(status == MAP_UNINITIALIZED_ERROR);
	status = HashMap_Insert(map, NULL, a);
	ASSERT_THAT(status == MAP_KEY_NULL_ERROR);
	HashMap_Destroy(&map, DestroyPart, DestroyPart);

END_UNIT

UNIT(Hash_Rehash_Null)
	HashMap* map;
	Map_Result status;
	map = HashMap_Create(10, HashFunc, Equality);
	ASSERT_THAT(map != NULL);
	status = HashMap_Rehash(NULL , 20);
	ASSERT_THAT(status == MAP_UNINITIALIZED_ERROR);
	status = HashMap_Rehash(map , 5);
	ASSERT_THAT(status == MAP_OVERFLOW_ERROR);
	HashMap_Destroy(&map, DestroyPart, DestroyPart);

END_UNIT


UNIT(Hash_Remove_Null)
	HashMap* map;
	Map_Result status;
	map = HashMap_Create(10, HashFunc, Equality);
	ASSERT_THAT(map != NULL);
	status = HashMap_Rehash(NULL , 20);
	ASSERT_THAT(status == MAP_UNINITIALIZED_ERROR);
	status = HashMap_Rehash(map , 5);
	ASSERT_THAT(status == MAP_SUCCESS);
	HashMap_Destroy(&map, DestroyPart, DestroyPart);

END_UNIT

UNIT(Hash_Remove_Not_Null)
	HashMap* map;
	const void* key;
	void* value;
	Map_Result status;
	int a=5,b=6,c=7,d=8;
	value = &a;
	key = &b;
	map = HashMap_Create(10, HashFunc, Equality);
	ASSERT_THAT(map != NULL);
	HashMap_Insert(map, (const void*)&a,  (void*)&b);
	ASSERT_THAT(HashMap_Size(map)==1);
	HashMap_Insert(map, (const void*)&c,  (void*)&d);
	ASSERT_THAT(HashMap_Size(map)==2);
	status = HashMap_Remove( map, (const void*)&a, (const void**) key, (void**) value);
	ASSERT_THAT(status == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Size(map)==1);
	HashMap_Destroy(&map, DestroyPart, DestroyPart);

END_UNIT


UNIT(Hash_Rehash_Not_Null)
	HashMap* map;
	Map_Result status;
	int a=5,b=6,c=7,d=8;
	map = HashMap_Create(2, HashFunc, Equality);
	ASSERT_THAT(map != NULL);
	HashMap_Insert(map, (const void*)&a,  (void*)&b);
	ASSERT_THAT(HashMap_Size(map) == 1);
	HashMap_Insert(map, (const void*)&c,  (void*)&d);
	ASSERT_THAT(HashMap_Size(map) == 2);
	status = HashMap_Rehash(map , 10);
	ASSERT_THAT(status == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Size(map) == 2);
	HashMap_Insert(map, (const void*)&a,  (void*)&b);
	ASSERT_THAT(HashMap_Size(map)==2);
	HashMap_Insert(map, (const void*)&c,  (void*)&d);
	ASSERT_THAT(HashMap_Size(map)==2);
	HashMap_Destroy(&map, DestroyPart, DestroyPart);

END_UNIT

UNIT(Hash_Find_Not_Null)
	HashMap* map;
	void* _pValue;
	
	int a=5,b=6,c=7,d=8,h;
	_pValue = &h;
	map = HashMap_Create(10, HashFunc, Equality);
	ASSERT_THAT(map != NULL);
	HashMap_Insert(map, (const void*)&a,  (void*)&b);
	ASSERT_THAT(HashMap_Size(map)==1);
	HashMap_Insert(map, (const void*)&c,  (void*)&d);
	ASSERT_THAT(HashMap_Size(map)==2);
	HashMap_Find(map, (const void*)&a, &_pValue);
	ASSERT_THAT(*(int*)_pValue == 6);
	HashMap_Destroy(&map, DestroyPart, DestroyPart);

END_UNIT

UNIT(Hash_For_each_Not_Null)
	HashMap* map;
	int a=5,b=6,c=7,d=8,h=10;
	size_t result;
	map = HashMap_Create(10, HashFunc, Equality);
	ASSERT_THAT(map != NULL);
	HashMap_Insert(map, (const void*)&a,  (void*)&b);
	ASSERT_THAT(HashMap_Size(map)==1);
	HashMap_Insert(map, (const void*)&c,  (void*)&d);
	ASSERT_THAT(HashMap_Size(map)==2);
	result=HashMap_ForEach(map,Action, (void*)&h);
	ASSERT_THAT(result == 2);
	result=HashMap_ForEach(map,Action, (void*)&a);
	ASSERT_THAT(result == 0);
	HashMap_Destroy(&map, DestroyPart, DestroyPart);

END_UNIT

UNIT(Hash_For_each_Null)
	HashMap* map;
	int h=10;
	size_t result;
	map = HashMap_Create(10, HashFunc, Equality);
	ASSERT_THAT(map != NULL);
	result=HashMap_ForEach(NULL,Action, (void*)&h);
	ASSERT_THAT(result == 0);
	result=HashMap_ForEach(map,NULL, (void*)&h);
	ASSERT_THAT(result == 0);
	result=HashMap_ForEach(map,Action, NULL);
	ASSERT_THAT(result == 0);
	result=HashMap_ForEach(map,Action, (void*)&h);
	ASSERT_THAT(result == 0);
	HashMap_Destroy(&map, DestroyPart, DestroyPart);

END_UNIT

TEST_SUITE(TEST_Hash)

	TEST(Hash_Create_Null)
	TEST(Hash_Create_Not_Null)
	TEST(Hash_Delete_Not_Null)
	TEST(Hash_Insert_Not_Null)
	TEST(Hash_Find_Null)
	TEST(Hash_Insert_Null)
	IGNORE_TEST(Hash_Rehash_Null)
	TEST(Hash_Remove_Not_Null)
	TEST(Hash_Find_Not_Null)
	TEST(Hash_For_each_Not_Null)
	TEST(Hash_For_each_Null)
	TEST(Hash_Rehash_Not_Null)
END_SUITE
