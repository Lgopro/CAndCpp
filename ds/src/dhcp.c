/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 24/06/2023
*/

#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/
#include <math.h> /*pow*/

#include "dhcp.h" 

#define BEGIN 0 
#define NO_STOP 0 
#define YES_STOP 1
#define UNTIL_GET_IP 1
#define FOUR_BYTES_IN_BIT 32
typedef struct Node node_t;

typedef enum status
{
    NOT_OCCUPIED = 0,
    OCCUPIED

}status_t;

typedef enum child
{
    LEFT = 0,
    RIGHT, 
    AMOUNT_OF_CHILDREN

}child_t;

struct Node
{
    node_t *children[AMOUNT_OF_CHILDREN];
    status_t status;
    int value;

};

struct dhcp 
{
    size_t subnet_size_in_bits;
    unsigned char * subnet_ip;
    node_t *root;
    int network[FOUR_BYTES_IN_BIT];
    int server[FOUR_BYTES_IN_BIT];
    int broadcast[FOUR_BYTES_IN_BIT];
};


static void DHCPCNodeDestroy(node_t *root);
static unsigned char FromBinaryToNumber(int *number);
static dhcp_status_t AllocateCustomMade(node_t *root,size_t amount_of_steps,int *arr_all_binary_representation);
static dhcp_status_t AllocateMin(node_t *root,size_t amount_of_steps,int *arr_all_binary_representation);
static dhcp_status_t Plus1(dhcp_t *dhcp, int arr_all_binary_representation[FOUR_BYTES_IN_BIT]);
static void FillContainter(int arr_all_binary_representation[FOUR_BYTES_IN_BIT], unsigned char container_ip[BYTES_IN_IP]);
static dhcp_status_t RemoveFromTrie(node_t *root, size_t amount_of_steps, int arr_all_binary_representation[FOUR_BYTES_IN_BIT]);
static int ToStop(node_t *root, size_t amount_of_steps);
static void FindOccupied(node_t *root , size_t height_counter, size_t *counter);
static void FindRightLocation(int *arr, size_t amount_of_steps, int value);
static void InsertUserData(int *arr, size_t begin_value, size_t amount_of_steps, const unsigned char request_ip[BYTES_IN_IP]);
static void InsertUserDataToTraverse(int *arr, size_t begin_value, size_t amount_of_steps, const unsigned char request_ip[BYTES_IN_IP]);
static void ApplyMirror(int *array, size_t subnet_size_in_bits);
static void Mirror(int *array, int *array_to_help,size_t begin, size_t end);
static node_t *AllocateNode(node_t *root, size_t direction);
static status_t IsNotOccupied(node_t *root);


dhcp_t *DHCPCreate (const unsigned char subnet_ip[BYTES_IN_IP], size_t subnet_size_in_bits)
{
    dhcp_t *dhcp = NULL;
    unsigned char network[BYTES_IN_IP] = {0, 0, 0, 0};
    unsigned char server[BYTES_IN_IP] = {255, 255, 255, 254};
    unsigned char broadcast[BYTES_IN_IP] = {255, 255, 255, 255};

    assert(subnet_ip);

    dhcp = (dhcp_t *)malloc(sizeof(dhcp_t) + sizeof(char) * BYTES_IN_IP);
    if(NULL == dhcp)
    {
        return NULL;
    }
    dhcp->root = (node_t *)malloc(sizeof(node_t));
    if(NULL == dhcp->root)
    {
        free(dhcp);
        return NULL;
    }

    InsertUserData(dhcp->network,BEGIN , subnet_size_in_bits, subnet_ip);
    InsertUserData(dhcp->network,subnet_size_in_bits , FOUR_BYTES_IN_BIT, network);

    InsertUserData(dhcp->server,BEGIN , subnet_size_in_bits, subnet_ip);
    InsertUserData(dhcp->server,subnet_size_in_bits , FOUR_BYTES_IN_BIT, server);

    InsertUserData(dhcp->broadcast,BEGIN , subnet_size_in_bits, subnet_ip);
    InsertUserData(dhcp->broadcast,subnet_size_in_bits , FOUR_BYTES_IN_BIT, broadcast);

    dhcp->root->children[LEFT] = NULL;
    dhcp->root->children[RIGHT] = NULL;
    dhcp->root->status = NOT_OCCUPIED;
    dhcp->root->value = -1;
    dhcp->subnet_size_in_bits = subnet_size_in_bits;
    dhcp->subnet_ip = (unsigned char *)subnet_ip;

    return dhcp;
}


void DHCPDestroy(dhcp_t *dhcp)
{
    assert(dhcp);

    DHCPCNodeDestroy(dhcp->root);
    free(dhcp);
    dhcp = NULL;
}

