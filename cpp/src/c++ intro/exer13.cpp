
#include <iostream>
using namespace std;

namespace useless
{
unsigned int g_wasteful[400];
extern int g_notthere;
void Foo() {cout << "Im here useless";}

namespace wasteoftyme
{
    void Foo() {cout << "Im here wasteoftyme";}
}//namesepace wasteoftyme
}//namespace usefull

namespace stupid
{
	void Foo() {cout << "Im here stupid";}
	void Bar() {}
	void DoNothing(unsigned int) {}
}//namespace stupid

namespace useless
{
	void DoNothing(int) {}
}//namespace useles

using namespace useless;


void DoStuff()
{
	stupid::Bar();
	Foo();
	using stupid::Foo;
	Foo();
	DoNothing(g_wasteful[3] + 1);
}

void Foo() {cout << "Im here";}

using namespace stupid;

namespace comeon = useless::wasteoftyme;

void DoMoreStuff()
{
	comeon::Foo();
	::Foo(); //try uncommenting this line, solve the error
	Bar(); //whe doesn't this line create an error?
	DoNothing(g_wasteful[3] + 1);
}

namespace useless
{
void DoUselessStuff()
{
	DoNothing(g_wasteful[3] + 1);
}
}//namespace useless


int main()
{
	/* useless::Foo();
	wasteoftyme::Foo();
	::Foo(); */
}