
/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 24/06/2023
*/

#include <stdio.h> /*printf*/
#include <stdlib.h>


#include "dhcp.h" 



#define FOUR_BYTES_IN_BIT 32




void DHCPCreateTest();
void DHCPAddTest1();
void DHCPAddMinTest();
void DHCPAddCustomTest();
void DHCPFreeMinTest();
void DHCPAddTest2();
void DHCPAddTest3();
void DHCPFreeIPTest();
void DHCPCountTest();
void IpTest();



int main()
{	
    IpTest();
	DHCPCreateTest();
    DHCPAddTest1();
    DHCPAddTest2();
    DHCPAddTest3();
    DHCPFreeIPTest();
    DHCPCountTest();
	return 0;
}

void IpTest()
{
    size_t i = 0;
    size_t j = 0;
    const unsigned char arr[BYTES_IN_IP] = {192, 168, 0, 0};
    size_t subnet_size_in_bits = 29;
    unsigned char container_ip[BYTES_IN_IP]= {0};
    dhcp_status_t status1 = 0;
    dhcp_status_t status2 = 0;
    dhcp_status_t status3 = 0;
    dhcp_status_t status4 = 0;
    dhcp_status_t status5 = 0;
	dhcp_t *dhcp = DHCPCreate (arr, subnet_size_in_bits);
    for(i = 0; i < 5; ++i)
    {
        DHCPAllocIP(dhcp, NULL, container_ip);

        for(j = 0; j < 4; ++j)
        {
            printf("%d ", ((int)container_ip[j]));
        }
        printf("\n");
    }
    DHCPFreeIP(dhcp, arr);
    DHCPAllocIP(dhcp, NULL, container_ip);
    for(j = 0; j < 4; ++j)
    {
        printf("%d ", ((int)container_ip[j]));
    }
    printf("\n");

	if(NULL != dhcp)
	{
		printf("DHCPAddTest2 pass\n");
	}
	else
	{
		printf("DHCPAddTest2 fail\n");
        printf("status1 %d\n", status1);
        printf("status2 %d\n", status2);
        printf("status3 %d\n", status3);
        printf("status4 %d\n", status4);
        printf("status5 %d\n", status5);

	}
    DHCPDestroy(dhcp);
}

void DHCPCountTest()
{
    size_t i = 0;
    const unsigned char arr[BYTES_IN_IP] = {192, 168, 15, 0};
    size_t subnet_size_in_bits = 24;
    unsigned char container_ip[BYTES_IN_IP]= {0};
    
	dhcp_t *dhcp = DHCPCreate (arr, subnet_size_in_bits);
    for(i = 0; i < 100; ++i)
    {
        DHCPAllocIP(dhcp, NULL, container_ip);
    }
	if(NULL != dhcp && 155 == DHCPCountFree(dhcp))
	{
		printf("DHCPCountTest pass\n");
	}
	else
	{
		printf("DHCPCountTest fail\n");
        
	}
    DHCPDestroy(dhcp);
}
void DHCPFreeIPTest(void)
{
    size_t i = 0;
    size_t j = 0;
    unsigned char arr[BYTES_IN_IP] = {192, 168, 15, 0};
    size_t subnet_size_in_bits = 24;
    unsigned char container_ip[BYTES_IN_IP]= {0};
    
	dhcp_t *dhcp = DHCPCreate (arr, subnet_size_in_bits);
    for(i = 0; i < 100; ++i)
    {
        DHCPAllocIP(dhcp, NULL, container_ip);
        for(j = 0; j < 4; ++j)
        {
            printf("%d ", ((int)container_ip[j]));
        }
        printf("\n");
    }
    for(i = 0; i < 100; ++i)
    {
        arr[3] = i;
        DHCPFreeIP(dhcp, arr);
    }
    for(i = 0; i < 100; ++i)
    {
        DHCPAllocIP(dhcp, NULL, container_ip);
        for(j = 0; j < 4; ++j)
        {
            printf("%d ", ((int)container_ip[j]));
        }
        printf("\n");
    }
	if(NULL != dhcp)
	{
		printf("DHCPAddTest1 pass\n");
	}
	else
	{
		printf("DHCPAddTest1 fail\n");
	}
    DHCPDestroy(dhcp);
}

