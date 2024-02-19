

class B
{
public:
    //....
    static void Bla();

};

void B::Bla()
{

}

int main()
{
    //...
    B::Bla();

    //....
    B b;
    b.Bla();
}