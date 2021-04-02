/*
 ============================================================================
 Name        : DataStructure_Week1.c
 Author      : Itachi
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//#include "data_structures/lifo_stack.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "string.h"

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct Mylist
{
    void* Key_P;
    struct Mylist *Next_P;
}myLL;

typedef struct LLObject
{
	/* Attribute */
	myLL* Head_P;
	myLL* Tail_P;
}LLObject_T;

typedef struct myStack
{
	LLObject_T*	 	StackLL;
	uint16_t 		numbElement;
}StackObj_T;
/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
//StackObj_T* StackCreate(void);
void StackInit(StackObj_T* Obj_P);
void StackPush(StackObj_T* Obj_P, uint8_t data);
uint8_t StackGetTop(StackObj_T* Obj_P);
uint8_t StackPop(StackObj_T* Obj_P);
bool StackIsEmpty(StackObj_T* Obj_P);


StackObj_T BracketStack;
StackObj_T PosStack;



#define TEST 0

#if TEST
#define MAX_INPUT 	200000
char input_data[MAX_INPUT]="{}{}[]{[]}{}[][]{}(){}{}()[][[]]{}{}[]{}[]()[()][](){}{}[]{()}()[][[]]{}[](){{}}[({})][]({})(){}[](())(()){}[][[]]()[][()]{}{[]}{}{}(){}()[][]()()()[()]({}){}(){}[](){}[]()[]{}()[]()[](){}[]({}){}[{}][](){}(())()[[]][()][]()[][]()[][]{}[]()[][]((()))[][](())({})[][]{}()({[]})([])()()[][()][[]](){}{}(())[[]](())()[]()[]()()({})(){()}({})()(){}()()[](([]))()[()][]{}()[()]()([]){}(){{}}{}[()]([])()[]{}{}[](){}[{}](){}[]{[]}[][]()()()({}){}{{{}}}(())[{{}}][({})]{{}}{[]}{}{}({})[][{}]()([])(()){()}()[]{{}}{}((())){}[[{()}]]{}{}({{}}){[]}{}{}{{}}[[{}]][][[()]]()(){(())}([])()[](){}[]()[]{{}}[][][[]]()[][()](())[]()[[]]{}{}[{}]()(){}(){}{}{}[{}][]{()}{{}}{{}}[{}]{}()()(()){}[][{}]{()}{}{[]}{}[]{{}}{{}}{()}(){}()({}){}{}[]([])[]()[][]{()}()[{}][]()[{}]{}(){[]}{}(){[]}(){()}[][([])][{}][()](){()}{}[{}]()()()[]{[]}{{}}{{()}}[{}]{{}}[][]{}({})()[][]()()[[]](())[()]{}[()][][][[]][()][]{}()()[][][{}]()[{}]()[]([{}])[([])]()([])()(){{}}{}()[[]]()(){}([])[]({{}}){}{}[][][]{}[]{}()(){}(){{}}(){}(()){{}}{{}}()[]{}([{}])((()))[()]{}[]{}[]{}()[{}]()[][[{}]]{[]}({})()[{}]{}()[{}][][]([]){[]}{}(){[]}(){}[[]]()[[]]()()()[]()({{}})[]()((()))()([]){}[()][]{}()[](()){}[][[]][[]]{}()([])[]({})()[]{}({}){}()(){}()(()){}()(){}{}{}{[]}()[]()()[]{[]}(){}[[]]()[()][][][][[]][{}]({})({})(()){}{({})}{{}}{}[]{}[()]()(){}[]{[]}()[]()()()({{}})()(){}({()})[()](([()])){{{}}}(())[]{}(){}[[]][]{}[]{}[]{()}()[]{}()[]{}{}{}[]{}{{}}{()}[()]{{}}[]{{}}[]{}([]){}({}){}[]{}()()(){}()[]{{}}{}{}(([{}]))[{}]()[]{(())}[]()[]{}()()([])[()]()()()(){{}}()()()[[]]{}(){[]}[[]]({})[([[]])]{{{[]}}}[{([])}]({[{}]})[[]][]{{({})}}()[][{[]}]{}{({()})}{}[(())]{}[](){}()[]{}{}[]{}(()){}[[]]()()(){}{}(){{}}[]()(){}(){}[()](){}{}(){}()[()]()()[][][]{}[][[]]()[]{[]}[]{()}(){}()[]{}{}[()][]{{}}[[[]]][()]{}([{()}])[[[]]][]()(){}()()()()[[]][{}]{}{}[][[]][[]]{()}[({})]{}{{}}[]{{}}[()]{{}}[]{}({}){{}}{[]}(){}{}{}[][()][]()(){({})}(()){}[][][]{}{()}()[]({[{}]})[]{[{}]}[]{{}}{}{}([])()()()({}){}[]()[][{}]{{}}{}[](){}()({}){{[]}}()[]{}{}{}{()}{}{}(){}()({})[{}]{}[{}]()(()){}[]{()}[[()]]{}(){()}{}(){}{}()[]{}[]()[](){[]}[][{}]{{}}[](({}))[][()][]{{}}()(()){}[]{{}}[][]{}{}{}(){}{}{}()()(){}()[]({})()[{}]{}{()}[]{{{}}}[]()(()){[]}[{}]{}{}()[][]()(){}[][][]({})[]{}(){}{{}}(()){}()[]{}[{()}](([])){}()({})[()]()[][[()]][]{}{}{}[]{}[]{}()[]{()}(){}[]{}(){}()(){}[]()(){}(()){}(())[]([])[]{}[][]()[()]({({})}){(({}))}[][]{{({})} ... [{()}]}{{}}()[][]({(())})[]{}[()][[()]][]{}()(){}()()()()()(){}[]()[][](){}()(({[]}))({})[]({{({})}})[[]]({({[]})})([{(())}]){}{}{{}}[]([])[][]()[()]{}{}()[[]]()[](){[]}[][({[]})]{}{[]}[{}][][]{}{[[{}]]}(())[(({}))][]({})()({[]}){[]}[[()]][[]](){[]}[(([[]]))][][]()[][][][][]()[][[{{{}}}]][][]{}(([[()]])){[[]]}[[]](())(()){}[][([])]{}[][{}](){[]}({})(())(){}()[[]]()[[()]]{}([()])({()})(){({})}[][][]()[{}]()(){}()[][]()[]{}{}(){}{}(())[][]{}[][[]]()()[{}]()[][{}][]()[()]{[[[()]]]}{}{}[({{()}})]{}[][][]{}{}[{}][()]{}()[](){}()[()](){{}}{}[][][[[{}]]](){}{}[](())(){}{}()()(){{}}(){}[[]][()]{()}()((())){{}}()(){}()[]()()[][][][]{}[][]{}()[]()[]{}(){}{}([])([])(){[]}[{}]({}){}[][]()(())[][](){{}}{}{}{({})}{}[](({}))(){}{()}[][]([])(){[]}[]{}{()}(()){}()()[][{}]{}(){{}}{}{{}}()[{}](){}{}[[]][]{}()[]{}({{}})[({})]({})()[](){}([]){[()]}[{}](){{}}([[]])[[]][][]()[()]()[][][]{}{()}[][]({}){}{}[[]]{[]}[]{}{}[]{[]}{}[[[]]]{}[]()[]{}({[{()}]}){{[{(())}]}}[]{([[]])}[]()[()](){}[][]{(())}[]{}()[][{}][]{}(())(){[{[{}]}]}{}[]{}[({})]()()[]((({()})))(({})){}{()}()()()()()[]{}()(){()}([])[]{[([])]}[[{{[]}}]]{}{}{}[]{[]}[]{}[][]({})(({})){}[[()]][]{()}[][()][][]{{}}()[[]][{}]{}{}[]()[](){{}}{}[[]]{}[{}]({})[][]{}{}({})()[]{}{[]}[]{}[][]{}[]{}(){}()[]([])[][{}][]{{}}[{[]}]{}[(())](){}(){}((()))()()()()(){}{{}}()[](){}(())({()}){}[]{}(){}[()]{}((()))({})[()]{}{}{}({})[[]]{}(){}{}{}{{}}[]()[[]][]()[](){}[]{}[]()([]){}({})[{}]{}()[]([[[]]])[[[]]]()([])(){}[]{}()[]{}[]{{()}}([]){{{}}}[{}]{}{[]}[([])]{}[{}][[[]]]()()[{}]{}{}{}(){}()()()()[]()()({})([])()[][]{}()[()][]()[]{}(()){()}{()}{()}{}{}(){}[]{[]}[({})][][][]{}{}(){}(){}{}{}{()}{}(){}{}{}{}[()]{}{({})}[([])][]()()[{}](){}[[]][[[]]]{[]}{{}}()(([]))()(){}[][]()(){}()({})()([])()[][{}]()()([[[]]]){{[]}}[]({()}){[]}{[]}()[[]]{[]}[{}]{}{}[][]{}[{}][{}]{}[]{()}(){{()}}{{{}}}{}{}{}[()][]{}[()]()({{}}){[]}{({[]})}{}({}){}{}()[][()][]()(){}([])[]({{}})(())({})()(){}([]){}[[[]]](){}{}({})[]([])(){}(){[{}]}{[]}[{()}]{[]}{[]}[][]{}{}{[]}()()[]{{}}{}{[]}{}[{}][]{}({}){}[()]([])()[]{}{{}}()(())[[]](){}[](){{}}()()()[]()[](){}([()])()({()}){}({[{}]})[]{}([]){}[[]]{}{}[]()[(())][][][](())[([])](()){}{}{{[]}}{}()()[][]()({})[][]()(){}()[]({{}})(){[]}[]()[](())()(){}{()}({})[()](){{}}{()}()[]{[]}{{}}{{{}}}(){}{{}}{()}{()}[]{}()[]{()}(){}[]{}{}[]()";
#else
#define MAX_INPUT 	200000
#endif  /* End of TEST */

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
			StackPush(&PosStack, idx);
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
				{
					StackPop(&BracketStack);
					StackPop(&PosStack);
				}
			}
		}
	}
	uint32_t last_index=0;
	if(StackIsEmpty(&BracketStack) == false)	/* Mo khong dong */
	{
		while(StackIsEmpty(&PosStack) == false)
		{
			 last_index = StackGetTop(&PosStack);
			 StackPop(&PosStack);
		}
		return last_index+1;
	}
	return 0;
}

