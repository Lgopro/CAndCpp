

#include <stdio.h> /*assert*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*free*/


#define DEADBEEF (-2131231)
#define SUCCESS (0)
#define FAIL (1)
#define SIZE (10)

typedef struct binarytree
{
    size_t size;
    int arr[SIZE];
}tree_t;

int InsertTree(tree_t* tree, size_t location, int value);

int main()
{
    int i = 0;
    int status = 0;
    tree_t *tree = (tree_t *)malloc(sizeof(tree_t));
    tree->size = SIZE;
    for(i = 0; i < SIZE; ++i)
    {
        tree->arr[i] = DEADBEEF;
    }

    InsertTree(tree, 0, 5);
    InsertTree(tree, 0, 2);
    InsertTree(tree, 0, 6);
    InsertTree(tree, 0, 1);
    InsertTree(tree, 0, 10);
    status = InsertTree(tree, 0, 15);    
    if(tree->arr[0] == 5 && tree->arr[1] == 2 && tree->arr[2] == 6 && tree->arr[3] == 1 && tree->arr[6] == 10 && status == FAIL)
    {
        printf("Test pass\n");
    }
    for(i = 0; i < SIZE; ++i)
    {
        printf("%d ", tree->arr[i]);
    }
	return 0;
}

int InsertTree(tree_t* tree, size_t location, int value)
{
    int status = 0;
    if(location >= tree->size)
    {
        return (FAIL);
    }

    if(DEADBEEF ==  tree->arr[location])
    {
        tree->arr[location] = value;
        return (SUCCESS);
    }

    if(value ==  tree->arr[location])
    {
        return (FAIL);
    }

    if(value < tree->arr[location])
    {
        status = InsertTree(tree, location * 2 + 1, value);    
    }
    else
    {
        status = InsertTree(tree, location * 2 + 2, value);   
    }
    return (status);
}
