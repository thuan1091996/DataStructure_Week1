/*
 * lifo_stack.h
 *
 *  Created on: Mar 26, 2021
 *      Author: thuantm
 */

#ifndef LIFO_STACK_H_
#define LIFO_STACK_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

#if NOT_USED
typedef struct myData
{
	uint8_t* p_data;
	uint16_t data_size;
}StackData_T;
#endif  /* End of NOT_USED */

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

#endif /* LIFO_STACK_H_ */
