union exe3
{
    int GetA();
    int a;
    int b;
};


class a
{
    public:
    int x;
    int y;

};

exe3 e = {1};

union exe3 : public a
{
    int a;
    int b;
};