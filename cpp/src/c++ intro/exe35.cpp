#include <iostream>
#include <exception>
#include <cstdlib>

void unexpectedHandler() {
    std::cerr << "Unexpected exception encountered." << std::endl;
    std::terminate();
}

void functionThrowingUnexpected() throw() {
    throw "Unexpected exception";
}

int main() {
    std::set_unexpected(unexpectedHandler);

    try {
        functionThrowingUnexpected();
    } catch (...) {
        std::cout << "Caught an unexpected exception." << std::endl;
        std::unexpected(); // Handle the unexpected exception
    }

    return 0;
}