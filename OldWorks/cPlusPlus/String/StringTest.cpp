
#include <stdio.h>
#include <ctype.h>
#include "StringT.h"
#include "mu_test.h"

UNIT(String_Total_test)
	String_t var;
    const char arr[]="Hello World";
    var.setString(arr);
    ASSERT_THAT(var.Length() == 11);

END_UNIT

UNIT(String_strcmp_test)
	String_t var;
    const char arr[]="Hello";
    var.setString(arr);
    const char arr1[]="Hello";
    const char arr2[]="Hella";
    const char arr3[]="Hellz";
    ASSERT_THAT(var.Compare(arr1) == 0);
    ASSERT_THAT(var.Compare(arr2) == 1);
    ASSERT_THAT(var.Compare(arr3) == 2);
END_UNIT
UNIT(String_upper_test)
	String_t var;
    const char arr[]="Hello";
    const char arr2[]="HELLO";
    const char arr3[]="LEON";
    var.setString(arr);
    var.Upper();
    ASSERT_THAT(strcmp(arr2,var.getString()) == 0);
    const char arr1[]="leon";
    var.setString(arr1);
    var.Upper();
    ASSERT_THAT(strcmp(arr3,var.getString()) == 0);
END_UNIT

UNIT(String_lower_test)
	String_t var;
    const char arr[]="HeLLo";
    const char arr2[]="hello";
    const char arr3[]="leon";
    var.setString(arr);
    var.Lower();
    ASSERT_THAT(strcmp(arr2,var.getString()) == 0);
    const char arr1[]="LEON";
    var.setString(arr1);
    var.Lower();
    ASSERT_THAT(strcmp(arr3,var.getString()) == 0);
END_UNIT

UNIT(String_prepend_test)
	String_t var;
    const char arr[]="HeLLo";
    var.setString(arr);
    const char arr1[]="H65";
    var.Prepend(arr1);
    var.Print();
    var.Prepend("Try");
    var.Print();
END_UNIT



UNIT(String_Operator_test)
	String_t var;
    const char arr[]="HeLLo";
    var.setString(arr);
    const char arr1[]="H65";
    var.operator+=(arr1);
    var.Print();
    var.operator+=("Try");
    var.Print();
END_UNIT


UNIT(String_Operators_test)
	String_t var;
    const char arr[]="Hello";
    var.setString(arr);
    String_t var1;
    const char arr1[]="Hella";
    var1.setString(arr1);
    String_t var2;
    const char arr2[]="Hellz";
    var2.setString(arr2);
    String_t var3;
    const char arr3[]="Hello";
    var3.setString(arr3);
    ASSERT_THAT(var.operator<(var2) == true);
    ASSERT_THAT(var.operator<(var1) == false);
    ASSERT_THAT(var.operator>(var1) == true);
    ASSERT_THAT(var.operator>(var2) == false);
    ASSERT_THAT(var.operator<=(var2) == true);
    ASSERT_THAT(var.operator<=(var3) == true);
    ASSERT_THAT(var.operator<=(var1) == false);
    ASSERT_THAT(var.operator>=(var1) == true);
    ASSERT_THAT(var.operator>=(var3) == true);
    ASSERT_THAT(var.operator>=(var2) == false);
    ASSERT_THAT(var.operator==(var3) == true);
    ASSERT_THAT(var.operator==(var1) == false);
    ASSERT_THAT(var.operator!=(var3) == false);
    ASSERT_THAT(var.operator!=(var1) == true);
END_UNIT

UNIT(String_Containes_test)
	String_t var;
    const char arr[]="Hello";
    var.setString(arr);
    String_t var2;
    const char arr1[]="He";
    var2.setString(arr1);
    ASSERT_THAT(var.Containes(var2) == 1);

END_UNIT

UNIT(String_Boundary_test)
	String_t var;
    const char arr[]="Hello";
     var.setString(arr);
    ASSERT_THAT(var.operator[](1) == 'e');
    ASSERT_THAT(var.operator[](3) == 'l');
    ASSERT_THAT(var.operator[](60) == '\0');
END_UNIT


UNIT(String_FindFirst_test)
	String_t var;
    const char arr[]="Hello World";
    var.setString(arr);
    ASSERT_THAT(var.FindFirst('o') == 4);
    ASSERT_THAT(var.FindFirst('l') == 2);
    
END_UNIT

UNIT(String_FindLast_test)
	String_t var;
    const char arr[]="Hello World";
    var.setString(arr);
    ASSERT_THAT(var.FindLast('o') == 7);
    ASSERT_THAT(var.FindLast('l') == 9);
    
END_UNIT

UNIT(String_OperatorPrint_test)
	String_t var;
    const char arr[]="Hello World";
    var.setString(arr);
    cout << var << endl;
    
END_UNIT

UNIT(String_OperatorGet_test)
	String_t var;
    cin >> var ;
    cout << var;
    cout << "\n";
END_UNIT

UNIT(String_OperatorCut_test)
	String_t var,var1;
    const char arr[]="Hello World";
    var.setString(arr);
    var1 = var.operator()(3,5);
    cout << var1 << endl;
END_UNIT

UNIT(String_Operatorflag_test)
	String_t var;
    const char arr[]="Hello";
    var.setString(arr);
    String_t var1;
    const char arr1[]="HELLO";
    var1.setString(arr1);
    var.MakeNewCaseSens();
    
    ASSERT_THAT(var.operator<(var1) == false);
    ASSERT_THAT(var.operator>(var1) == false);
    ASSERT_THAT(var.operator<=(var1) == true);
    ASSERT_THAT(var.operator<=(var1) == true);
    ASSERT_THAT(var.operator==(var1) == true);
    ASSERT_THAT(var.operator!=(var1) == false);
  
END_UNIT

TEST_SUITE(TEST_STRING)

	TEST(String_Total_test)
	TEST(String_strcmp_test)
    TEST(String_upper_test)
    TEST(String_lower_test)
    TEST(String_prepend_test)
    TEST(String_Operator_test)
    TEST(String_Operators_test)
    TEST(String_Containes_test)
    TEST(String_Boundary_test)
    TEST(String_FindFirst_test)
    TEST(String_FindLast_test)
    TEST(String_OperatorPrint_test)
    TEST(String_OperatorGet_test)
    TEST(String_OperatorCut_test)
    TEST(String_Operatorflag_test)
END_SUITE