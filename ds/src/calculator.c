/*
Rev: Maria Ponomariov
Dev: Leonid Golovko
status: finished
date:11/06/2023
*/
#include "calculator.h"

#include <string.h> /*strtod*/
#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <math.h>	/*pow*/

#define AMOUNT_OF_CHAR (256)

typedef struct AllPriorities all_priorities_t;

typedef struct ParsingStacks pars_stacks;

typedef struct calculator calc_t;

typedef calculator_status_t (*calc_func)(double *, double, double);

typedef calculator_status_t (*transition_t)(calc_t *, char **);

typedef calculator_status_t (*push_func_t)(pars_stacks *, void *);

typedef enum Accociablitiy
{
	NOT_POW = 0,
	YES_POW
} accociablitiy_t;

typedef enum Parenthesis
{
	NONE,
	PARENT_ONE = '(',
	PARENT_TWO = '[',
	PARENT_THREE = '{',
	PARENT_ONE_CLOSE = ')',
	PARENT_TWO_CLOSE = ']',
	PARENT_THREE_CLOSE = '}'
} parenthesis_t;

typedef enum calc_priority
{
	END = -2,
	PARENTISIS = -1,
	ZERO,
	ONE,
	TWO,
	THREE,
	CALC_TYPES

} priority_t;

typedef enum calc_status
{
	WAIT_FOR_NUM,
	WAIT_FOR_SIGN,
	STATUS_TYPE
} status_t; /*TODO state*/

typedef enum calc_input
{
	NUMBER_ZERO = '0',
	NUMBER_ONE = '1',
	NUMBER_TWO = '2',
	NUMBER_THREE = '3',
	NUMBER_FOUR = '4',
	NUMBER_FIVE = '5',
	NUMBER_SIX = '6',
	NUMBER_SEVEN = '7',
	NUMBER_EIGHT = '8',
	NUMBER_NINE = '9',
	PLUS = '+',
	MINUS = '-',
	DIVIDE = '/',
	MULTIPLY = '*',
	POW = '^',
	PARETESIS_ONE_OPEN = '(',
	PARETESIS_ONE_CLOSE = ')',
	PARETESIS_TWO_OPEN = '[',
	PARETESIS_TWO_CLOSE = ']',
	PARETESIS_THREE_OPEN = '{',
	PARETESIS_THREE_CLOSE = '}',
	SPACE = ' ',
	GET_RESULT = '\0'
} input_t;

struct ParsingStacks
{
	stack_t *NumStack;
	stack_t *OpStack;
	stack_t *ParenStack;
};

struct AllPriorities
{
	priority_t priority;
	accociablitiy_t accociability;
};

struct calculator
{
	pars_stacks *stacks;
	status_t status;
	size_t pow_before;
	void *data;

	transition_t transition_table[STATUS_TYPE][AMOUNT_OF_CHAR];

	all_priorities_t char_LUT_priority[AMOUNT_OF_CHAR];

	calc_func char_LUT_calculate[AMOUNT_OF_CHAR];

	parenthesis_t Parenthesis_LUT_check[AMOUNT_OF_CHAR];
};

/********************calc creation functions*************************/
static calc_t *CreateCalculator(char *expression);
static void CharLut(calc_t *calculator);
static void StatesTable(calc_t *calculator);
static pars_stacks *CreateStacks(char *expression);
static void Destroy(calc_t *calculator);
/********************calc functions*************************/
static calculator_status_t PlusCalculate(double *result, double number1, double number2);
static calculator_status_t MinusCalculate(double *result, double number1, double number2);
static calculator_status_t MultiplyCalculate(double *result, double number1, double number2);
static calculator_status_t DivideCalculate(double *result, double number1, double number2);
static calculator_status_t PowCalculate(double *result, double number1, double number2);
static calculator_status_t ErrorCalculate(double *result, double number1, double number2);
static calculator_status_t ParentesisCalculate(double *result, double number1, double number2);
static calculator_status_t CalculateOperation(calc_t *calculator);
/********************transition table functions*************************/
static calculator_status_t ReceiveError(calc_t *calculator, char **array);
static calculator_status_t ReceiveNum(calc_t *calculator, char **array);
static calculator_status_t ReceiveSign(calc_t *calculator, char **array);
static calculator_status_t ReceivePow(calc_t *calculator, char **array);
static calculator_status_t ReceiveResult(calc_t *calculator, char **array);
static calculator_status_t ReceiveParentesisOpen(calc_t *calculator, char **array);
static calculator_status_t ReceiveParentesisClose(calc_t *calculator, char **array);
static calculator_status_t ReceiveSpace(calc_t *calculator, char **array);

