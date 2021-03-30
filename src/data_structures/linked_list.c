/*
 * linked_list.c
 *
 *  Created on: Mar 26, 2021
 *      Author: thuantm
 */

/******************************************************************************
* Includes
*******************************************************************************/
#include "linked_list.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
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
