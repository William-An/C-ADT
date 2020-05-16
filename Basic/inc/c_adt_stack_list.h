#ifndef __C_ADT_STACK_LIST_H__
#define __C_ADT_STACK_LIST_H__

/**
 * 
 * LinkedList implementation of stack
 * 
 * */

#include <stdint.h>
#include <stdlib.h>
#include "c_adt_list.h"

#ifndef ValueType
#define ValueType int
#endif

// Data Structure Definition
typedef struct LinkedList_s Stack_s;
typedef LinkedList Stack;   // Using linkedlist implementation of stack

// Stack API
void init_stack(Stack stack);
void push_stack(ValueType val, Stack stack);
ValueType pop_stack(Stack stack);
ValueType peek_stack(Stack stack);
int isEmpty_stack(Stack stack);
void free_stack(Stack stack);

#endif