#ifndef __MAX__
#define __MAX__

#include <iostream>
#include <iosfwd>

#define TEMPLATE_MAX(T) \
    T Max_##T(T a, T b) { \
        return a > b ? a : b; \
    }

#endif

TEMPLATE_MAX(int)
TEMPLATE_MAX(double)

int main() {
    int a = Max_int(5, 6);
    double b = Max_double(5.5, 6.5); // Use double arguments
    return 0;
}