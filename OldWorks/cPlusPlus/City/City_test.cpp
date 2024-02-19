#include "City.h"
#include "Street.h"
#include "Building.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	
	Building_t<int> buil2;
    
    Street_t<string,int> str3("Bar Yohai");
    Street_t<string,int> str2("Gilat");
    City_t<string,string,int> city("Beer-Sheva");
    Building_t<int> bil(1);
    Building_t<int> bil1(2);
    Building_t<int> bil2(3);
    Building_t<int> bil3(4);
    str3.AddBuilding2Street(bil); 
    str3.AddBuilding2Street(bil1); 
    str3.AddBuilding2Street(bil2); 
    str3.AddBuilding2Street(bil3); 
    str2.AddBuilding2Street(bil1); 
    str2.AddBuilding2Street(bil3); 
    str2.AddBuilding2Street(bil); 
    str2.AddBuilding2Street(bil3); 

    city.AddStreet(str2);
    city.AddStreet(str3);
    


    try
    {
		buil2 = str2.GetBuilding(8);
	}
    catch(TException_t<int> _exception)
    {
		cout << "The file selected is: " << _exception.GetFile() << endl;
		cout << "The line number is: " << _exception.GetLine() << endl;
		cout << "The Exception in this case is: " << _exception.GetException() << endl;
        cout << "error type: " << _exception.GetText() << endl;
	}
       
	

    

	return 0;
}