dhcp_status_t DHCPAllocIP(dhcp_t *dhcp, const unsigned char request_ip[BYTES_IN_IP], unsigned char container_ip[BYTES_IN_IP])
{
    dhcp_status_t status = DHCP_SUCCESS;
    dhcp_status_t plus_status = DHCP_SUCCESS;

    assert(dhcp);
    assert(container_ip);
    

    if(NULL == request_ip)
    {
        status = AllocateMin(dhcp->root, dhcp->subnet_size_in_bits, dhcp->network);
        FillContainter(dhcp->network, container_ip);
        return status;
    }
    
    InsertUserDataToTraverse(dhcp->network, dhcp->subnet_size_in_bits , FOUR_BYTES_IN_BIT, request_ip);
    while(UNTIL_GET_IP)
    {
        if(DHCP_SUCCESS != AllocateCustomMade(dhcp->root, dhcp->subnet_size_in_bits, dhcp->network))
        {
            plus_status = Plus1(dhcp, dhcp->network);
            if(DHCP_FAILURE == plus_status)
            {
                request_ip = NULL;
                break;
            }
        }
        else
        {
            ApplyMirror(dhcp->network, dhcp->subnet_size_in_bits);
            FillContainter(dhcp->network, container_ip);
            return DHCP_SUCCESS;
        }
    }

    
    status = AllocateMin(dhcp->root, dhcp->subnet_size_in_bits, dhcp->network);
    FillContainter(dhcp->network, container_ip);
    return status;
   
    
}

dhcp_status_t DHCPFreeIP(dhcp_t *dhcp, const unsigned char ip_to_free[BYTES_IN_IP])
{
    assert(dhcp);
    assert(ip_to_free);

    InsertUserDataToTraverse(dhcp->network,dhcp->subnet_size_in_bits , FOUR_BYTES_IN_BIT, ip_to_free);
    return RemoveFromTrie(dhcp->root, dhcp->subnet_size_in_bits, dhcp->network);
}


size_t DHCPCountFree(const dhcp_t *dhcp)
{
    size_t count_occupied_amount = 0;
    size_t max_amount = 0;

    assert(dhcp);

    max_amount = pow(2, (FOUR_BYTES_IN_BIT - dhcp->subnet_size_in_bits)) - 1;
    FindOccupied(dhcp->root , dhcp->subnet_size_in_bits, &count_occupied_amount);
    return (max_amount - count_occupied_amount);
}



/********************static functions********************/
static void FindRightLocation(int *arr, size_t amount_of_steps, int value)
{
    size_t byte = 4 * amount_of_steps / 32;
    size_t location_in_byte = 31 % 8 - amount_of_steps % 8;
    size_t location_in_array = byte * 8 + location_in_byte;
    *(arr + location_in_array) = value;
}

static void InsertUserDataToTraverse(int *arr, size_t begin_value, size_t amount_of_steps, const unsigned char request_ip[BYTES_IN_IP])
{
    size_t i = begin_value;
    size_t byte = 0;
    size_t location_in_byte = 0;
    size_t location_in_array = 0;
    int value = 0;
    while(i < amount_of_steps)
    {
        byte = 4 * i / FOUR_BYTES_IN_BIT;
        location_in_byte = i % 8;
        location_in_array = byte * 8 + 7 - location_in_byte;
        if(0 < (request_ip[byte] & (1 << location_in_byte)))
        {
            value = 1;
        }
        else
        {
            value = 0;
        }
        *(arr + location_in_array) = value;
        ++i;
    }
}

static void InsertUserData(int *arr, size_t begin_value, size_t amount_of_steps, const unsigned char request_ip[BYTES_IN_IP])
{
    size_t i = begin_value;
    size_t byte = 0;
    size_t location_in_byte = 0;
    size_t location_in_array = 0;
    int value = 0;
    while(i < amount_of_steps)
    {
        byte = 4 * i / 32;
        location_in_byte = 7 - i % 8;
        location_in_array = byte * 8 + location_in_byte;
        if(0 < (request_ip[byte] & (1 << location_in_byte)))
        {
            value = 1;
        }
        else
        {
            value = 0;
        }
        *(arr + location_in_array) = value;
        ++i;
    }
}
static void FindOccupied(node_t *root , size_t height_counter, size_t *counter)
{
    if(FOUR_BYTES_IN_BIT == height_counter)
    {
        ++(*counter);
        return;
    }
    if(NULL != root->children[LEFT])
    {
        FindOccupied(root->children[LEFT] , height_counter + 1, counter);
    }
    if(NULL != root->children[RIGHT])
    {
        FindOccupied(root->children[RIGHT] , height_counter + 1, counter);
    }
}