int main(void) {
	setbuf(stdout, NULL);
	StackInit(&BracketStack);
	StackInit(&PosStack);
	#if !TEST
	char checkme[MAX_INPUT]={0};
	gets(checkme);
	uint32_t where = IsBalanced(checkme);
	#else
	uint32_t where = IsBalanced(input_data);
	#endif  /* End of TEST */

	if (where == 0)
		printf("Success");
	else
		printf("%d",where);
	return EXIT_SUCCESS;
}

void* LLGetFront(LLObject_T* Obj_P)
{
	return Obj_P->Head_P->Key_P;
}

void* LLGetBack(LLObject_T* Obj_P)
{
	return Obj_P->Tail_P->Key_P;
}

void LLPushFront(LLObject_T* Obj_P, void* Key_P)
{
	myLL* p_newNode = (myLL*) malloc( sizeof(myLL) );
	if (p_newNode == NULL)
	{
		printf("Cant allocate memory \n");
		while(1);
	}
	p_newNode->Key_P = Key_P;
	p_newNode->Next_P = Obj_P->Head_P;
	Obj_P->Head_P = p_newNode;
    if(Obj_P->Tail_P == NULL) Obj_P->Tail_P = Obj_P->Head_P;
}

void LLPushBack(LLObject_T* Obj_P, void* Key_P)
{
	myLL* p_newNode = (myLL*) malloc( sizeof(myLL) );
	if (p_newNode == NULL)
	{
		printf("Cant allocate memory \n");
		while(1);
	}
	p_newNode->Key_P = Key_P;
	p_newNode->Next_P = NULL;
	if(Obj_P->Head_P == NULL)
	{
		Obj_P->Head_P = p_newNode;
		Obj_P->Tail_P = Obj_P->Head_P;
	}
	else
	{
		Obj_P->Tail_P->Next_P = p_newNode;
		Obj_P->Tail_P = p_newNode;
	}
}

