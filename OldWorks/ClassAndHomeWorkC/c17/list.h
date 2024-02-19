
typedef struct Person Person;
struct Person
{
    int     m_id;         /* Primary Key */
    char    m_name[128];
    int     m_age;
    Person* m_next;
};
/*
Description: Return the pointer to the last person.
Input: Pointer to the original Person struct .
Output: The pointer to last person.
Complexity: o(n).
*/
Person* LastPerson(struct Person* _head);
/*
Description: Inserts new block to the head of the function.
Input: Pointer to the original Person struct and the new block added.
Output: The struct after the insert of new function.
Complexity: o(n).
*/
struct Person* ListInsertHead(struct Person* _head ,struct Person* _p);
/*
Description: Deletes the first block of the struct.
Input: Pointer to the original Person struct and a double pointer to the adress of the deleted block.
Output: The struct after deleting the block.
Complexity: o(n).
*/
struct Person* ListRemoveHead(struct Person* _head,struct Person** _item);
/*
Description: Insert the new block by the value of the key.
Input: Pointer to the original Person struct, the key parameter and the block that the key is part of.
Output: The new struct of Person after adding the _p block.
Complexity: o(n).
*/
struct Person* ListInsertByKey(struct Person* _head, int _key,struct Person* _p);
/*
Description: Insert the new block by the value of the key recursivly.
Input: Pointer to the original Person struct, the key parameter and the block that the key is part of.
Output: The new struct of Person after adding the _p block.
Complexity: o(n).
*/
struct Person* ListInsertByKeyRec(struct Person* _head, int _key,struct Person* _p);
/*
Description: Remove the block by the key value if found and placing it adress in the _p struct.
Input: Pointer to the original Person struct, the key parameter and the parameter that gets the adress of the deleted block.
Output: The new struct of Person after removing the block if its found.
Complexity: o(n).
*/
struct Person* ListRemoveByKey(struct Person* _head, int _key,struct Person* *_p);
/*
Description: Remove the block by the key value if found and placing it adress in the _p struct recursivly.
Input: Pointer to the original Person struct, the key parameter and the parameter that gets the adress of the deleted block.
Output: The new struct of Person after removing the block if its found.
Complexity: o(n).
*/
struct Person* ListRemoveByKeyRec(struct Person* _head, int _key,struct Person**_p);
/*
Description: Print all the blocks of the Person struct.
Input: Pointer to the original Person struct.
Output: Void.
Complexity: o(n).
*/
void PrintList(struct Person* _head);

