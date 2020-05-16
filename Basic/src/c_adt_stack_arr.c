#include "c_adt_stack_arr.h"

// ************************************************************************
// Stack API
// ************************************************************************

/**
 * 
 * @brief: _resize_stack, helper function used to resize the stack to the newSize; if newSize is smaller than the count of elements, operation should be invalid
 * @param: stack, Stack, stack to be resized
 * @param: newSize, uint32_t, new size of the stack
 * 
 * */
void _resize_stack(Stack stack, uint32_t newSize) {
    if (stack == NULL || newSize < stack->size)
        return;
    else {
        stack->arr = (ValueType*) realloc(stack->arr, newSize * sizeof(ValueType));
        stack->maxSize = newSize;
    }
}

/**
 * 
 * @brief: init_stack, given a pointer to the stack, initialize all variables necessary; in particular, initialize array size to MIN_STACK_SIZE
 * @param: stack, Stack, pointer to Stack_s, should be assigned a space in memory prior to calling this function
 * 
 * */
void init_stack(Stack stack) {
    if (stack == NULL)
        return;
    else {
        stack->arr = (ValueType*) malloc(sizeof(ValueType) * MIN_STACK_SIZE);
        stack->size = 0;
        stack->maxSize = MIN_STACK_SIZE;
    }
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
    else {
        // todo Push element to stack, resize if necessary
        if (stack->size < stack->maxSize) {
            stack->arr[stack->size] = val;
            stack->size++;
        } else {
            // Full stack, need to resize
            _resize_stack(stack, stack->maxSize * 2);
            push_stack(val, stack);
        }
    }
}

/**
 * 
 * @brief: pop_stack, pop the top value from the stack, should resize stack if necessary
 * @param: stack, Stack, pointer to Stack_s
 * @return: ValueType, value originally at top of the stack
 * 
 * */
ValueType pop_stack(Stack stack) {
    if (stack == NULL)
        return (ValueType) 0;
    else {
        // todo pop element from stack, resize if necessary
        if (stack->size == 0)   // Empty stack
            return (ValueType) 0;
        else {
            ValueType res = stack->arr[stack->size - 1];
            stack->size--;
            // Resize if less than 1/4
            if (stack->maxSize != MIN_STACK_SIZE && stack->size < stack->maxSize / 4)
                _resize_stack(stack, stack->maxSize / 2);
            return res;
        }
    }
}

/**
 * 
 * @brief: peek_stack, return the value on top of stack without removing it from stack
 * @param: stack, Stack, pointer to Stack_s
 * @return: ValueType, value currently at top of the stack
 * 
 * */
ValueType peek_stack(Stack stack) {
    if (stack == NULL)
        return (ValueType) 0;
    else {
        // todo pop element from stack, resize if necessary
        if (stack->size == 0)   // Empty stack
            return (ValueType) 0;
        else {
            return stack->arr[stack->size - 1];
        }
    }
}

/**
 * 
 * @brief: isEmpty_stack, check if a stack is empty (element count is zero)
 * @param: stack, Stack, pointer to Stack_s
 * @return: int, 1 means Stack stack is empty, 0 otherwise
 * 
 * */
int isEmpty_stack(Stack stack) {
    if (stack == NULL)
        return 1;
    else
        return stack->size == 0;
}

/**
 * 
 * @brief: free the memory assigned to Stack stack during init_stack
 * @param: stack, Stack, pointer to Stack_s
 * 
 * */
void free_stack(Stack stack) {
    if (stack == NULL)
        return;
    else {
        free(stack->arr);
        stack->size = 0;
        stack->maxSize = MIN_STACK_SIZE;
        stack->arr = NULL;
        return;
    }
}