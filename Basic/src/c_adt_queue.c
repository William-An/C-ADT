#include "c_adt_queue.h"

// ************************************************************************
// Queue API
// ************************************************************************

/**
 * 
 * @brief: _resize_queue, helper function used to resize the queue to the newSize; if newSize is smaller than the count of elements, operation should be invalid
 * @param: q, Queue, queue to be resized
 * @param: newSize, uint32_t, new size of the queue
 * 
 * */
void _resize_queue(Queue q, uint32_t newSize) {

}

/**
 * 
 * @brief: init_queue, given a pointer to the queue, initialize all variables necessary; in particular, initialize array size to MIN_QUEUE_SIZE
 * @param: q, Queue, pointer to Queue_s, should be assigned a space in memory prior to calling this function
 * 
 * */
void init_queue(Queue q) {

}

/**
 * 
 * @brief: enqueue_q, enqueue a value into the queue, should resize queue if necessary
 * @param: val, ValueType, value to be enqueued into the queue
 * @param: q, Queue, pointer to Queue_s
 * 
 * */
void enqueue_q(ValueType val, Queue q) {

}

/**
 * 
 * @brief: dequeue_q, remove the value at the head of the queue, should resize queue if necessary
 * @param: q, Queue, pointer to Queue_s
 * @return: ValueType, original value at the head of the queue
 * 
 * */
ValueType dequeue_q(Queue q) {

}

/**
 * 
 * @brief: peek_q, return the value at the head of the queue without removing it
 * @param: q, Queue, pointer to Queue_s
 * @return: ValueType, current value at the head of the queue
 * 
 * */
ValueType peek_q(Queue q) {

}

/**
 * 
 * @brief: isEmpty_q, check if a queue is empty (element count is zero)
 * @param: q, Queue, pointer to Queue_s
 * 
 * */
int isEmpty_q(Queue q) {

}

/**
 * 
 * @brief: free the memory assigned to Queue q during init_queue
 * @param: q, Queue, pointer to Queue_s
 * 
 * */
void free_q(Queue q) {

}