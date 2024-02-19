void Foo()
{
    int *ip = new int;
    Bar(ip);
    Fishi();
    Fifi(ip);
    Dodo();
    delete ip;
}


/*first fix*/
void Foo() {
    int *ip = nullptr;
    try {
        ip = new int;
        Bar(ip);
        Fishi();
        Fifi(ip);
        Dodo();
    } catch (...) {
        // Handle exceptions and ensure proper cleanup
        delete ip;
        throw; // Re-throw the exception
    }
    delete ip; // Cleanup after successful execution
}


/*secomnd fix smart pointers*/
#include <iostream>
#include <memory>

void Foo() {
    std::unique_ptr<int> ip(new int);
    Bar(ip.get());
    Fishi();
    Fifi(ip.get());
    Dodo();
}