

#include "calculator.h"

#include <string.h> /*strtod*/
#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <math.h> /*pow*/
#include <stdio.h>


typedef enum VALUE
{
    NUMBER,
    SIGN, 
    SPACE, 
    ERROR = -99
}value_t;

typedef struct ParsingStacks
{
    stack_t *NumStack;
    stack_t *OpStack;
    char last_parenthesis[100];
    size_t amount_of_parenthesis;
}pars_stacks;

typedef int (*parcer_status_t)( void*, size_t*, char **, double *, pars_stacks*);

typedef int (*calculate_status_t)(pars_stacks * ,double *);

typedef int (*push_func_t)(pars_stacks *, void *);


typedef struct calculator_luts
{
	parcer_status_t parcer_stat[14];
	calculate_status_t operating_stat[8];
	push_func_t push_oper_type[4];
}calc_luts;



static int OperationType(char *expression);

static int ParserPlus(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct);

static int ParserMinus(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct);

static int ParserMult(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct);

static int ParserDivide(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct);

static int ParserPow(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct);

static int ParserParentesis(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct);

static int ToCalculate(char *precedence1, char *precedence2);

static int ParserNumber(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct);

static int ParserSpace(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct);

static int ParserERROR(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct);

static int ErrorCalculate(pars_stacks *stacks_struct, double *calculate);

static int PlusCalculate(pars_stacks *stacks_struct, double *calculate);

static int MinusCalculate(pars_stacks *stacks_struct, double *calculate);

static int MultiplyCalculate(pars_stacks *stacks_struct, double *calculate);

static int DivideCalculate(pars_stacks *stacks_struct, double *calculate);

static int PowCalculate(pars_stacks *stacks_struct, double *calculate);

static int ParentesisCalculate(pars_stacks *stacks_struct, double *calculate);

static int PushNumber(pars_stacks *stacks_struct, void *data);

static int PushSign(pars_stacks *stacks_struct, void *data);

static int PushSpace(pars_stacks *stacks_struct, void *data);

static int PushSyncError(pars_stacks *stacks_struct, void *data);

static int UpdateLastParenthesis(char *expression, pars_stacks *stacks_struct);

static int IsBeginParenthesis(char *expression);

static int IsEndParenthesis(char *expression);

static int IsRightEndParenthesis(char expression, pars_stacks *stacks_struct);

static void CalculateOperation(pars_stacks *stacks_struct, calc_luts *luts);

static calc_luts *InitLuts();

static value_t Parcer(char **expression, void *data, size_t *counter, calc_luts *luts, pars_stacks *stacks_struct);

static calculator_status_t Push(pars_stacks *stacks_struct, void *data, value_t status, calc_luts *luts);

static calculator_status_t Calculate(pars_stacks *stacks_struct, calc_luts *luts, char **expression);

static size_t Counter(char *expression);

static void Destroy(pars_stacks * stacks_struct);

static pars_stacks *Create(char *expression);

void GetResult(pars_stacks *stacks_struct,double **result);



static int IsOperation(char *expression);
static int GetPrecedence(char *expression);



calculator_status_t Calculator(const char *expression, double *result)
{
	pars_stacks *stacks_struct = NULL;
	value_t status = SUCCESS;
	calculator_status_t calc_status = SUCCESS;
	void *data = NULL;
	char *runner = (char *)expression;
	size_t counter = 0;
	calc_luts *luts = NULL;
	assert(expression);
	assert(result);
	data = (void *)malloc(sizeof(void *));
	if(NULL == data)
	{
		return MEMORY_ALLOC_ERR;
	}
	luts = InitLuts();
	if(NULL == luts)
	{
		free(data);
		return MEMORY_ALLOC_ERR;
	}
	stacks_struct = Create((char *)expression);
	if(NULL == stacks_struct)
	{
		free(data);
		free(luts);
		return MEMORY_ALLOC_ERR;
	}
	
	while('\0' != *runner)
	{
		status = Parcer(&runner, data, &counter, luts, stacks_struct);
		if(ERROR == status)
		{
			free(data);
			free(luts);
			Destroy(stacks_struct);
			return SYNTAX_ERR;
		}

		Push(stacks_struct, data, status, luts);
		calc_status = Calculate(stacks_struct, luts, &runner );
		if(SUCCESS != calc_status)
		{
			free(data);
			free(luts);
			Destroy(stacks_struct);
			return status;
		}

	}
	
	GetResult(stacks_struct, &result);
	
	free(data);
	free(luts);
	Destroy(stacks_struct);
	
	return status;
}

