/*
Rev: Liran Tzunam
Dev: Leonid Golovko
status: finished
date: 05/08/23
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <iostream>

#include "shapes.hpp"
using namespace ilrd;





int main()
{
    
    Line a(3);
    Circle b(5);
    Square c(7);
    Rectangle d(2);
    a.Move();
    a.Draw();
    b.Move();
    b.Draw();
    c.Move();
    c.Draw();
    d.Move();
    d.Draw();
    return 0;
}


