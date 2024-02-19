#include <stdio.h>

void Bla()
{
    printf("Non Static method Bla() called.\n");
}

struct B 
{
   void (*B_Bla) (void);
};


void B_Bla() 
{
   
    printf("Static method Bla() called.\n");
}

int main() {
    
    B_Bla();

    
    struct B b;
    b.B_Bla = Bla;
    
    b.B_Bla;

    return 0;
}