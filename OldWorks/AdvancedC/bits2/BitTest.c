#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "mu_test.h"
#include "Bit.h"



UNIT(Bit_Flip_One_Bit_Check)
	FlipOneBit(64,7);
END_UNIT

UNIT(Bit_Flip_Two_Bit_Check)
	FlipTwoBits(64 , 1, 7);
END_UNIT

UNIT(Bit_Multiply_By_TreeHalf_Check)
	int i,r;
	srand((unsigned int)time(NULL));
    for(i=0;i<100;i++)
    {
       	r=rand()%100;
       	ASSERT_THAT(MultiplyByTreeInHalf(r) == r*3+r/2);
    }	
END_UNIT

UNIT(Bit_Print_Check)
	int i;
    for(i=0;i<1000;i=i+100)
    {
         printf("%d is:",i);

         PrintBit(i);
    }
END_UNIT

UNIT(Bit_Power_of_two_Table_Check)
	int status;
    status=PowerOfTwoTable(64);
    ASSERT_THAT(status == 1);
    status=PowerOfTwoTable(1);
    ASSERT_THAT(status == 1);
    status=PowerOfTwoTable(3);
    ASSERT_THAT(status == 0);
    status=PowerOfTwoTable(5);
    ASSERT_THAT(status == 0);
    status=PowerOfTwoTable(8);
    ASSERT_THAT(status == 1);
    status=PowerOfTwoTable(9);
	ASSERT_THAT(status == 0);
END_UNIT

UNIT(Bit_Power_of_two_Check)
	int status;
    status=PowerOfTwo(64);
    ASSERT_THAT(status == 1);
    status=PowerOfTwo(1);
    ASSERT_THAT(status == 1);
    status=PowerOfTwo(3);
    ASSERT_THAT(status == 0);
    status=PowerOfTwo(5);
    ASSERT_THAT(status == 0);
    status=PowerOfTwo(8);
    ASSERT_THAT(status == 1);
    status=PowerOfTwo(9);
	ASSERT_THAT(status == 0);
END_UNIT

UNIT(Bit_Flip_Two_Bits_Table_Check)
	FlipTwoBitTable(64,1,4);
END_UNIT

UNIT(Bit_Flip_All_Bits_Check)
	FlipAllBits(64,1,4);
END_UNIT

UNIT(Bit_Flip_Two_Bits_Check)
	FlipTwoBits(64,1,4);
END_UNIT

UNIT(Flip_One_bit_check)
	FlipOneBit(64,1);
END_UNIT

UNIT(Bit_Flip_One_Bit_Table_Check)
	FlipOneBitTable(64,1);
END_UNIT


UNIT(Bit_Add_Two_Numbers_Check)
	int i,r;
	srand((unsigned int)time(NULL));
    for(i=0;i<100;i++)
    {
       	r=rand()%100;
       	ASSERT_THAT(Add(r,r) == r*2);
    }	
END_UNIT


UNIT(Bit_Rotate_Check)
	Rotate(64, 3);

END_UNIT

UNIT(Bit_Single_Time_Check)
	int n;
	int arr[] = {3, 3, 2, 3, 1, 2, 4, 4}; 
    n = sizeof(arr) / sizeof(arr[0]); 
    ASSERT_THAT(getSingle(arr, n)  == 1);        

END_UNIT

TEST_SUITE(BIT_LIST)

	TEST(Bit_Flip_One_Bit_Check)
	TEST(Bit_Flip_Two_Bit_Check)
	TEST(Bit_Multiply_By_TreeHalf_Check)
	TEST(Bit_Print_Check)
	TEST(Bit_Power_of_two_Table_Check)
	TEST(Bit_Power_of_two_Check)
	TEST(Bit_Flip_All_Bits_Check)
	TEST(Bit_Add_Two_Numbers_Check)
	TEST(Bit_Flip_Two_Bits_Table_Check)
	TEST(Bit_Flip_Two_Bits_Check)
	TEST(Flip_One_bit_check)
	TEST(Bit_Flip_One_Bit_Table_Check)
	TEST(Bit_Rotate_Check)
	TEST(Bit_Single_Time_Check)
END_SUITE
