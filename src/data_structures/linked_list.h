/*
 * linked_list.h
 *
 *  Created on: Mar 26, 2021
 *      Author: thuantm
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/

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
	#if 0
	/* Interface */
	void*	(*GetBack)();
	void*	(*GetFront)();
	void 	(*PopBack)();
	void 	(*PopFront)();
	void 	(*PushBack)(void* Key_P);
	void 	(*PushFront)(void* Key_P);
	void 	(*PrintList)();
	bool	(*IsEmpty)();
	bool	(*IsExist)(void* Key_P);
	#endif  /* End of 0 */
	/* Attribute */
	myLL* Head_P;
	myLL* Tail_P;
}LLObject_T;

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void* LLGetFront(LLObject_T* Obj_P);
void* LLGetBack(LLObject_T* Obj_P);
void  LLPopFront(LLObject_T* Obj_P);
void  LLPopBack(LLObject_T* Obj_P);
void  LLPrintList(LLObject_T* Obj_P);
void  LLInit(LLObject_T* Obj_P);
void  LLPushFront(LLObject_T* Obj_P, void* Key_P);
void  LLPushBack(LLObject_T* Obj_P, void* Key_P);
bool LLIsExist(LLObject_T* Obj_P, void* Key_P);
bool LLIsEmpty(LLObject_T* Obj_P);
LLObject_T* LLCreate(void);


#endif /* LINKED_LIST_H_ */