static void GetResult(calc_t *calculator, double **result);

/********************main function*************************/

calculator_status_t Calculator(const char *expression, double *result)
{

	char *runner = NULL;
	calc_t *calculator = NULL;

	calculator_status_t status = SUCCESS;
	assert(expression);
	assert(result);

	runner = (char *)expression;

	calculator = CreateCalculator(runner);
	if (NULL == calculator)
	{
		return (MEMORY_ALLOC_ERR);
	}

	while ('\0' != *runner && SUCCESS == status)
	{
		status = (calculator_status_t)calculator->transition_table[calculator->status][(int)*runner](calculator, (char **)&runner);
	}

	if(WAIT_FOR_NUM == calculator->status || 0 != StackSize((const stack_t *)calculator->stacks->ParenStack)) /*ENUM*/ /*RETURN ();*/
	{
		status = SYNTAX_ERR;
	}
	
	if (SUCCESS != status)
	{
		Destroy(calculator);
		return (status);
	}
	
	status = ReceiveResult(calculator, (char **)&runner);
	GetResult(calculator, &result);
	Destroy(calculator);

	return (status);
}

/********************static functions*************************/
static void CharLut(calc_t *calculator)
{
	int i = 0;

	for (i = 0; i < AMOUNT_OF_CHAR; ++i)
	{
		calculator->char_LUT_calculate[i] = &ErrorCalculate;
		calculator->char_LUT_priority[i].priority = ZERO;
		calculator->char_LUT_priority[i].accociability = NOT_POW;
	}

	for (i = 0; i < AMOUNT_OF_CHAR; ++i)
	{
		calculator->Parenthesis_LUT_check[i] = NONE;
	}

	calculator->Parenthesis_LUT_check[PARENT_ONE] = PARENT_ONE_CLOSE;
	calculator->Parenthesis_LUT_check[PARENT_TWO] = PARENT_TWO_CLOSE;
	calculator->Parenthesis_LUT_check[PARENT_THREE] = PARENT_THREE_CLOSE;

	calculator->Parenthesis_LUT_check[PARENT_ONE_CLOSE] = PARENT_ONE;
	calculator->Parenthesis_LUT_check[PARENT_TWO_CLOSE] = PARENT_TWO;
	calculator->Parenthesis_LUT_check[PARENT_THREE_CLOSE] = PARENT_THREE;

	calculator->char_LUT_priority[GET_RESULT].priority = END;

	calculator->char_LUT_calculate[PLUS] = &PlusCalculate;
	calculator->char_LUT_priority[PLUS].priority = ONE;

	calculator->char_LUT_calculate[MINUS] = &MinusCalculate;
	calculator->char_LUT_priority[MINUS].priority = ONE;

	calculator->char_LUT_calculate[MULTIPLY] = &MultiplyCalculate;
	calculator->char_LUT_priority[MULTIPLY].priority = TWO;

	calculator->char_LUT_calculate[DIVIDE] = &DivideCalculate;
	calculator->char_LUT_priority[DIVIDE].priority = TWO;

	calculator->char_LUT_calculate[POW] = &PowCalculate;
	calculator->char_LUT_priority[POW].priority = THREE;
	calculator->char_LUT_priority[POW].accociability = YES_POW;

	calculator->char_LUT_priority[PARETESIS_ONE_OPEN].priority = PARENTISIS;
	calculator->char_LUT_priority[PARETESIS_ONE_CLOSE].priority = PARENTISIS;

	calculator->char_LUT_calculate[PARETESIS_ONE_OPEN] = &ParentesisCalculate;
	calculator->char_LUT_calculate[PARETESIS_ONE_CLOSE] = &ParentesisCalculate;

	calculator->char_LUT_priority[PARETESIS_TWO_OPEN].priority = PARENTISIS;
	calculator->char_LUT_priority[PARETESIS_TWO_CLOSE].priority = PARENTISIS;

	calculator->char_LUT_calculate[PARETESIS_TWO_OPEN] = &ParentesisCalculate;
	calculator->char_LUT_calculate[PARETESIS_TWO_CLOSE] = &ParentesisCalculate;

	calculator->char_LUT_priority[PARETESIS_THREE_OPEN].priority = PARENTISIS;
	calculator->char_LUT_priority[PARETESIS_THREE_CLOSE].priority = PARENTISIS;

	calculator->char_LUT_calculate[PARETESIS_THREE_OPEN] = &ParentesisCalculate;
	calculator->char_LUT_calculate[PARETESIS_THREE_CLOSE] = &ParentesisCalculate;
}

