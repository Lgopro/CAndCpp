

#include <iostream>
#include <string>
#include <typeinfo>
#include "VirtIO_t.h"
#include "asciiIO_t.h"
#include "binIO_t.h"

template <class T>
void Handler(const TException_t<T>& _ex)
{
		cout << _ex.GetText() << "Exception: " << _ex.GetException() << endl;
		cout << "File: " << _ex.GetFile() << endl;
		cout << "Line: " << _ex.GetLine() << endl;
		cout << "Wrong input" << endl;
}




void Test(VirtIO_t& _file)
{
    int option,condition = 1, position, write, read;
    char fileName[50],mode[50];
    bool status;
    int read_i, write_i;
    char read_c, write_c;
    short read_s, write_s;
    long read_l, write_l;
    double read_d, write_d;
    

    

    while(condition)
    {
        cout << "Choose option: " << endl;
        cout << "1: Open file  " << endl;
        cout << "2: Close file  " << endl;
        cout << "3: Set position  " << endl;
        cout << "4: Get position  " << endl;
        cout << "5: Write to file  " << endl;
        cout << "6: Read from file  " << endl;
        cout << "7: Get file length  " << endl;
        cout << "8: Get file mode  " << endl;
        cout << "9: Get file name  " << endl;
        cout << "10: Binary write  " << endl;
        cout << "11: Binary read  " << endl;
        cout << "Any another number - stop " << endl ;
        cin >>  option;
        switch (option) 
        {
            case 1:
                cout << "Please enter file name: " << endl;
                cin >>  fileName;
                cout << "Please enter file mode: " << endl;
                cin >>  mode;
                status = _file.OpenFile(fileName, mode);
                if(status == true)
                {
                    cout << "The file opened successfuly: " << endl;
                }
                else
                {
                    cout << "Cannot open file! Please try again.. " << endl;
                }
                break;
            case 2:
                status = _file.CloseFile();
                if(status == true)
                {
                    cout << "The file closed successfuly: " << endl;
                }
                else
                {
                    cout << "Cannot close file! Please try again.. " << endl;
                }
                break;
            case 3:
                cout << "Please enter the position you want to set: " << endl;
                cin >>  position;
                status = _file.SetPosition(position);
                if(status == true)
                {
                    cout << "File position now is: " << position <<endl;
                }
                else
                {
                    cout << "File position was not set because file not exist or position is begger then file length: " <<endl;
                }
                
                break;
            case 4:
                cout << "1: The current file position is: "<< _file.GetPosition() << endl;
                break;

            case 5:
                cout << "1: Please enter what you want to write: "<< endl;    
                cout << "1: char " << endl;
				cout << "2: short " << endl;
				cout << "3: int " << endl;
				cout << "4: long " << endl;
				cout << "5: double " << endl;
				cout << "6: Binary: write buffer " << endl;
                cin >>  write;
                try
                {
                    switch (write) 
                    {
                    case 1:
                        cout << "Please enter the char " << endl; 
                        cin >> write_c;
                        _file << write_c << ' ';
                        break;
                    case 2:
                        cout << "Please enter the short " << endl; 
                        cin >> write_s;
                        _file << write_s << ' ';
                        break;
                    case 3:
                        cout << "Please enter the int " << endl; 
                        cin >> write_i;
                        _file << write_i<< ' ';

                        break;
                    case 4:
                        cout << "Please enter the long " << endl; 
                        cin >> write_l;
                        _file << write_l << ' ';
                        break;
                    case 5:
                        cout << "Please enter the double " << endl; 
                        cin >> write_d;
                        _file << write_d << ' ';
                        break;
                    default: 
                        break;
                    }
                }
                catch (TException_t<int> ex) { Handler(ex);}
                break;
            case 6:
                cout << "1: Please enter what you want to read: "<< endl;    
                cout << "1: char  " << endl;
				cout << "2: short    " << endl;
				cout << "3: int  " << endl;
				cout << "4: long  " << endl;
				cout << "5: double  " << endl;
				cout << "6: Binary: read buffer  " << endl;
                cin >>  read;
                switch (read) 
                {
                    case 1:
                        _file >> read_c;
                        cout << "The char is: " << read_c <<  endl; 
                        break;
                    case 2:
                        _file >> read_s;
                        cout << "The short is: " << read_s <<  endl; 
                        break;
                    case 3:
                        _file >> read_i;
                        cout << "The int is: " << read_i <<  endl; 
                        break;
                    case 4:
                        _file >> read_l;
                        cout << "The long is: " << read_l <<  endl; 
                        break;
                    case 5:
                        _file >> read_d;
                        cout << "The double is: " << read_d <<  endl; 
                        break;
                    default: 
                        break;
                }
                break;
            case 7:
                cout << "The current file length is: "<< _file.GetLength() << endl;
                break;
            case 8:
                cout << "The current file mode is: "<< _file.GetMode() << endl;
                break;
            case 9:
                cout << "The current file name is: "<< _file.GetName() << endl;
                break;
            case 10:
                {
                    BinIO_t* binary;
                    if ((binary = dynamic_cast<BinIO_t*>(&_file)) != 0)
                    {
                        cout << "Please enter the int " << endl; 
                        cin >> write_i;
                        *binary << &write_i, sizeof(int);
                    }
                    
                }
                break;
            case 11:
                {
                    BinIO_t* binary;
                    try
                    {
                        if ((binary = dynamic_cast<BinIO_t*>(&_file)) != 0)
                        {
                            *binary >> &read_i, sizeof(int);
                            cout << "The int is: " << read_i <<  endl;
                            
                        }
                    }
                    catch (TException_t<int> ex) { Handler(ex);}
                    
                }
                break;
            default: 
                condition = 0;
                break;
        }
    }

}
int main()
{
	int option,condition = 1;
	AsciiIO_t	ascii;
	BinIO_t		binary;
    while(condition)
    {
        cout << "Choose option: " << endl;
        cout << "1: Ascii test  " << endl;
        cout << "2: Binary test  " << endl;
        cout << "Any another number - stop " << endl ;
        cin >>  option;
        switch (option) 
        {
            case 1:
                Test(ascii);
                break;
            case 2:
                Test(binary);
                break;
            default: 
                condition = 0;
                break;
        }
    }
	return 0;
}



