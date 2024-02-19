#include "parser.h"
using namespace std;



/* int main()
{
	Parser par("name.txt");
	
	return 0;
}  */

int main(int argc, char* argv[])
{
	Parser p;
	for(int i = 1 ; i < argc; ++i)
	{
		p.OpenFile(argv[i]);
	}

	return 0;
} 