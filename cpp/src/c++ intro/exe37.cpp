#include <iostream>
#include <stdexcept>
#include <typeinfo>
class X {
public:
    X(int a) : m_a(a) {}
    ~X() {
        std::cerr << "Hallo" << std::endl;
    }

private:
    int m_a;
};

int Foo(int x) throw(std::bad_alloc) {
    if (x == 42) {
        throw std::runtime_error("Exception from Foo"); // Throws a different exception type
    }
    return x * 2;
}

void Bar()
{
    Foo(42);
    throw std::bad_cast();
    
}

void Fishi() {
    X x1(42);
    try {
        Bar();
    } catch (const std::exception& e) {
        std::cerr << "Caught exception in Fishi: " << e.what() << std::endl;
    }
}

int main() {
    try {
        Fishi();
    } catch (...) {
        std::cerr << "Caught an exception in main." << std::endl;
    }
    return 0;
}
