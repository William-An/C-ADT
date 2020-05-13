#include "c_adt_stack_arr.h"

/**
 * 
 * Data Structure definition for array implementation of Stack
 * 
 * */

struct Stack_s {
    ValueType* arr;
    uint32_t size;      // Current element count in the stack
    uint32_t maxSize;   // Current array size
    uint32_t tail;      // Current stack tail index in the array (can be pushed)
};

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

}

/**
 * 
 * @brief: init_stack, given a pointer to the stack, initialize all variables necessary; in particular, initialize array size to MIN_STACK_SIZE
 * @param: stack, Stack, pointer to Stack_s, should be assigned a space in memory prior to calling this function
 * 
 * */
void init_stack(Stack stack) {

}

/**
 * 
 * @brief: push_stack, push a value onto the stack
 * @param: val, ValueType, value to be pushed into stack
 * @param: stack, Stack, pointer to Stack_s
 * 
 * */
void push_stack(ValueType val, Stack stack) {

}

/**
 * 
 * @brief: pop_stack, pop the top value from the stack
 * @param: stack, Stack, pointer to Stack_s
 * 
 * */
ValueType pop_stack(Stack stack) {

}

/**
 * 
 * @brief: peek_stack, return the value on top of stack without removing it from stack
 * @param: stack, Stack, pointer to Stack_s
 * 
 * */
ValueType peek_stack(Stack stack) {
    
}

/**
 * 
 * @brief: isEmpty_stack, check if a stack is empty (element count is zero)
 * @param: stack, Stack, pointer to Stack_s
 * 
 * */
int isEmpty_stack(Stack stack) {

}

/**
 * 
 * @brief: free the memory assigned to Stack stack during init_stack
 * @param: stack, Stack, pointer to Stack_s
 * 
 * */
void free_stack(Stack stack) {

}