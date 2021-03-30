/*
 ============================================================================
 Name        : DataStructure_Week1.c
 Author      : Itachi
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "data_structures/lifo_stack.h"
#include "string.h"

#ifdef TEST
#define TEST_LL 	0
#define TEST_STACK 	1
#endif /* TEST */

#if TEST
	#include "data_structures/linked_list.h"
	void TestLL(void);
	void TestStack(void);
	char CountChar[]={0,1,2,3,4,5,6,7,8};
	uint8_t g_checkme=255;
#endif  /* End of TEST */


//#define MAX_INPUT 	100000
#define MAX_INPUT 	20
StackObj_T BracketStack;
uint8_t output_str[MAX_INPUT]={0};
char checkme[MAX_INPUT]="foo(bar);";

/* Return 0 if success, or idx based 1 if there is error */
uint32_t IsBalanced(char* p_data)
{
	char input_data[MAX_INPUT]={0};
	strcpy(input_data, p_data);
	for(uint32_t idx=0; idx < strlen(input_data); idx++)
	{
		if( (input_data[idx] == '(')  || (input_data[idx] == '[') || (input_data[idx] == '{'))
		{
			StackPush(&BracketStack, input_data[idx]);
		}
		else if ( (input_data[idx] == ')') || (input_data[idx] == ']') || (input_data[idx] == '}') )
		{
			if(StackIsEmpty(&BracketStack) == true)
				return idx+1; /* Mo? ma khong dong'*/
			else
			{
				uint8_t top = StackGetTop(&BracketStack);
				if( ( (input_data[idx] == ')') && (top != '(')  ) ||
					( (input_data[idx] == ']') && (top != '[')  ) ||
					( (input_data[idx] == '}') && (top != '{')  ) 	 )
					return idx+1; /* Dong khong dung ngoac*/
				else
					StackPop(&BracketStack);
			}
		}
	}
	return 0;
}

int main(void) {
	setbuf(stdout, NULL);
	StackInit(&BracketStack);
	uint32_t where = IsBalanced(checkme);
	if (where == 0)
		printf("Success");
	else
		printf("%d",where);
	return EXIT_SUCCESS;
}


#if TEST_STACK
StackObj_T TestStackObj={0};
void TestStack(void)
{
	StackInit(&TestStackObj);
	if (StackIsEmpty(&TestStackObj) == true)
	{
		StackPush(&TestStackObj, CountChar[0]);
		StackPush(&TestStackObj, CountChar[1]);
		g_checkme = StackGetTop(&TestStackObj);
		g_checkme = StackPop(&TestStackObj);
		g_checkme = StackPop(&TestStackObj);
		g_checkme = StackPop(&TestStackObj);
	}
	else
		printf("What wrong with u \n");
}
#endif  /* End of TEST_STACK */

#if TEST_LL
LLObject_T TestLLObj;
void TestLL(void)
{
	LLObject_T* P_TestLL = LLCreate();
	LLPushFront(&TestLLObj, &CountChar[2]);
	LLPrintList(&TestLLObj);
	LLPushBack(&TestLLObj, &CountChar[0]);
	LLPrintList(&TestLLObj);
	LLPushBack(&TestLLObj, &CountChar[1]);
	LLPushFront(&TestLLObj, &CountChar[3]);
	LLPrintList(&TestLLObj);
	LLPopBack(&TestLLObj);
	LLPrintList(&TestLLObj);
	LLPopFront(&TestLLObj);
	LLPrintList(&TestLLObj);
	LLPrintList(P_TestLL);
}
#endif  /* End of TEST_LL */
