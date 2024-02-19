/*
Rev: 
Dev: Leonid Golovko
status: finished
date:24/03/23
*/


#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <string.h> /*strcmp*/
#define FINISH 1
#define SIZE 200
#define AMOUNT 5
#define UNUSED(X) (void)(X)

void OpenAndClose(char * file_name);
void PrintFile(FILE * fp);

typedef enum File_Result 
{
	FILE_SUCCESS = 0,
	FILE_NULL_ERROR,
	FILE_FOPEN_NULL_ERROR,
	FILE_FCLOSE_ERROR,
	FILE_COMPARE_FAIL,
	FILE_COMPARE_SUCCESS,
	FILE_REMOVE,
	FILE_BEGIN_PRINT,
	COUNT_LINES,
	FILE_EXIT
} File_Result;

typedef int (*operating_t)(char *, char *);
typedef int (*comparison_t)(char *, char *);


typedef struct file_t
{
	char arr[SIZE];
	comparison_t comparison;
	operating_t operating;
	

} file;

int StartCheck(char *line, char *file_name);
int PrintCompare(char * line, char * compare);
int CountCompare(char * line, char * compare);
int BeginingCompare(char * line, char * compare);
int RemoveCompare(char * line, char * compare);
int ExitCompare(char * line, char * compare);
int Print(char * line, char* file_name);
int PrintToBegining(char * line, char* file_name);
int Exit(char * line, char* file_name);
int Remove(char * line, char* file_name);
int CountLines(char *line, char* file_name);
int EnterLine(char *file_name);
int PrintToBegining(char * line, char* file_name);
int StructStringInit(char *line, char *file_name);
int StructRun(char *line, char *file_name, file arr[AMOUNT]);
int StructInit(char *line, file* chain);




int main(int args, char *argv[])
{

	File_Result status = FILE_SUCCESS;
	if(args != 2)
	{
		printf("Please enter a file name\n");
	}
	
	
	while(FILE_SUCCESS == status)
	{
		status = EnterLine(argv[1]);
	}
	return 0;
}





int EnterLine(char *file_name)
{
	static size_t counter = 0;
	File_Result status = FILE_SUCCESS;
	char *str = (char *)malloc(sizeof(char) * SIZE);
	file *chain;
	if(0 == counter)
	{
		chain = (file *)malloc(sizeof(file) * AMOUNT);
	}
	printf("Please type a line up to 200 characters: ");
	fgets(str, SIZE, stdin);
	if(0 == counter)
	{
		status = StructInit(str, chain);
		++counter;
	}
	if(FILE_SUCCESS == status)
	{
		status = StructRun(str, file_name, chain);
	}
	free(str);
	if(FILE_SUCCESS != status)
	{
		free(chain);
	}
	return status;
}

int StructInit(char *line, file* chain)
{
	File_Result status = FILE_SUCCESS;
	
	
	strcpy(chain[0].arr ,"-remove\n");
	chain[0].comparison = RemoveCompare;
	chain[0].operating = Remove;
	
	
	strcpy(chain[1].arr, "-count\n");
	chain[1].comparison = CountCompare;
	chain[1].operating = CountLines;
	
	
	strcpy(chain[2].arr, "-exit\n");
	chain[2].comparison = ExitCompare;
	chain[2].operating = Exit;
	
	
	strcpy(chain[3].arr, line);
	chain[3].comparison = BeginingCompare;
	chain[3].operating = PrintToBegining;
	
	
	strcpy(chain[4].arr, line);
	chain[4].comparison = PrintCompare;
	chain[4].operating = Print;
	return status;
}

int StructRun(char *line, char *file_name, file arr[AMOUNT])
{
	File_Result status = FILE_SUCCESS;
	size_t i = 0;
	while(i < AMOUNT)
	{
		status = arr[i].comparison(line, arr[i].arr);
		if(FILE_COMPARE_SUCCESS == status)
		{
			status = arr[i].operating(line, file_name);
			if(FILE_BEGIN_PRINT == status || COUNT_LINES == status || FILE_REMOVE == status)
			{
				status = FILE_SUCCESS;
				break;
				
			}
			if(FILE_SUCCESS != status)
			{
				return status;
				
			}
			
		}
		i++;
	}
	return status;

}