void LLPopFront(LLObject_T* Obj_P)
{
	if(Obj_P->Head_P == NULL)
	{
		printf("Error: HeadPt Null ???\n");
		while(1);
	}
	else
	{
		myLL *p_curhead = Obj_P->Head_P;
		Obj_P->Head_P = Obj_P->Head_P->Next_P;
		if(Obj_P->Head_P == NULL) Obj_P->Tail_P = NULL;
		free(p_curhead);
	}
}

void LLPopBack(LLObject_T* Obj_P)
{
	if(Obj_P->Head_P == NULL)
		printf("There is nothing to pop \n");
	else
	{
		myLL* p_temp=Obj_P->Head_P;
		if (Obj_P->Head_P == Obj_P->Tail_P)
		{
			Obj_P->Head_P = NULL;
			Obj_P->Tail_P = NULL;
		}
		else
		{
			while(p_temp->Next_P != Obj_P->Tail_P)
			{
				p_temp = p_temp->Next_P;
			}
			p_temp->Next_P = NULL;	/* Update node before tail */
			Obj_P->Tail_P = p_temp;
			p_temp = p_temp->Next_P;
		}
		free(p_temp);
	}
}

void LLPrintList(LLObject_T* Obj_P)
{
	printf("\n");
	printf("HeadPt: %p \n", Obj_P->Head_P);
	myLL* p_cur = Obj_P->Head_P;
	printf("------------------------------------------------------- \n");
	while(1)
	{
		if(p_cur != NULL)
		{
			printf("Address %p --- Value: %3d --- Next: %p \n", p_cur, *((uint8_t*)p_cur->Key_P), p_cur->Next_P);
			p_cur = p_cur->Next_P;
		}
		else
		{
			break;
		}
	}
	printf("------------------------------------------------------- \n");
	printf("TailPt: %p \n",Obj_P->Tail_P);
	printf("\n");
}

