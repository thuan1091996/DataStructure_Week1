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

#define MAX_INPUT 	10
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

StackObj_T BracketStack;
uint8_t output_str[MAX_INPUT]={0};
char checkme[MAX_INPUT]={"[[(()]"};



int main(void) {
	setbuf(stdout, NULL);
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
