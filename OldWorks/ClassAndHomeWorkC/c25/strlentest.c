#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mu_test.h"
#include "strlen.h"

#define LINE_LENGTH 50
UNIT(StrlenItrtest)
	char const line[LINE_LENGTH]="hello";
	char const linetry[LINE_LENGTH]="hellzhello";
	ASSERT_THAT( StrlenItr(line) == 5);
	ASSERT_THAT( StrlenItr(linetry) == 10);
END_UNIT

UNIT(StrlenRectest)
	char const line[LINE_LENGTH]="hello";
	char const linetry[LINE_LENGTH]="hellzhello";
	ASSERT_THAT( StrlenRec(line) == 5);
	ASSERT_THAT( StrlenRec(linetry) == 10);
END_UNIT

UNIT(StrcmpItrtest)
	char const line[LINE_LENGTH]="hello";
	char const line1[LINE_LENGTH]="hello";
	char const line2[LINE_LENGTH]="hella";
	char const line3[LINE_LENGTH]="hellz";
	ASSERT_THAT( StrcmpItr(line,line1) == 0);
	ASSERT_THAT( StrcmpItr(line,line2) > 0);
	ASSERT_THAT( StrcmpItr(line,line3) < 0);
END_UNIT


UNIT(StrcmpRectest)
	char const line[LINE_LENGTH]="hello";
	char line1[LINE_LENGTH]="hello";
	char const line2[LINE_LENGTH]="hella";
	char line3[LINE_LENGTH]="hellz";
	ASSERT_THAT( StrcmpRec(line,line1) == 0);
	ASSERT_THAT( StrcmpRec(line,line2) > 0);
	ASSERT_THAT( StrcmpRec(line,line3) < 0);
END_UNIT

UNIT(StrcpyItrtest)
	char const line[LINE_LENGTH]="hello";
	char line1[LINE_LENGTH]="hellokkk";
	StrcpyItr(line1,line);
	ASSERT_THAT( strcmp(line1,line) == 0);
	

END_UNIT

UNIT(StrcpyRectest)
	char const line[LINE_LENGTH]="hello";
	char line1[LINE_LENGTH]="hellokkk";
	StrcpyRec(line1,line);
	ASSERT_THAT( strcmp(line1,line) == 0);

END_UNIT


UNIT(StrncpyItrtest)
	char const line[LINE_LENGTH]="hello";
	char line1[LINE_LENGTH]="hellokkk";
	StrncpyItr(line1,line,3);
	ASSERT_THAT( strncmp(line1,line,3) == 0);

END_UNIT

UNIT(StrncpyRectest)
	char const line[LINE_LENGTH]="hello";
	char line1[LINE_LENGTH]="hellokkk";
	StrncpyRec(line1,line,3);
	ASSERT_THAT( strncmp(line1,line,3) == 0);

END_UNIT

UNIT(Strcattest)
	char const line[LINE_LENGTH]="hello";
	char line1[LINE_LENGTH]="hellokkk";
	char line2[LINE_LENGTH]="hellokkkhello";
	MyStrcat(line1,line);
	ASSERT_THAT( strcmp(line1,line2) == 0);

END_UNIT
UNIT(StrStrtest)
	char const line[LINE_LENGTH]="hellolll";
	char line1[LINE_LENGTH]="hellokkk";
	MyStrstr(line1,line);
	ASSERT_THAT( MyStrstr(line1,line)== NULL);
	

END_UNIT

TEST_SUITE(StrTest)
	TEST(StrlenItrtest)
	TEST(StrlenRectest)	
	TEST(StrcmpItrtest)
	TEST(StrcmpRectest)
	TEST(StrcpyItrtest)
	TEST(StrcpyRectest)
	TEST(StrncpyItrtest)
	TEST(StrncpyRectest)
	TEST(Strcattest)
	TEST(StrStrtest)
END_SUITE
