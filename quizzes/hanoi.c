#include <stdio.h>
#include <assert.h>

void towerOfHanoi(int n, char from_rod, char to_rod,char aux_rod);

int main()
{
    int Number = 3;
  
    towerOfHanoi(Number, 'A', 'C', 'B');
    return 0;
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{

    if (0 == n) 
    {
        return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Disk %d from %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
  