static calc_luts *InitLuts()
{
	
	calc_luts *luts = (calc_luts *)malloc(sizeof(calc_luts));
	if(NULL == luts)
	{
		return NULL;
	}
	luts->push_oper_type[0] = &PushNumber;
	luts->push_oper_type[1] = &PushSign;
	luts->push_oper_type[2] = &PushSpace;
	luts->push_oper_type[3] = &PushSyncError;
	
	luts->operating_stat[0] = &ErrorCalculate;
	luts->operating_stat[1] = &PlusCalculate;
	luts->operating_stat[2] = &MinusCalculate;
	luts->operating_stat[3] = &MultiplyCalculate;
	luts->operating_stat[4] = &DivideCalculate;
	luts->operating_stat[5] = &PowCalculate;
	luts->operating_stat[7] = &ParentesisCalculate;

	luts->parcer_stat[0] = &ParserERROR;
	luts->parcer_stat[1] = &ParserPlus;
	luts->parcer_stat[2] = &ParserMinus;
	luts->parcer_stat[3] = &ParserMult;
	luts->parcer_stat[4] = &ParserDivide;
	luts->parcer_stat[5] = &ParserPow;
	luts->parcer_stat[6] = &ParserParentesis;
	luts->parcer_stat[7] = &ParserParentesis;
	luts->parcer_stat[8] = &ParserParentesis;
	luts->parcer_stat[9] = &ParserParentesis;
	luts->parcer_stat[10] = &ParserParentesis;
	luts->parcer_stat[11] = &ParserParentesis;
	luts->parcer_stat[12] = &ParserNumber;
	luts->parcer_stat[13] = &ParserSpace;
	
	return luts;
}

void GetResult(pars_stacks *stacks_struct,double **result)
{
	**result = *(double *)StackPeek(stacks_struct->NumStack);
}


static value_t Parcer(char **expression, void *data, size_t *counter, calc_luts *luts, pars_stacks *stacks_struct)
{
	double number = 0;
	char *char_to_push = NULL;
	
	number = strtod((const char *)(*expression), &char_to_push);
	if('\0' == **expression || (IsOperation(*expression) && IsOperation((*expression + 1))))
	{
		return ERROR;
	}
	
	return luts->parcer_stat[OperationType(*expression)](*(&data), *(&counter), *(&expression), &number, stacks_struct);
}


static calculator_status_t Push(pars_stacks *stacks_struct, void *data, value_t status, calc_luts *luts)
{
	return luts->push_oper_type[status](stacks_struct, data);
}