static dhcp_status_t RemoveFromTrie(node_t *root, size_t amount_of_steps, int arr_all_binary_representation[FOUR_BYTES_IN_BIT])
{
    dhcp_status_t status = DHCP_SUCCESS;
   
    if(FOUR_BYTES_IN_BIT == amount_of_steps)
    {
        root->children[LEFT] = NULL;
        root->children[RIGHT] = NULL;
        free(root);
        return DHCP_SUCCESS;
    }
    else if(0 == arr_all_binary_representation[amount_of_steps] && NULL == root->children[LEFT])
    {
        return DHCP_FAILURE;
    }
    else if(0 == arr_all_binary_representation[amount_of_steps] && NULL != root->children[LEFT])
    {
        status = RemoveFromTrie(root->children[LEFT], amount_of_steps + 1, arr_all_binary_representation);  
        if(31 == amount_of_steps)
        {
            root->children[LEFT] = NULL;
        }
        root->status = IsNotOccupied(root);
    }
    else if(1 == arr_all_binary_representation[amount_of_steps] && NULL == root->children[RIGHT])
    {
        return DHCP_FAILURE;
    }
    else if(1 == arr_all_binary_representation[amount_of_steps] && NULL != root->children[RIGHT])
    {
        status = RemoveFromTrie(root->children[RIGHT], amount_of_steps + 1, arr_all_binary_representation);  
        if(31 == amount_of_steps)
        {
            root->children[RIGHT] = NULL;
        }
        root->status = IsNotOccupied(root);
    }
    return status;
}

static status_t IsNotOccupied(node_t *root)
{
    if(OCCUPIED == root->status && ((NULL == root->children[LEFT] || NULL == root->children[RIGHT]) || 
    (OCCUPIED != root->children[LEFT]->status || OCCUPIED != root->children[RIGHT]->status)))
    {
        return NOT_OCCUPIED;
    }
    return root->status;
}

static void FillContainter(int arr_all_binary_representation[FOUR_BYTES_IN_BIT], unsigned char container_ip[BYTES_IN_IP])
{
    size_t i = 0;
    for(i = 0; i < BYTES_IN_IP; ++i)
    {
        container_ip[i] = FromBinaryToNumber((arr_all_binary_representation + 8 * i));
    }
}


static dhcp_status_t Plus1(dhcp_t *dhcp, int arr_all_binary_representation[FOUR_BYTES_IN_BIT])
{
    size_t byte = 0;
    size_t bit = 0;
    size_t i = 0;
 
    for(i = 31; i > dhcp->subnet_size_in_bits; --i)
    {
        byte = (i / 32) * 4;
        bit = i - byte * 8;
        if(1 == arr_all_binary_representation[byte * 8 + bit])
        {
            arr_all_binary_representation[byte * 8 + bit] = 0;
        }
        else
        {
            arr_all_binary_representation[byte * 8 + bit] = 1;
            break;
        }
    }
    if(i == dhcp->subnet_size_in_bits)
    {
        return DHCP_FAILURE;
    }
    return DHCP_SUCCESS;
}

static dhcp_status_t AllocateCustomMade(node_t *root,size_t amount_of_steps,int *arr_all_binary_representation)
{
    dhcp_status_t status = DHCP_SUCCESS;
    int stop_status = NO_STOP;

    stop_status = ToStop(root, amount_of_steps);
    if(YES_STOP == stop_status)
    {
        return DHCP_SUCCESS;
    }
    else if(0 == arr_all_binary_representation[amount_of_steps] && NULL == root->children[LEFT])
    {
        root->children[LEFT] = AllocateNode(root, LEFT);
        if(NULL == root->children[LEFT])
        {
            return DHCP_FAILURE;
        }
        status = AllocateCustomMade(root->children[LEFT], amount_of_steps + 1, arr_all_binary_representation);  
    }
    else if(0 == arr_all_binary_representation[amount_of_steps] && NULL != root->children[LEFT] && OCCUPIED == root->children[LEFT]->status)
    {
        return DHCP_FAILURE;
    }
    else if(0 == arr_all_binary_representation[amount_of_steps] && NULL != root->children[LEFT])
    {
        status = AllocateCustomMade(root->children[LEFT], amount_of_steps + 1, arr_all_binary_representation);  
    }
    else if(1 == arr_all_binary_representation[amount_of_steps] && NULL == root->children[RIGHT])
    {
        root->children[RIGHT] = AllocateNode(root, RIGHT);
        if(NULL == root->children[RIGHT])
        {
            return DHCP_FAILURE;
        }
        status = AllocateCustomMade(root->children[RIGHT], amount_of_steps + 1, arr_all_binary_representation);  
    }
    else if(1 == arr_all_binary_representation[amount_of_steps] && NULL != root->children[RIGHT] && OCCUPIED == root->children[RIGHT]->status)
    {
        return DHCP_FAILURE;
    }
    else if(1 == arr_all_binary_representation[amount_of_steps] && NULL != root->children[RIGHT])
    {
        status = AllocateCustomMade(root->children[RIGHT], amount_of_steps + 1, arr_all_binary_representation);  
    }

    if(NULL != root->children[LEFT] && NULL != root->children[RIGHT])
    {
        if(OCCUPIED == root->children[LEFT]->status && OCCUPIED == root->children[RIGHT]->status)
        {
            root->status = OCCUPIED;
        }
    }
    return status;
}

