#ifndef __MAX__
#define __MAX__

#include <iostream>
#include <iosfwd>
 
 #define TEMPLATE_MAX(T)             
    T Max_##T(T a,T b)            
    {                           
        return a > b ? a : b;   
    }


#endif