static calculator_status_t Calculate(pars_stacks *stacks_struct, calc_luts *luts, char **expression)
{
	double calculate[2] = {0};
	if(0 == StackIsEmpty((const stack_t *)stacks_struct->OpStack) && IsEndParenthesis((char *)StackPeek(stacks_struct->OpStack)))
	{
		luts->operating_stat[OperationType((char *)StackPeek(stacks_struct->OpStack))](stacks_struct, calculate);
	}

	if(1 == IsOperation(*expression) || '\0' == **expression || 1 == IsBeginParenthesis(*expression) || 1 == IsEndParenthesis(*expression))
	{
		while(2 <= StackSize((const stack_t *)stacks_struct->NumStack) && 0 == StackIsEmpty((const stack_t *)stacks_struct->OpStack) 
			&& 0 == IsBeginParenthesis((char *)StackPeek(stacks_struct->OpStack)))
		{
			
			if(3 == GetPrecedence((char *)StackPeek(stacks_struct->OpStack)) && 3 > GetPrecedence(*expression))
			{
				while(0 == StackIsEmpty((const stack_t *)stacks_struct->OpStack) && '^' == *(char *)StackPeek(stacks_struct->OpStack))
				{
					CalculateOperation(stacks_struct, luts);
				}
			}
			else if(0 <= ToCalculate((char *)StackPeek(stacks_struct->OpStack), *expression))
			{
				CalculateOperation(stacks_struct, luts);
			}
			else
			{
				break;
			}
		}
	}
		return SUCCESS;
}

static void CalculateOperation(pars_stacks *stacks_struct, calc_luts *luts)
{
	double calculate[2] = {0};
	char sign = 0;
	calculate[1] = *(double *)StackPeek(stacks_struct->NumStack);
	StackPop(stacks_struct->NumStack);
	sign = *(char *)StackPeek(stacks_struct->OpStack);
	StackPop(stacks_struct->OpStack);
	calculate[0] = *(double *)StackPeek(stacks_struct->NumStack);
	StackPop(stacks_struct->NumStack);
	luts->operating_stat[OperationType(&sign)](stacks_struct, calculate);
}

static size_t Counter(char *expression)
{
	size_t counter = 0;
	char *runner = expression;
	while(('9' >= *runner && '0' <= *runner) || '.' == *runner)
	{
		++runner;
		++counter;
	}
	return counter;
}

static void Destroy(pars_stacks * stacks_struct)
{
	StackDestroy(stacks_struct->NumStack);
	StackDestroy(stacks_struct->OpStack);
	free(stacks_struct);
}

static pars_stacks *Create(char *expression)
{
	char dummy = '#';
	pars_stacks *stacks_struct = (pars_stacks *)malloc(sizeof(pars_stacks));
	if(NULL == stacks_struct)
	{
		return NULL;
	}
	stacks_struct->NumStack = StackCreate(strlen(expression), sizeof(double));
	if(NULL == stacks_struct->NumStack)
	{
		free(stacks_struct);
		return NULL;
	}
	stacks_struct->OpStack = StackCreate(strlen(expression), sizeof(char));
	if(NULL == stacks_struct->OpStack)
	{
		StackDestroy(stacks_struct->NumStack);
		free(stacks_struct);
		return NULL;
	}
	StackPush(stacks_struct->OpStack,(const void *)&dummy);
	stacks_struct->amount_of_parenthesis = 0;
	return stacks_struct;
}

static int IsOperation(char *expression)
{
	return ('-' == *expression || '+' == *expression || '*' == *expression 
			|| '/' == *expression || '^' == *expression);
}
static int IsBeginParenthesis(char *expression)
{
	return ('(' == *expression || '[' == *expression || '{' == *expression);
}

static int IsEndParenthesis(char *expression)
{
	return (')' == *expression || ']' == *expression || '}' == *expression);
}

static int IsRightEndParenthesis(char expression, pars_stacks *stacks_struct)
{
	return (expression == stacks_struct->last_parenthesis[stacks_struct->amount_of_parenthesis - 1]);
}

