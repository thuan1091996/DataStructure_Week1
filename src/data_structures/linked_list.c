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
static myLL *p_head=NULL; 	/* <-- cur Head */
static myLL *p_tail=NULL;	/* <-- cur Tail */


/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
void LLPushFront(myLL *newNode)
{
	printf("Push in %d \n", newNode->value);
	newNode->next = p_head;
    p_head = newNode;
    if(p_tail == NULL) p_tail = p_head;
}

void LLPopFront(void)
{
	printf(" ======== Remove head =========>\n");
	if(p_head == NULL)
	{
		printf("Error: HeadPt Null ???\n");
	}
	else
	{
		p_head = p_head->next;
		if(p_head == NULL) p_tail = NULL;
	}
}

uint8_t LLGetFront()
{
	return p_head->value;
}

uint8_t LLGetBack()
{
	return p_tail->value;
}

void LLPopBack(void)
{

	printf("======== Remove tail =========>\n");
	if(p_head == NULL)
		printf("There is nothing to pop \n");
	else if (p_head == p_tail)
	{
		p_head = NULL;
		p_tail = NULL;
	}
	else
	{
		myLL* p_temp=p_head;
		while(p_temp->next != p_tail)
		{
			p_temp = p_temp->next;
		}
		p_temp->next = NULL;
		p_tail = p_temp;
	}
}
void LLPushBack(myLL *newNode)
{
	printf("Push back to tail %d \n", newNode->value);
	if(p_head == NULL)
	{
		p_head = newNode;
		p_tail = p_head;
	}
	else
	{
		p_tail->next = newNode;
		p_tail = newNode;
	}
}

bool LLSearchNode(uint8_t findme)
{
	myLL* p_cur = p_head;
	while(p_cur != NULL)
	{
		if (p_cur->value != findme)
			p_cur = p_cur->next;
		else
			return true;
	}
	return false;
}

void LLPrintList()
{
	printf("\n");
	printf("HeadPt: %p \n", p_head);
	myLL* p_cur = p_head;
	printf("------------------------------------------------------- \n");
	while(1)
	{
		if(p_cur != NULL)
		{
			printf("Address %p --- Value: %3d --- Next: %p \n", p_cur, p_cur->value, p_cur->next);
			p_cur = p_cur->next;
		}
		else
		{
			break;
		}
	}
	printf("------------------------------------------------------- \n");
	printf("TailPt: %p \n",p_tail);
	printf("\n");
}

