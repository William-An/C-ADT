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
    if (q == NULL)
        return;
    else {
        ValueType* tmp = q->arr;    // old array
        q->arr = (ValueType*) malloc(sizeof(ValueType) * newSize);
        for (size_t i = q->head; i < q->size + q->head; i++)
        {
            // Copy elements from old array to the new array
            // from the start 
            size_t old_i = i % q->maxSize;
            size_t new_i = i - q->head;
            (q->arr)[new_i] = tmp[old_i];
        }
        free(tmp);
        q->head = 0;
        q->tail = q->size;
        q->maxSize = newSize;
    }
}

/**
 * 
 * @brief: init_queue, given a pointer to the queue, initialize all variables necessary; in particular, initialize array size to MIN_QUEUE_SIZE
 * @param: q, Queue, pointer to Queue_s, should be assigned a space in memory prior to calling this function
 * 
 * */
void init_queue(Queue q) {
    if (q == NULL)
        return;
    else {
        q->arr = (ValueType*) malloc(sizeof(ValueType) * MIN_QUEUE_SIZE);
        q->head = 0;
        q->tail = 0;
        q->size = 0;
        q->maxSize = MIN_QUEUE_SIZE;
    }
}

/**
 * 
 * @brief: enqueue_q, enqueue a value into the queue, should resize queue if necessary
 * @param: val, ValueType, value to be enqueued into the queue
 * @param: q, Queue, pointer to Queue_s
 * 
 * */
void enqueue_q(ValueType val, Queue q) {
    if (q == NULL)
        return;
    else {
        if (q->size < q->maxSize) { // Not need to resize
            (q->arr)[q->tail] = val;
            (q->tail)++;
            q->tail %= q->maxSize;
            q->size++;
        } else {    // Resize to twice the size
            _resize_queue(q, q->maxSize * 2);
            enqueue_q(val, q);
        }
    }
}

/**
 * 
 * @brief: dequeue_q, remove the value at the head of the queue, should resize queue if necessary
 * @param: q, Queue, pointer to Queue_s
 * @return: ValueType, original value at the head of the queue
 * 
 * */
ValueType dequeue_q(Queue q) {
    if (q == NULL)
        return (ValueType) 0;
    else {
        if (q->size < q->maxSize / 4 && q->maxSize > MIN_QUEUE_SIZE) {  // Resize to 1/4
            _resize_queue(q, q->maxSize / 2);
            return dequeue_q(q);
        } else if (!isEmpty_q(q)) {  // Dequeue
            ValueType res = (q->arr)[q->head];
            (q->head)++;
            q->head %= q->maxSize;
            q->size--;
            return res;
        } else  // Do nothing if the queue is empty
            return (ValueType) 0;
    }
}

/**
 * 
 * @brief: peek_q, return the value at the head of the queue without removing it
 * @param: q, Queue, pointer to Queue_s
 * @return: ValueType, current value at the head of the queue
 * 
 * */
ValueType peek_q(Queue q) {
    if (q == NULL)
        return (ValueType) 0;
    else {
        if (!isEmpty_q(q))
            return (q->arr)[q->head];
        else
            return (ValueType) 0;
    }
}

/**
 * 
 * @brief: isEmpty_q, check if a queue is empty (element count is zero)
 * @param: q, Queue, pointer to Queue_s
 * 
 * */
int isEmpty_q(Queue q) {
    if (q == NULL)
        return 1;
    else
        return q->size == 0;
}

/**
 * 
 * @brief: free the memory assigned to Queue q during init_queue
 * @param: q, Queue, pointer to Queue_s
 * 
 * */
void free_q(Queue q) {
    if (q == NULL)
        return;
    else {
        free(q->arr);
        q->arr = NULL;
        q->head = 0;
        q->tail = 0;
        q->size = 0;
        q->maxSize = MIN_QUEUE_SIZE;
    }
}