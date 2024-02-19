#include <string>
#include <string.h>
#include <iostream>
#include <stddef.h>
#include <cstdio>
#include "Manager.h"
#include "Page.h"
#include "Pool.h"

using namespace std;
void Test(Manager_t *_memory);
int main()
{
    int number = 1; // trigger to stop loop
    unsigned int option;
    Manager_t *manager = NULL;
    while (number)
    {
        cout << "Choose option: " << endl;
        cout << "1: Check Page  " << endl;
        cout << "2: Check Pool  " << endl;
        cout << "Any other number - exit " << endl;

        cin >> option;
        switch (option)
        {
        case 1:
            manager = new Page_t;
            Test(manager);
            break;
        case 2:
            manager = new Pool_t;
            Test(manager);
            break;
        default:
            number = 0;
            break;
        }
    }

    return 0;
}

void Test(Manager_t *_memory)
{
    int option, number = 1;
    Pool_t *poolCheck = dynamic_cast<Pool_t *>(_memory);
    size_t position, toread, result;
    char readText[100], writeText[100];
    while (number)
    {
        cout << "Choose option: " << endl;
        cout << "1: Get Position " << endl;
        cout << "2: Set Position  " << endl;
        cout << "3: Get actual size " << endl;
        cout << "4: Read  " << endl;
        cout << "5: Read from set position " << endl;
        cout << "6: Write  " << endl;
        cout << "7: Write from set position " << endl;
        cout << "Any other number - exit " << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            position = _memory->GetPosition();
            cout << "The position is: " << position << endl;
            break;
        case 2:
            cout << "Please enter the position number you want to set " << endl;
            cin >> position;
            _memory->SetPosition(position);
            if (_memory->GetPosition() >= position)
            {
                cout << "The new position is: " << position << endl;
            }
            else
            {
                cout << "Wrong input! The position is still " << _memory->GetPosition() << endl;
            }
            break;
        case 3:
            cout << "The actual size is: " << _memory->GetActualPosition() << endl;
            break;
        case 4:
            if (poolCheck == 0)
            {
                cout << "Please enter the amount of letters to read" << endl;
                cin >> toread;
                result = _memory->Read(readText, toread);
                if (result == 0)
                {
                    cout << "Wrong input. Please try again.." << endl;
                }
                else
                {
                    readText[toread] = '\0';
                    cout << "The text you read is:" << readText  << endl;
                    readText[0] = '\0';
                }
                
            }
            else
            {
                cout << "Please enter the amount of letters to read" << endl;
                cin >> toread;
                result =_memory->Read(readText, toread);
                if (result == 0)
                {
                    cout << "Wrong input. Please try again.." << endl;
                }
                else
                {
                    readText[toread] = '\0';
                    cout << "The text you read is:" << readText  << endl;
                    readText[0] = '\0';
                }
            }

            break;
        case 5:
            if (poolCheck == 0)
            {
                cout << "Please enter the amount of letters to read" << endl;
                cin >> toread;
                cout << "Please enter the start position" << endl;
                cin >> position;
                result = _memory->Read(readText, toread, position);
                if (result == 0)
                {
                    cout << "Wrong input. Please try again.." << endl;
                }
                else
                {
                    readText[toread] = '\0';
                    cout << "The text you read is:" << readText  << endl;
                    readText[0] = '\0';
                }
            }
            else
            {
                cout << "Please enter the amount of letters to read" << endl;
                cin >> toread;
                cout << "Please enter the start position" << endl;
                cin >> position;
                result = _memory->Read(readText, toread, position);
                if (result == 0)
                {
                    cout << "Wrong input. Please try again.." << endl;
                }
                else
                {
                    readText[toread] = '\0';
                    cout << "The text you read is:" << readText  << endl;
                    readText[0] = '\0';
                }
            }
            break;
        case 6:
            if (poolCheck == 0)
            {
                cout << "Please enter the text you want to write" << endl;
                getchar();
                cin.getline(writeText,100);
                _memory->Write(writeText, strlen(writeText));
            }
            else
            {
                cout << "Please enter the text you want to write" << endl;
                getchar();
                cin.getline(writeText,100);
                _memory->Write(writeText, strlen(writeText));
            }
            break;
        case 7:
            if (poolCheck == 0)
            {
                cout << "Please enter the text you want to write" << endl;
                getchar();
                cin.getline(writeText,100);
                cout << "Please enter the start position" << endl;
                cin >> position;
                _memory->Write(writeText, strlen(writeText), position);
            }
            else
            {
                cout << "Please enter the text you want to write" << endl;
                getchar();
                cin.getline(writeText,100);
                _memory->Write(writeText, strlen(writeText));
                cin >> position;
                _memory->Write(writeText, strlen(writeText), position);
            }
            break;
        default:
            number = 0;
            break;
        }
    }
}
