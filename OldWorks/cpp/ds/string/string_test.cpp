#include "mu_test.h"
#include "string.hpp"




UNIT(String_Initialize)
	experis::String s1("abc");
    ASSERT_THAT(strcmp(s1.AsCString(),"abc") == 0);
    const experis::String s2("defgh");
    ASSERT_THAT(strcmp(s2.AsCString() , "defgh") == 0);
    experis::String s3(s1);
    ASSERT_THAT(strcmp(s3.AsCString() , s1.AsCString()) == 0);
    experis::String s4;
    s1[2] = 'e';
    ASSERT_THAT(strcmp(s1.AsCString(),"abe") == 0);
    s3 = "hello";
    ASSERT_THAT(strcmp(s3.AsCString() , "hello") == 0);
END_UNIT
 
UNIT(String_equal)
	experis::String s1("abc");
    const experis::String s2("defgh");
    experis::String s3(s1);
    s3 = s2;
    ASSERT_THAT(strcmp(s3.AsCString() , s2.AsCString()) == 0);
    s1 = s1;

END_UNIT

UNIT(String_print)
	experis::String s1("abc");
    const experis::String s2("defgh");
    std::cout << s1[1];
    std::cout << s2[1];
    std::cout << s2;
END_UNIT

UNIT(String_preatorShave)
	experis::String s1("abc");
    const experis::String s2("defgh");
    s1 == s2;
    s2 == "abc";
    "abc" == s2;
END_UNIT

TEST_SUITE(TEST_String)

	TEST(String_Initialize)
	TEST(String_equal)
	TEST(String_print)
    TEST(String_preatorShave)
END_SUITE