int CountLines(char *line, char* file_name)
{
	size_t countlines = 0;
	char str[SIZE];
	FILE *fp;	
	UNUSED(line);
	fp = fopen(file_name, "r");
	if(NULL == fp)
	{
		printf("The number of lines is 0\n");
		return COUNT_LINES;
	}
	fseek(fp, 0, SEEK_SET);
	do
	{		
		if(NULL != fgets(str,SIZE,fp)) 
		{
			++countlines;
		}	
	}while(!feof(fp));
	printf("The number of lines is %ld\n", countlines);
	if(EOF == fclose(fp))
	{
		return FILE_FCLOSE_ERROR;
	}
	return COUNT_LINES;
}

int Remove(char * line, char* file_name)
{
	UNUSED(line);
	if(0 != remove(file_name))
	{
		return FILE_NULL_ERROR;
	
	}
	return FILE_REMOVE;
}


int Exit(char * line, char* file_name)
{
	UNUSED(line);
	UNUSED(file_name);
	return FILE_EXIT;
}

int PrintToBegining(char * line, char* file_name)
{
	FILE *fp;
	FILE *other;
	char str[SIZE];
	char temp_name[8] = "try.txt";
	fp = fopen(file_name, "a+");
	if(NULL == fp)
	{
		return FILE_FOPEN_NULL_ERROR;
	}
	other = fopen(temp_name, "w");
	if(NULL == other)
	{
		return FILE_FOPEN_NULL_ERROR;
	}
	++line;
	fprintf(other, "%s", line);  /* remove <*/
	
	while(!feof(fp))
	{
		if(NULL == fgets(str,SIZE,fp))
		{
			break;
		}
		fprintf(other, "%s", str);
	}
	
	
	if(EOF == fclose(fp))
	{
		return FILE_FCLOSE_ERROR;
	}
	if(EOF == fclose(other))
	{
		return FILE_FCLOSE_ERROR;
	}
	
	if(0 != remove(file_name))
	{
		return FILE_NULL_ERROR;
	}
	if(0 != rename(temp_name, file_name))
	{
		return FILE_NULL_ERROR;
	
	}
	return FILE_BEGIN_PRINT;
}

int Print(char * line, char* file_name)
{
	FILE *fp = fopen(file_name, "a");
	if(NULL == fp)
	{
		return FILE_FOPEN_NULL_ERROR;
	}
	fprintf(fp, "%s", line);
	if(EOF == fclose(fp))
	{
		return FILE_FCLOSE_ERROR;
	}
	return FILE_SUCCESS;
}

int ExitCompare(char * line, char * compare)
{
	if(NULL == line)
	{
		return FILE_NULL_ERROR;
	}
	if(0 == strcmp(line, compare))
	{
		return FILE_COMPARE_SUCCESS;	
	}
	return FILE_COMPARE_FAIL;
}


int RemoveCompare(char * line, char * compare)
{
	if(NULL == line)
	{
		return FILE_NULL_ERROR;
	}
	
	if(0 == strcmp(line, compare))
	{
		printf("I got here\n");
		return FILE_COMPARE_SUCCESS;	
	}
	return FILE_COMPARE_FAIL;
}

int BeginingCompare(char * line, char * compare)
{
	UNUSED(compare);
	if(NULL == line)
	{
		return FILE_NULL_ERROR;
	}
	if('<' == *line)
	{	
		
		return FILE_COMPARE_SUCCESS;
	}
	return FILE_COMPARE_FAIL;
}

int CountCompare(char * line, char * compare)
{
	if(NULL == line)
	{
		return FILE_NULL_ERROR;
	}
	if(0 == strcmp(line, compare))
	{
		return FILE_COMPARE_SUCCESS;	
	}
	return FILE_COMPARE_FAIL;
	
}

int PrintCompare(char * line, char * compare)
{
	UNUSED(compare);
	if(NULL == line)
	{
		return FILE_NULL_ERROR;
	}
	return FILE_COMPARE_SUCCESS;	
}



