#ifndef __C_ADT_STACK_ARR_H__
#define __C_ADT_STACK_ARR_H__

/**
 * 
 * Array implementation of stack
 * 
 * */

#include <stdint.h>
#include <stdlib.h>

#ifndef ValueType
#define ValueType int
#endif

// minimum stack size used to initialize stack
#ifndef MIN_STACK_SIZE
#define MIN_STACK_SIZE 10
#endif // MIN_STACK_SIZE

// Data Structure Definition
struct Stack_s;
typedef struct Stack_s* Stack;

// Stack API
void init_stack(Stack stack);
void push_stack(ValueType val, Stack stack);
ValueType pop_stack(Stack stack);
ValueType peek_stack(Stack stack);
int isEmpty_stack(Stack stack);
void free_stack(Stack stack);

#endif