static void StatesTable(calc_t *calculator)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < STATUS_TYPE; ++i)
	{
		for (j = 0; j < AMOUNT_OF_CHAR; ++j)
		{
			calculator->transition_table[i][j] = &ReceiveError;
		}
	}
	for (i = (int)NUMBER_ZERO; i <= (int)NUMBER_NINE; ++i)
	{
		calculator->transition_table[WAIT_FOR_NUM][i] = &ReceiveNum;
	}
	for (i = 0; i < STATUS_TYPE; i++)
	{
		calculator->transition_table[i][SPACE] = &ReceiveSpace;
	}

	calculator->transition_table[WAIT_FOR_NUM][PLUS] = &ReceiveNum;
	calculator->transition_table[WAIT_FOR_NUM][MINUS] = &ReceiveNum;

	calculator->transition_table[WAIT_FOR_SIGN][PLUS] = &ReceiveSign;
	calculator->transition_table[WAIT_FOR_SIGN][MINUS] = &ReceiveSign;

	calculator->transition_table[WAIT_FOR_SIGN][MULTIPLY] = &ReceiveSign;
	calculator->transition_table[WAIT_FOR_NUM][MULTIPLY] = &ReceiveError;

	calculator->transition_table[WAIT_FOR_SIGN][DIVIDE] = &ReceiveSign;
	calculator->transition_table[WAIT_FOR_NUM][DIVIDE] = &ReceiveError;

	calculator->transition_table[WAIT_FOR_SIGN][POW] = &ReceivePow;
	calculator->transition_table[WAIT_FOR_NUM][POW] = &ReceiveError;

	calculator->transition_table[WAIT_FOR_SIGN][GET_RESULT] = &ReceiveResult;
	calculator->transition_table[WAIT_FOR_NUM][GET_RESULT] = &ReceiveError;

	calculator->transition_table[WAIT_FOR_SIGN][PARETESIS_ONE_OPEN] = &ReceiveError;
	calculator->transition_table[WAIT_FOR_NUM][PARETESIS_ONE_OPEN] = &ReceiveParentesisOpen;

	calculator->transition_table[WAIT_FOR_NUM][PARETESIS_ONE_CLOSE] = &ReceiveError;
	calculator->transition_table[WAIT_FOR_SIGN][PARETESIS_ONE_CLOSE] = &ReceiveParentesisClose;

	calculator->transition_table[WAIT_FOR_SIGN][PARETESIS_TWO_OPEN] = &ReceiveError;
	calculator->transition_table[WAIT_FOR_NUM][PARETESIS_TWO_OPEN] = &ReceiveParentesisOpen;

	calculator->transition_table[WAIT_FOR_NUM][PARETESIS_TWO_CLOSE] = &ReceiveError;
	calculator->transition_table[WAIT_FOR_SIGN][PARETESIS_TWO_CLOSE] = &ReceiveParentesisClose;

	calculator->transition_table[WAIT_FOR_SIGN][PARETESIS_THREE_OPEN] = &ReceiveError;
	calculator->transition_table[WAIT_FOR_NUM][PARETESIS_THREE_OPEN] = &ReceiveParentesisOpen;

	calculator->transition_table[WAIT_FOR_NUM][PARETESIS_THREE_CLOSE] = &ReceiveError;
	calculator->transition_table[WAIT_FOR_SIGN][PARETESIS_THREE_CLOSE] = &ReceiveParentesisClose;
}




