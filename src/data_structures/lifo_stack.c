/*
 * lifo_stack.c
 *
 *  Created on: Mar 26, 2021
 *      Author: thuantm
 */

/******************************************************************************
* Includes
*******************************************************************************/
#include "lifo_stack.h"
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



