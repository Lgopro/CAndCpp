// Creation:  

 String s0; // Creates a string that  points to "ABC"

 String s1("1234"); 

 String s2(s1);  

// operator[]: (reuse the implementation)  

s1[0] = 'r'; 
s2[0] = s1[1];  

// assignment:  

 s1 = "abc"; 
 s2 = s1; 
 s1 = 'A'; // Will change all the characters in s1 to 'A' (in this case to "AAA")  

s0 = s1 = s2; // Not allowed!  

// Implement a function that will always return the number of String objects alive: 

// Use example: 
main()
{  
    String s1("1234");  
    s1 = '@'; // will change s1 to "@@@@"   
    string *s2 = new String;            
    std::cout<< s2->GetInstances(); // will print 2     
    delete s2;  
    std::cout<< String::Getinstances(); // will print 1 
}