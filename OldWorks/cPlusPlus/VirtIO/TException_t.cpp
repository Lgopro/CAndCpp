#include "TException_t.h"

int main()
{
	try
    {
		throw TException_t<int>(10, __FILE__, __LINE__, "error");
	}
    catch(TException_t<int> _exception)
    {
		cout << "The file selected is: " << _exception.GetFile() << endl;
		cout << "The line number is: " << _exception.GetLine() << endl;
		cout << "The Exception is: " << _exception.GetException() << endl;
        cout << "" << _exception.GetText() << endl;
	}

	return 0;
}