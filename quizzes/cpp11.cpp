

#include <iostream>
#include <thread>


void Testing(int value)
{
    ([&]{std::cout << "The int value is: " << value << std::endl; })();
}

void Test(int number1, int number2)
{
    auto add = [](int number1, int number2) -> int
    {
        return number1 + number2;
    };

    std::cout<< "The sum of " << number1 << " and " << number2 << " is: " << add(number1, number2) << std::endl;

}

int main()
{
    int number = 5;
    int number2 = 7;
    std::thread t1(Testing, number);
    std::thread t2(Test, number, number2);

    t1.join();
    t2.join();



    std::thread t3([&]{
        std::cout<< "Im thread3 mf" << std::endl;
    });
    t3.join();
    return 0;
}