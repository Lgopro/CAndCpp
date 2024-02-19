#include "tContainer.h"
using namespace std;

template <class T>
void Handler(const TException_t<T>& _ex)
{
		cout << _ex.GetText() << "Exception: " << _ex.GetException() << endl;
		cout << "File: " << _ex.GetFile() << endl;
		cout << "Line: " << _ex.GetLine() << endl;
		cout << "Wrong input" << endl;
}

template <class T, class Container>
void Test(tContainer_t<T, Container>& _cont)
{
	int 	condition = 1,option, num;			
	int*	get;

	while (condition)
	{
		cout << "Choose option: " << endl;
		cout << "1: Check if container is empty  " << endl;
		cout << "2: Get number of elements    " << endl;
		cout << "3: Insert new element  " << endl;
		cout << "4: Get the value first element  " << endl;
		cout << "5: Get the value of last element" << endl;
		cout << "6: Find element  " << endl;
		cout << "7: operator[]" << endl;
		cout << "8: Remove element  " << endl;
		cout << "9: Remove all elements" << endl;
		cout <<"10: Remove and delete element"<< endl;
		cout << "11: Remove and delete all elements" << endl;
		cout << "Any another number - stop " << endl;

		cin >>  option;
		switch (option)
		{
			case 1:
				if(_cont.IsEmpty())
				{
					cout << "The container is empty" << endl;
				}
				else
				{
					cout << "The container is not empty" << endl;	
				}				
				break;
			case 2:
			
				cout << "The amount of the elements the container has is:" <<_cont.NumOfElements() << endl;
				break;
			
			case 3:
				cout << "Please add a number:" << endl;
				cin >> num;
				_cont.Insert(&num);
				cout << "The number added successfuly" << endl;
				break;
			case 4:

				get = _cont.GetFirst();
				if(get == NULL)
				{
					cout << "The container is empty" << endl;
				}
				else
				{
					cout << "The first element is: " << *get << endl;	
				}				
				break;
			case 5:
				get = _cont.GetLast();
				if(get == NULL)
				{
					cout << "Container is empty" << endl;
				}
				else
				{
					cout << "The last element is: " << *get << endl;	
				}				
				break;
			case 6:
				cout << "please insert integer to find:" << endl;
				cin >> num;
				get = _cont.FindElement(num);
				if(get == NULL)
				{
					cout << "Element not found" << endl;
				}
				else
				{
					cout << "The found element is:" << *get << endl;	
				}				
				break;
			case 7:
				cout << "Please insert index:" << endl;
				cin >> num;
				get = _cont[num];
				if(get == NULL)
				{
					cout << "Element not found" << endl;
				}
				else
				{
					cout << "The element is: " << *get << endl;	
				}				
				break;
			case 8:
				cout << "Please insert element to remove:" << endl;
				cin >> num;
				get = _cont.RemoveElement(num);
				if(get == NULL)
				{
					cout << "Element not found" << endl;
				}
				else
				{
					cout << "The removed element is: " << *get << endl;		
				}			
				break;
			case 9:
				_cont.RemoveAllElements();
				break;
			case 10:
				cout << "Please insert element to remove and delete:" << endl;
				cin >> num;
				try 
				{
					_cont.RemoveAndDeleteElement(num);
					cout << "Element removed successfuly" << endl;	
				}
				catch (TException_t<int> ex) { Handler(ex);}					
				break;
			case 11:
				_cont.RemoveAndDeleteAllElements();
				break;
			default: 
				condition = 0;
				break;
		}		
	}
}


int main()
{
	tContainer_t<int, vector<int*> > m_vec;
	tContainer_t<int, list<int*> > m_list;
	int option,condition = 1;
	while (condition)
	{
		cout << "Choose option: " << endl;
		cout << "1: Test a vector container  " << endl;
		cout << "2: Test a list container   " << endl;
		cout << "Any another number - stop " << endl;

		cin >>  option;
		switch (option) 
		{
			case 1:
				Test(m_vec);
				break;
			case 2:
				Test(m_list);
				break;
			default: 
				condition = 0;
				break;
		}
	}
	
	return 0;
}