static void GetResult(calc_t *calculator, double **result)
{
	**result = *(double *)StackPeek(calculator->stacks->NumStack);
}

static void Destroy(calc_t *calculator)
{
	StackDestroy(calculator->stacks->ParenStack);
	StackDestroy(calculator->stacks->NumStack);
	StackDestroy(calculator->stacks->OpStack);
	free(calculator->stacks);
	free(calculator);
}

static calc_t *CreateCalculator(char *expression)
{
	calc_t *calculator = (calc_t *)malloc(sizeof(calc_t));
	if (NULL == calculator)
	{
		return NULL;
	}

	CharLut(calculator);
	StatesTable(calculator);

	calculator->stacks = CreateStacks(expression);
	if (NULL == calculator->stacks)
	{
		free(calculator);
		return NULL;
	}

	calculator->status = WAIT_FOR_NUM;
	calculator->pow_before = 0;
	calculator->data = NULL;

	return (calculator);
}

static pars_stacks *CreateStacks(char *expression)
{
	char dummy = '#';
	pars_stacks *stacks_struct = (pars_stacks *)malloc(sizeof(pars_stacks));
	if (NULL == stacks_struct)
	{
		return NULL;
	}
	stacks_struct->NumStack = StackCreate(strlen(expression), sizeof(double));
	if (NULL == stacks_struct->NumStack)
	{
		free(stacks_struct);
		return NULL;
	}
	stacks_struct->OpStack = StackCreate(strlen(expression), sizeof(char));
	if (NULL == stacks_struct->OpStack)
	{
		StackDestroy(stacks_struct->NumStack);
		free(stacks_struct);
		return NULL;
	}
	StackPush(stacks_struct->OpStack, (const void *)&dummy);
	stacks_struct->ParenStack = StackCreate(strlen(expression), sizeof(char));
	if (NULL == stacks_struct->ParenStack)
	{
		StackDestroy(stacks_struct->OpStack);
		StackDestroy(stacks_struct->NumStack);
		free(stacks_struct);
		return NULL;
	}
	return (stacks_struct);
}



static calculator_status_t ReceiveError(calc_t *calculator, char **array)
{
	(void)calculator;
	(void)array;
	return (SYNTAX_ERR);
}

static calculator_status_t ReceiveNum(calc_t *calculator, char **array)
{
	double number = 0;
	char *current_char = *array;

	number = strtod(*array, &current_char);
	*array = current_char;
	StackPush(calculator->stacks->NumStack, &number);
	calculator->status = WAIT_FOR_SIGN;
	return (SUCCESS);
}

static calculator_status_t ReceiveSign(calc_t *calculator, char **array)
{
	calculator_status_t status = SUCCESS;

	while ((1 != StackSize((const stack_t *)calculator->stacks->OpStack) && 
		   (calculator->char_LUT_priority[(int)**array].priority <=
	       calculator->char_LUT_priority[(int)*(char *)StackPeek(calculator->stacks->OpStack)].priority)) &&
		   SUCCESS == status)  /*CHECK <= add (int)calculator->char_LUT_priority[(int)**array].accociability*/
	{
		status = CalculateOperation(calculator);
	}

	StackPush(calculator->stacks->OpStack, *array);
	calculator->status = WAIT_FOR_NUM;
	*array += 1;
	return (status);
}

static calculator_status_t ReceivePow(calc_t *calculator, char **array)
{

	calculator_status_t status = SUCCESS;

	while ((1 != StackSize((const stack_t *)calculator->stacks->OpStack) 
							&& (calculator->char_LUT_priority[(int)**array].priority +
							(int)calculator->char_LUT_priority[(int)**array].accociability <=
							(int)calculator->char_LUT_priority[(int)*(char *)StackPeek(calculator->stacks->OpStack)].priority)) 
							&& SUCCESS == status)
	{
		status = CalculateOperation(calculator);
	}

	StackPush(calculator->stacks->OpStack, *array);
	calculator->status = WAIT_FOR_NUM;
	*array += 1;
	return (status);
}

