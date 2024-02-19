#include <iostream>

class Car {
public:
    Car(int &num):number(num)
    {
    }
    void printMake() 
    {
        std::cout << "Make: " << number << std::endl;
    }

private:
    int& number;
};

int main() 
{
    return 0;
}