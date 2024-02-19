#include <stdio.h>
#include <stdlib.h>

#define RET_ADDR  (*(size_t *)((char *)rbp + sizeof(size_t)))

size_t ret = 99;


void jumpto(void)
{
    register long rbp __asm__ ("rbp");
    printf("jumpto, return address value = 0x%lx\n", RET_ADDR);
    RET_ADDR  = ret;
}

void callee(void)
{
    register long rbp __asm__ ("rbp");
    ret = RET_ADDR;
    printf("callee, return address value = 0x%lx\n", RET_ADDR);
    RET_ADDR = (size_t)jumpto;
}

void caller(void)
{
    register long rbp __asm__ ("rbp");
    size_t saved = RET_ADDR;
    printf("caller, return address value = 0x%lx\n", RET_ADDR);
    callee();
    RET_ADDR = saved;
}

int main(void)
{
    caller();
    printf("DONE\n");
    return (0);
}