static calculator_status_t ReceiveResult(calc_t *calculator, char **array)
{
	char sign = 0;
	calculator_status_t status = SUCCESS;

	while (1 != StackSize((const stack_t *)calculator->stacks->OpStack) && SUCCESS == status)
	{
		sign = *(char *)StackPeek(calculator->stacks->OpStack);
		if (calculator->char_LUT_priority[(int)**array].priority <=
			calculator->char_LUT_priority[(int)sign].priority)
		{
			status = CalculateOperation(calculator);
		}
	}
	calculator->status = WAIT_FOR_NUM;
	return (status);
}

static calculator_status_t CalculateOperation(calc_t *calculator)
{
	double calculate[2] = {0};
	char sign = 0;
	calculator_status_t status = SUCCESS;
	double result = 0;

	sign = *(char *)StackPeek(calculator->stacks->OpStack);
	calculate[1] = *(double *)StackPeek(calculator->stacks->NumStack);
	StackPop(calculator->stacks->NumStack);
	StackPop(calculator->stacks->OpStack);
	calculate[0] = *(double *)StackPeek(calculator->stacks->NumStack);
	StackPop(calculator->stacks->NumStack);
	status = calculator->char_LUT_calculate[(int)sign](&result, calculate[0], calculate[1]);
	StackPush(calculator->stacks->NumStack, &result);
	return (status);
}

static calculator_status_t ReceiveParentesisOpen(calc_t *calculator, char **array)
{
	StackPush(calculator->stacks->ParenStack, &calculator->Parenthesis_LUT_check[(int)**array]);
	StackPush(calculator->stacks->OpStack, *array);
	calculator->status = WAIT_FOR_NUM;
	*array += 1;
	return (SUCCESS);
}
static calculator_status_t ReceiveParentesisClose(calc_t *calculator, char **array)
{
	calculator_status_t status = SUCCESS;
	if (1 == StackIsEmpty(calculator->stacks->ParenStack) || 
	    **array != *(char *)StackPeek(calculator->stacks->ParenStack))
	{
		return (SYNTAX_ERR);
	}
	while (1 != StackSize((const stack_t *)calculator->stacks->OpStack) && SUCCESS == status 
		   && (int)calculator->Parenthesis_LUT_check[(int)**array] 
		   != (int)*(char *)StackPeek(calculator->stacks->OpStack))
	{
		status = CalculateOperation(calculator);
	}
	StackPop(calculator->stacks->OpStack);
	StackPop(calculator->stacks->ParenStack);
	calculator->status = WAIT_FOR_SIGN;
	*array += 1;
	return (status); 
}

static calculator_status_t ReceiveSpace(calc_t *calculator, char **array)
{
	(void)calculator;
	(void)array;
	*array += 1;
	return (SUCCESS);
}

static calculator_status_t PlusCalculate(double *result, double number1, double number2)
{
	*result = number1 + number2;
	return (SUCCESS);
}

static calculator_status_t MinusCalculate(double *result, double number1, double number2)
{
	*result = number1 - number2;
	return (SUCCESS);
}

static calculator_status_t MultiplyCalculate(double *result, double number1, double number2)
{
	*result = number1 * number2;
	return (SUCCESS);
}

static calculator_status_t DivideCalculate(double *result, double number1, double number2)
{
	if (0 == number2)
	{
		return (MATH_ERR);
	}
	*result = number1 / number2;
	return (SUCCESS);
}

static calculator_status_t PowCalculate(double *result, double number1, double number2)
{
	*result = pow(number1, number2);
	return (SUCCESS);
}

static calculator_status_t ErrorCalculate(double *result, double number1, double number2)
{
	(void)result;
	(void)number1;
	(void)number2;
	return (SYNTAX_ERR);
}

static calculator_status_t ParentesisCalculate(double *result, double number1, double number2)
{
	(void)result;
	(void)number1;
	(void)number2;
	return (SUCCESS);
}
