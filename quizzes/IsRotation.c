#include <stdio.h> /*printf*/
#include <string.h> /*strlen*/


int IsRotation(char *str1,char *str2, size_t length1, size_t length2);

int main()
{
	char str2[] = "Hello World";
	char str1[] = "WorldH";
	int result = IsRotation(str1, str2, strlen(str1), strlen(str2));
	if(1 == result)
	{
		printf("Is rotation\n");
	}
	if(0 == result)
	{
		printf("Is Not rotation\n");
	}
	return 0;
}

int IsRotation(char *str1, char *str2, size_t length1, size_t length2)
{
	char *begining1 = str1;
	char *begining2 = str2;
	char *last_location = NULL;
	size_t counter = 0;
	size_t counter_equal = 0;
	if(length1 > length2)
	{
		return 0;
	}
	while(counter < length2)
	{
		
		if(*str1 == *str2)
		{
			counter = 0;
			last_location = str2;
			while(counter_equal != length1 - 1)
			{
				if('\0' == *str2)
				{
					str2 = begining2;
				}
				if(*str1 == *str2)
				{
					++counter_equal;
					++str1;
					++str2;
				}
				if(*str1 != *str2)
				{
					str2 = last_location;
					str1 = begining1;
					break;
				}
			
			}
			++counter_equal;
		
		}
		++str2;
		++counter;
	}
	if(counter_equal == length1)
	{
		return 1;
	}
	return 0;
}