static int UpdateLastParenthesis(char *expression, pars_stacks *stacks_struct)
{
	int status = 0;
	switch(*expression)
	{
		case '(':
		{
			stacks_struct->last_parenthesis[stacks_struct->amount_of_parenthesis] = ')';
			stacks_struct->amount_of_parenthesis += 1;
			return SIGN;
		}
		case '[':
		{
			stacks_struct->last_parenthesis[stacks_struct->amount_of_parenthesis] = ']';
			stacks_struct->amount_of_parenthesis += 1;
			return SIGN;
		}
		case '{':
		{
			stacks_struct->last_parenthesis[stacks_struct->amount_of_parenthesis] = '}';
			stacks_struct->amount_of_parenthesis += 1;
			return SIGN;
		}
		case ')':
		{
			status = IsRightEndParenthesis(*expression, stacks_struct);
			stacks_struct->amount_of_parenthesis -= 1;
			if(!status)
			{
				return ERROR;
			}
			return SIGN;
		}
		case ']':
		{
			status = IsRightEndParenthesis(*expression, stacks_struct);
			stacks_struct->amount_of_parenthesis -= 1;
			if(!status)
			{
				return ERROR;
			}
			return SIGN;
		}
		case '}':
		{
			status = IsRightEndParenthesis(*expression, stacks_struct);
			stacks_struct->amount_of_parenthesis -= 1;
			if(!status)
			{
				return ERROR;
			}
			return SIGN;
		}
		default:
		{
			return ERROR;
		}
	}
}
static int OperationType(char *expression)
{
	switch(*expression)
	{
		case '+':
		{
			return 1;
		}
		case '-':
		{
			 return 2;
		}
		case '*':
		{
			 return 3;
		}
		case '/':
		{
			 return 4;
		}
		case '^':
		{
			 return 5;
		}
		case '(':
		{
			 return 6;
		}
		case ')':
		{
			 return 7;
		}
		case '[':
		{
			 return 8;
		}
		case ']':
		{
			 return 9;
		}
		case '{':
		{
			 return 10;
		}
		case '}':
		{
			 return 11;
		}
		case '0':
		{
			 return 12;
		}
		case '1':
		{
			 return 12;
		}
		case '2':
		{
			  return 12;
		}
		case '3':
		{
			  return 12;
		}
		case '4':
		{
			  return 12;
		}
		case '5':
		{
			  return 12;
		}
		case '6':
		{
			 return 12;
		}
		case '7':
		{
			 return 12;
		}
		case '8':
		{
			 return 12;
		}
		case '9':
		{
			 return 12;
		}
		case ' ':
		{
			 return 13;
		}
		default:
		{
			return 0;
		}
	}
}
static int ToCalculate(char *precedence1, char *precedence2)
{
	if(3 == GetPrecedence(precedence1) && 3 ==  GetPrecedence(precedence2))
	{
		return -1;

	}
	return (GetPrecedence(precedence1) - GetPrecedence(precedence2));

}
static int GetPrecedence(char *expression)
{
	switch(*expression)
	{
		case '+':
		{
			return 1;
		}
		case '-':
		{
			 return 1;
		}
		case '*':
		{
			 return 2;
		}
		case '/':
		{
			 return 2;
		}
		case '^':
		{
			 return 3;
		}
		case '(':
		{
			 return 0;
		}
		case ')':
		{
			 return -1;
		}
		case '[':
		{
			 return 0;
		}
		case ']':
		{
			 return -1;
		}
		case '{':
		{
			 return 0;
		}
		case '}':
		{
			 return -1;
		}
		case '#':
		{
			return -100;
		}
		default:
		{
			return -99;
		}
	}
}




static int ParserPlus(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct)
{
	size_t amount_of_char_to_move = 0;
	
	if('-' == **expression && 0 == *counter)
	{
		++(*expression);
		amount_of_char_to_move = Counter(*expression);
		(*expression) = (*expression) + amount_of_char_to_move;
		*(double *)data = *number;
		++(*counter);
		return NUMBER;
	}
	
	(void)stacks_struct;
	*(char *)data = **expression;
	++(*expression);
	++(*counter);
	return SIGN;
}

static int ParserMult(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct)
{
	(void)number;
	(void)counter;
	(void)stacks_struct;
	*(char *)data = **expression;
	++(*expression);
	++(*counter);
	return SIGN;
}

static int ParserDivide(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct)
{
	(void)number;
	(void)counter;
	(void)stacks_struct;
	*(char *)data = **expression;
	++(*expression);
	++(*counter);
	return SIGN;
}

