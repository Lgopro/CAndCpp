
#include <iostream>
#include "Bus.h"
#include "Private.h"


using namespace std;



int main()
{
	int cont = 1; // trigger to stop loop
	
	/* char input[128]; */
	Private_t priv1, priv2; 
	unsigned int option;
	Bus_t bus1, bus2;
	

	while (cont)
	{
		cout << "Choose option: " << endl;
		cout << "1: Create Bus  " << endl;
		cout << "2: Create private car    " << endl;
		cout << "3: Compare bus and car " << endl;
		cout << "4: Compare two car names " << endl;
		cout << "5: Compare bus and car " << endl;
		cout << "6: Compare bus and car " << endl;
		cout << "Any another number - exit " << endl;

		cin >> option;
		switch (option)
		{
		case 1:

		case 2:

		case 3:

		default:
			cont = 0;
			break;
		}
	}

	return 0;
}
