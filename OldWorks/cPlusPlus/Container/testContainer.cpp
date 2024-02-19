



#include <iostream>
#include "Vector_t.h"
#include "List_h.h"
#include "Container_t.h"

using namespace std;


void Test(container_t<int>* _cont)
{
    int 	cont = 1;	
	int 	option, num, index, num2, num3 , num4, num5, num6, num7,num8;
	int*	get;

	while (cont)
	{
		cout << "Choose option: " << endl;
		cout << "1: Check if container is empty  " << endl;
		cout << "2: Get number of elements    " << endl;
		cout << "3: Insert new element  " << endl;
		cout << "4: Append new element  " << endl;
		cout << "5: Prepend new element" << endl;
        cout << "6: Find if container containes element" << endl;
		cout << "7: Find element  " << endl;
		cout << "8: Remove element  " << endl;
		cout << "9: Remove all elements" << endl;
		cout << "10: Remove and delete element" << endl;
		cout << "11: Remove and delete all elements" << endl;
        cout << "12: Find index" << endl;
		cout << "Any another number - stop " << endl;
        num = 0;
		cin >>  option;
		switch (option)
		{
			case 1:
				if(true == _cont->IsEmpty())
                {
                    cout << "The container is empty!" << endl;
                }
                else
                {
                    cout << "The container is not empty!" << endl;
                }				
				break;
			case 2:
               
                cout << "The container has "<< _cont->Count() << " elements" << endl;
                
				break;
			case 3:
				cout << "Please insert a number to add" << endl;
                cin >>  num;
				if(_cont->Insert(&num) == true)
                {
                    cout << "The number added successfuly" << endl;
                }
				break;
			case 4:
                cout << "Please insert a number to add" << endl;
                cin >>  num2;
                cout << "Please insert a index" << endl;
                cin >>  index;
				if(_cont->Append(index, &num2) == true)
                {
                    cout << "The number added successfuly" << endl;
                }
				else
                {
                    cout << "Wrong index!!" << endl;
                }
                			
				break;
			case 5:

                cout << "Please insert a number to add" << endl;
                cin >>  num3;
                cout << "Please insert a index" << endl;
                cin >>  index;
				if(_cont->Prepend(index, &num3) == true)
                {
                    cout << "The number added successfuly" << endl;
                }
				else
                {
                    cout << "Wrong index!!" << endl;
                }


				break;
			case 6:
				cout << "Please insert a number check" << endl;
                cin >>  num4;	
                if(true == _cont->Contains(num4))
                {
                    cout << "The selected number is in the container!" << endl;
                }
                else
                {
                    cout << "The selected number is not in the container!" << endl;
                }
                
				break;
			case 7:
				cout << "Please insert a number to check" << endl;
                cin >>  num5;
                get = _cont->Find(num5);
                if(get == NULL)
                {
                    cout << "The selected number is not found" << endl;
                    
                }
                else
                {
                    cout << "The selected number found!" << endl;
                }				
				break;
			case 8:
				cout << "Please insert a number to remove" << endl;
                cin >>  num6;
                get = _cont->Remove(num6);
                if(*get == num6)
                {
                    cout << "The selected number removed!" << endl;
                }
                else
                {
                    cout << "The selected number dont exist" << endl;
                }	
				break;
			case 9:
				_cont->RemoveAll();
                cout << "All elements removed" << endl;
				break;
			case 10:
				cout << "Please insert a number to remove and delete" << endl;
                cin >>  num7;
                
                if(_cont->RemoveAndDelete(num7) == true)
                {
                    cout << "The selected number removed and deleted!" << endl;
                }
                else
                {
                    cout << "The selected number dont exist" << endl;
                }	
				break;
			case 11:
				_cont->RemoveAndDeleteAll();
                cout << "All elements removed and deleted" << endl;			
				break;
            case 12:
                {
                    cout << "Please insert a number" << endl;
                    cin >>  num8;
                    if(_cont->Index(num8) != -1)
                    {
                        cout << "The index is: "<< _cont->Index(num8) << endl;
                    }
                    else
                    {
                        cout << "The number not found " << endl;
                    }	
                } 
                break;
			default: 
                cont = 0;
                break;
		}
	}

} 


int main()
{
    container_t <int>* m_select;
	int option,cont = 1;
    while(cont)
    {
        cout << "Choose option: " << endl;
        cout << "1: Test with vector  " << endl;
        cout << "2: Test with list   " << endl;
        cout << "Any another number - stop " << endl;

        cin >>  option;
        switch (option) 
        {
            case 1:
                m_select = new vector_t<int>(20);
                Test(m_select);
                delete m_select;
                break;
            
            case 2:
                m_select = new list_t<int>;
                Test(m_select);
                delete m_select;
                break;
            default: 
                cont = 0;
                break;
        }
    }
	return 0;
}