static dhcp_status_t AllocateMin(node_t *root,size_t amount_of_steps,int *arr_all_binary_representation)
{
    dhcp_status_t status = DHCP_SUCCESS;
    int stop_status = NO_STOP; 

    stop_status = ToStop(root, amount_of_steps);
    if(YES_STOP == stop_status)
    {
        root->status = OCCUPIED;
        return DHCP_SUCCESS;
    }

    if(NULL != root->children[LEFT] && NULL != root->children[RIGHT] && OCCUPIED == root->children[LEFT]->status 
       && OCCUPIED == root->children[RIGHT]->status)
    {  
        return DHCP_FAILURE;

    }
    else if(NULL == root->children[LEFT])
    {
        root->children[LEFT] = AllocateNode(root, LEFT);
        if(NULL == root->children[LEFT])
        {
            return DHCP_FAILURE;
        }
        FindRightLocation(arr_all_binary_representation, amount_of_steps, 0);
        status = AllocateMin(root->children[LEFT], amount_of_steps + 1, arr_all_binary_representation);
    }
    else if(NULL != root->children[LEFT] && OCCUPIED != root->children[LEFT]->status)
    {
        FindRightLocation(arr_all_binary_representation, amount_of_steps, 0);
        status = AllocateMin(root->children[LEFT], amount_of_steps + 1, arr_all_binary_representation);   
    }
    else if(OCCUPIED == root->children[LEFT]->status && NULL == root->children[RIGHT])
    {
        root->children[RIGHT] = AllocateNode(root, RIGHT);
        if(NULL == root->children[RIGHT])
        {
            return DHCP_FAILURE;
        }
        FindRightLocation(arr_all_binary_representation, amount_of_steps, 1);
        status = AllocateMin(root->children[RIGHT], amount_of_steps + 1, arr_all_binary_representation);  
    }
    else if(OCCUPIED == root->children[LEFT]->status && OCCUPIED != root->children[RIGHT]->status)
    {
        FindRightLocation(arr_all_binary_representation, amount_of_steps, 1);
        status = AllocateMin(root->children[RIGHT], amount_of_steps + 1, arr_all_binary_representation);  
    }

    if(NULL != root->children[LEFT] && NULL != root->children[RIGHT])
    {
        if(OCCUPIED == root->children[LEFT]->status && OCCUPIED == root->children[RIGHT]->status)
        {
            root->status = OCCUPIED;
        }
    }

    return status;
}




static int ToStop(node_t *root, size_t amount_of_steps)
{
    if(FOUR_BYTES_IN_BIT == amount_of_steps)
    {
        root->status = OCCUPIED;
        return YES_STOP;
    }
    return NO_STOP;
}

static node_t *AllocateNode(node_t *root, size_t direction)
{
    root->children[direction] = (node_t *)malloc(sizeof(node_t));
    if(NULL == root->children[direction])
    {
        return NULL;
    }
    root->children[direction]->children[LEFT] = NULL;
    root->children[direction]->children[RIGHT] = NULL;
    root->children[direction]->status = NOT_OCCUPIED;
    root->children[direction]->value = 0;
    return root->children[direction];
}

static void DHCPCNodeDestroy(node_t *root)
{
	if(NULL == root)
	{
		return;
	}
	
	DHCPCNodeDestroy(root->children[LEFT]);
	DHCPCNodeDestroy(root->children[RIGHT]);
	free(root);
}


static unsigned char FromBinaryToNumber(int *number) 
{
	int i = 0;
    unsigned char sum = 0;
	for(i = 7; i >= 0; --i)
	{
		if((*(number + i)))
		{
			sum^=(1 << i);
		}
	}
	return sum;
}

static void ApplyMirror(int *array, size_t subnet_size_in_bits)
{
    size_t i = 0;
    int array_to_help[8] = {0};
    size_t byte = 4 * subnet_size_in_bits / 32;
    size_t location_in_byte = 7 - subnet_size_in_bits % 8;
    Mirror((array + byte * 8), array_to_help, location_in_byte, 7);
    
    for(i = byte; i < 4; ++i)
    {
        Mirror((array + byte * 8), array_to_help, 0, 7);
    }
}

static void Mirror(int *array, int *array_to_help,size_t begin, size_t end)
{
    size_t i = 0;
    int j = (int)end;
    for(i = begin; i <= end; ++i)
    {
        array_to_help[j] = array[i];
        --j;
    }
     for(i = begin; i <= end; ++i)
    {
        array[i] = array_to_help[i];
    }
}