static int ParserPow(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct)
{
	(void)number;
	(void)counter;
	(void)stacks_struct;
	*(char *)data = **expression;
	++(*expression);
	++(*counter);
	return SIGN;
}

static int ParserParentesis(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct)
{
	int status = 0;
	(void)number;
	status = UpdateLastParenthesis(*expression, stacks_struct); 
	*(char *)data = **expression;
	++(*expression);
	(*counter) = 0;
	return status;
}

static int ParserMinus(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct)
{
	size_t amount_of_char_to_move = 0;
	(void)stacks_struct;
	if('-' == **expression && 0 == *counter)
	{
		++(*expression);
		amount_of_char_to_move = Counter(*expression);
		(*expression) = (*expression) + amount_of_char_to_move;
		*(double *)data = *number;
		++(*counter);
		return NUMBER;
	}
		
	*(char *)data = **expression;
	++(*expression);
	++(*counter);
			
	return SIGN;
}

static int ParserNumber(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct)
{
	size_t amount_of_char_to_move = 0;
	(void)stacks_struct;
	amount_of_char_to_move = Counter(*expression);
	(*expression) = (*expression) + amount_of_char_to_move;
	*(double *)data = *number;
	++(*counter);
	return NUMBER;
}

static int ParserSpace(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct)
{
	(void)data;
	(void)number;
	(void)stacks_struct;
	++(*expression);
	++(*counter);
	return SPACE;
}

static int ParserERROR(void* data, size_t* counter, char **expression, double *number, pars_stacks *stacks_struct)
{
	(void)data;
	(void)counter;
	(void)stacks_struct;
	(void)number;
	(void)expression;
	return ERROR;
}




static int ErrorCalculate(pars_stacks *stacks_struct, double *calculate)
{
	(void)stacks_struct;
	(void)calculate;
	return MATH_ERR;
}

static int PlusCalculate(pars_stacks *stacks_struct, double *calculate)
{
	double output = calculate[0] + calculate[1];
	StackPush(stacks_struct->NumStack, (const void *)&output);
	return SUCCESS;
}

static int MinusCalculate(pars_stacks *stacks_struct, double *calculate)
{
	double output = calculate[0] - calculate[1];
	StackPush(stacks_struct->NumStack, (const void *)&output);
	return SUCCESS;
}

static int MultiplyCalculate(pars_stacks *stacks_struct, double *calculate)
{
	double output = calculate[0] * calculate[1];
	StackPush(stacks_struct->NumStack, (const void *)&output);
	return SUCCESS;
}

static int DivideCalculate(pars_stacks *stacks_struct, double *calculate)
{
	double output = calculate[0] / calculate[1];
	StackPush(stacks_struct->NumStack, (const void *)&output);
	return SUCCESS;
}

static int PowCalculate(pars_stacks *stacks_struct, double *calculate)
{
	double output = pow(*calculate, *(calculate + 1));
	StackPush(stacks_struct->NumStack, (const void *)&output);
	return SUCCESS;
}

static int ParentesisCalculate(pars_stacks *stacks_struct, double *calculate)
{
	(void)calculate;
	StackPop(stacks_struct->OpStack);
	StackPop(stacks_struct->OpStack);
	return SUCCESS;
}

static int PushNumber(pars_stacks *stacks_struct, void *data)
{
	StackPush(stacks_struct->NumStack, (const void *)data);
	return SUCCESS;
}

static int PushSign(pars_stacks *stacks_struct, void *data)
{
	StackPush(stacks_struct->OpStack, (const void *)data);
	return SUCCESS;
}

static int PushSpace(pars_stacks *stacks_struct, void *data)
{
	(void)stacks_struct;
	(void)data;
	return SUCCESS;
}

static int PushSyncError(pars_stacks *stacks_struct, void *data)
{
	(void)stacks_struct;
	(void)data;
	return SYNTAX_ERR;
}