void LLInit(LLObject_T* Obj_P)
{
	#if 0
	LL_P->GetFront	= &LLGetFront;
	LL_P->GetBack	= &LLGetBack;
	LL_P->PushFront	= &LLPushFront;
	LL_P->PushBack	= &LLPushBack;
	LL_P->PopFront	= &LLPopFront;
	LL_P->PopBack	= &LLPopBack;
	LL_P->IsEmpty	= &LLIsEmpty;
	LL_P->IsExist	= &LLIsExist;
	LL_P->PrintList	= &LLPrintList;
	#endif  /* End of 0 */
}

bool LLIsEmpty(LLObject_T* Obj_P)
{
	if(Obj_P->Head_P == NULL)
		return true;
	else
		return false;
}

bool LLIsExist(LLObject_T* Obj_P, void* Key_P)
{
	myLL* p_cur = Obj_P->Head_P;
	while(p_cur != NULL)
	{
		if (p_cur->Key_P != Key_P)
			p_cur = p_cur->Next_P;
		else
			return true;
	}
	return false;
}

LLObject_T* LLCreate(void)
{
	LLObject_T *p_ll = malloc(sizeof (LLObject_T));
	if (p_ll == NULL)
	{
		while(1);
	}
	p_ll->Head_P= NULL;
	p_ll->Tail_P= NULL;
	return p_ll;
}

bool StackIsEmpty(StackObj_T* Obj_P)
{
	if(LLIsEmpty(Obj_P->StackLL) == true)
		return true;
	else
		return false;
}


void StackPush(StackObj_T* Obj_P, uint8_t data)
{
	uint8_t* p_data = (uint8_t*) malloc( sizeof(data));
	*p_data = data;
	LLPushFront(Obj_P->StackLL, p_data);
	Obj_P->numbElement++;
}

/*
 * Return the top element without popping it out
 */
uint8_t StackGetTop(StackObj_T* Obj_P)
{
	uint8_t retval=0;
	if( StackIsEmpty(Obj_P) == true)
	{
		printf("Stack is empty");
	}
	else
	{
		retval = *(uint8_t*)LLGetFront(Obj_P->StackLL);
	}
	return retval;
}

uint8_t StackPop(StackObj_T* Obj_P)
{
	uint8_t retval=0;
	if (StackIsEmpty(Obj_P) == true)
	{
		printf("Stack is empty");
	}
	else
	{
		uint8_t* p_data = (uint8_t*) LLGetFront(Obj_P->StackLL);
		retval = *p_data;
		LLPopFront(Obj_P->StackLL);
		free(p_data);
		Obj_P->numbElement--;
	}
	return retval;
}

void StackInit(StackObj_T* Obj_P)
{
	Obj_P->StackLL = LLCreate();
	Obj_P->numbElement = 0;
}