void DHCPCreateTest()
{
    const unsigned char arr[BYTES_IN_IP] = {192, 168, 0, 0};
    size_t subnet_size_in_bits = 16;
	dhcp_t *dhcp = DHCPCreate (arr, subnet_size_in_bits);
	if(NULL != dhcp)
	{
		printf("DHCPCreateTest pass\n");
		
	}
	else
	{
		
		printf("DHCPCreateTest fail\n");
		
	}
    DHCPDestroy(dhcp);
}

void DHCPAddTest1()
{
    size_t i = 0;
    size_t j = 0;
    const unsigned char arr[BYTES_IN_IP] = {192, 168, 15, 0};
    size_t subnet_size_in_bits = 24;
    unsigned char container_ip[BYTES_IN_IP]= {0};
    
	dhcp_t *dhcp = DHCPCreate (arr, subnet_size_in_bits);
    for(i = 0; i < 100; ++i)
    {
        DHCPAllocIP(dhcp, NULL, container_ip);
        for(j = 0; j < 4; ++j)
        {
            printf("%d ", ((int)container_ip[j]));
        }
        printf("\n");
    }

	if(NULL != dhcp)
	{
		printf("DHCPAddTest1 pass\n");
	}
	else
	{
		printf("DHCPAddTest1 fail\n");
	}
    DHCPDestroy(dhcp);

}

void DHCPAddTest2()
{
    size_t i = 0;
    size_t j = 0;
    const unsigned char arr[BYTES_IN_IP] = {192, 168, 0, 0};
    unsigned char arr_to_innsert[BYTES_IN_IP] = {192, 168, 0, 0};
    size_t subnet_size_in_bits = 24;
    unsigned char container_ip[BYTES_IN_IP]= {0};
    dhcp_status_t status1 = 0;
    dhcp_status_t status2 = 0;
    dhcp_status_t status3 = 0;
    dhcp_status_t status4 = 0;
    dhcp_status_t status5 = 0;
	dhcp_t *dhcp = DHCPCreate (arr, subnet_size_in_bits);
    for(i = 100; i < 255; ++i)
    {
        arr_to_innsert[3] = i;
        DHCPAllocIP(dhcp, arr_to_innsert, container_ip);

        for(j = 0; j < 4; ++j)
        {
            printf("%d ", ((int)container_ip[j]));
        }
        printf("\n");
    }
	if(NULL != dhcp)
	{
		printf("DHCPAddTest2 pass\n");
	}
	else
	{
		printf("DHCPAddTest2 fail\n");
        printf("status1 %d\n", status1);
        printf("status2 %d\n", status2);
        printf("status3 %d\n", status3);
        printf("status4 %d\n", status4);
        printf("status5 %d\n", status5);

	}
    DHCPDestroy(dhcp);
}


void DHCPAddTest3()
{
    size_t i = 0;
    size_t j = 0;
    size_t counter = 0;
    const unsigned char arr[BYTES_IN_IP] = {192, 168, 0, 0};
    unsigned char arr_to_innsert[BYTES_IN_IP] = {192, 168, 0, 0};
    size_t subnet_size_in_bits = 24;
    unsigned char container_ip[BYTES_IN_IP]= {0};
    dhcp_status_t status1 = 0;
    dhcp_status_t status2 = 0;
    dhcp_status_t status3 = 0;
    dhcp_status_t status4 = 0;
    dhcp_status_t status5 = 0;
	dhcp_t *dhcp = DHCPCreate (arr, subnet_size_in_bits);
    while(counter < 100)
    {
        arr_to_innsert[3] = i;
        DHCPAllocIP(dhcp, arr_to_innsert, container_ip);

        for(j = 0; j < 4; ++j)
        {
            printf("%d ", ((int)container_ip[j]));
        }
        printf("\n");
        ++counter;
    }
	if(NULL != dhcp)
	{
		printf("DHCPAddTest3 pass\n");
	}
	else
	{
		printf("DHCPAddTest3 fail\n");
        printf("status1 %d\n", status1);
        printf("status2 %d\n", status2);
        printf("status3 %d\n", status3);
        printf("status4 %d\n", status4);
        printf("status5 %d\n", status5);

	}
    DHCPDestroy(dhcp);
}



