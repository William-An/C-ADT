#include "c_adt_stack_list.h"

// ************************************************************************
// Stack API
// ************************************************************************

/**
 * 
 * @brief: init_stack, given a pointer to the stack, initialize all variables necessary
 * @param: stack, Stack, pointer to Stack_s, should be assigned a space in memory prior to calling this function
 * 
 * */
void init_stack(Stack stack) {
    if (stack == NULL)
        return;
    init_LL((LinkedList) stack);
}

/**
 * 
 * @brief: push_stack, push a value onto the stack, should resize stack if necessary
 * @param: val, ValueType, value to be pushed into stack
 * @param: stack, Stack, pointer to Stack_s
 * 
 * */
void push_stack(ValueType val, Stack stack) {
    if (stack == NULL)
        return;
    insertHead_LL(val, (LinkedList) stack);
}

/**
 * 
 * @brief: pop_stack, pop the top value from the stack, should resize stack if necessary
 * @param: stack, Stack, pointer to Stack_s
 * @return: ValueType, value originally at top of the stack
 * 
 * */
ValueType pop_stack(Stack stack) {
    if (stack == NULL || isEmpty_stack(stack) == 1)
        return (ValueType) 0;
    ValueType res = ((LinkedList) stack)->head->value;
    PtrToLinkedListNode node = ((LinkedList) stack)->head;
    ((LinkedList) stack)->head = node->next;
    free(node);
    return res;
}

/**
 * 
 * @brief: peek_stack, return the value on top of stack without removing it from stack
 * @param: stack, Stack, pointer to Stack_s
 * @return: ValueType, value currently at top of the stack
 * 
 * */
ValueType peek_stack(Stack stack) {
    if (stack == NULL || isEmpty_stack(stack) == 1)
        return (ValueType) 0;
    ValueType res = ((LinkedList) stack)->head->value;
    return res;
}

/**
 * 
 * @brief: isEmpty_stack, check if a stack is empty (element count is zero)
 * @param: stack, Stack, pointer to Stack_s
 * @return: int, 1 means Stack stack is empty, 0 otherwise
 * 
 * */
int isEmpty_stack(Stack stack) {
    return isEmpty_LL((LinkedList) stack);
}

/**
 * 
 * @brief: free the memory assigned to Stack stack during init_stack
 * @param: stack, Stack, pointer to Stack_s
 * 
 * */
void free_stack(Stack stack) {
    free_LL((LinkedList) stack);
}