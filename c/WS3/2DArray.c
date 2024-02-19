/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date:23/03/23
*/

#include <stdio.h> /*printf*/

void Count(int arr[][3], int sum[], size_t rows, size_t columns);
 
int main()
{
    	int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    	int sum[3] = { 0 };
    Count(arr, sum, 3, 3);
    if( 6 == sum[0] && 15 == sum[1] && 24 == sum[2])
    {
    
    	printf("Test Count passed\n");
    }
    return 0;
}




 void Count(int arr[][3], int sum[], size_t rows, size_t columns)
 {
 	size_t i = 0, j = 0;
 	
 	
 	for(i = 0;i < rows; ++i)
 	{
 		for(j = 0; j < columns; ++j)
 		{
 			sum[i] += arr[i][j];
 		}
 	}
 }
