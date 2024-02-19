

typedef struct Base
{
    int x;
    int y;
}Base_t;

struct Derived
{
    Base_t base;
    int z;
};