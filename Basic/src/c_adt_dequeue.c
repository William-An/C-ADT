#include "c_adt_dequeue.h"

/**
 * 
 * Data Structure definition for array implementation of Dequeue
 * 
 * */

struct Dequeue_s {
    ValueType* arr;
    uint32_t size;      // Current element count in the dequeue
    uint32_t maxSize;   // Current array size
    uint32_t head;      // Current dequeue head index in the array
    uint32_t tail;      // Current dequeue tail index in the array
};

// ************************************************************************
// Dequeue API
// ************************************************************************

/**
 * 
 * @brief: _resize_dequeue, helper function used to resize the dequeue to the newSize; if newSize is smaller than the count of elements, operation should be invalid
 * @param: dq, Dequeue, dequeue to be resized
 * @param: newSize, uint32_t, new size of the queue
 * 
 * */
void _resize_dequeue(Dequeue dq, uint32_t newSize) {

}

/**
 * 
 * @brief: init_dequeue, given a pointer to the queue, initialize all variables necessary; in particular, initialize array size to MIN_QUEUE_SIZE
 * @param: dq, Dequeue, pointer to Dequeue_s, should be assigned a space in memory prior to calling this function
 * 
 * */
void init_dequeue(Dequeue dq) {

}

/**
 * 
 * @brief: insertHead_dq, given a value and a dequeue, insert the value at the head of the dequeue and update dq data fields accordingly and resize if necessary
 * @param: val, ValueType, value to be inserted into dq
 * @param: dq, Dequeue, pointer to Dequeue_s
 * 
 * */
void insertHead_dq(ValueType val, Dequeue dq) {

}

/**
 * 
 * @brief: insertTail_dq, given a value and a dequeue, insert the value at the tail of the dequeue and update dq data fields accordingly and resize if necessary
 * @param: val, ValueType, value to be inserted into dq
 * @param: dq, Dequeue, pointer to Dequeue_s
 * 
 * */
void insertTail_dq(ValueType val, Dequeue dq) {

}

/**
 * 
 * @brief: removeHead_dq, given a dequeue, remove and return its value at head position, resize if necessary
 * @param: dq, Dequeue, pointer to Dequeue_s
 * @return: ValueType, value originally at head position
 * 
 * */
ValueType removeHead_dq(Dequeue dq) {

}

/**
 * 
 * @brief: removeHead_dq, given a dequeue, remove and return its value at tail position, resize if necessary
 * @param: dq, Dequeue, pointer to Dequeue_s
 * @return: ValueType, value originally at tail position
 * 
 * */
ValueType removeTail_dq(Dequeue dq) {

}

/**
 * 
 * @brief: peekHead_dq, return the element at head position of dq without removing it
 * @param: dq, Dequeue, pointer to Dequeue_s
 * @return: ValueType, value currently at head position
 * 
 * */
ValueType peekHead_dq(Dequeue dq) {

}

/**
 * 
 * @brief: peekTail_dq, return the element at tail position of dq without removing it
 * @param: dq, Dequeue, pointer to Dequeue_s
 * @return: ValueType, value currently at tail position
 * 
 * */
ValueType peekTail_dq(Dequeue dq) {

}

/**
 * 
 * @brief: isEmpty_dq, check if dequeue dq is empty (element count is zero)
 * @param: dq, Dequeue, pointer to Dequeue_s
 * @return: int, 1 means the dq is empty, 0 other wise
 * 
 * */
int isEmpty_dq(Dequeue dq) {

}

/**
 * 
 * @brief: free the memory assigned to Dequeue dq during init_dequeue
 * @param: dq, Dequeue, pointer to Dequeue_s
 * 
 * */
void free_dq(Dequeue dq) {

}