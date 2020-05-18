#include "c_adt_dequeue.h"

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
    if (dq == NULL)
        return;
    else {
        ValueType* tmp = dq->arr;    // old array
        dq->arr = (ValueType*) malloc(sizeof(ValueType) * newSize);
        for (size_t i = dq->head; i < dq->size + dq->head; i++)
        {
            // Copy elements from old array to the new array
            // from the start 
            size_t old_i = i % dq->maxSize;
            size_t new_i = i - dq->head;
            (dq->arr)[new_i] = tmp[old_i];
        }
        free(tmp);
        dq->head = 0;
        dq->tail = dq->size;
        dq->maxSize = newSize;
    }
}

/**
 * 
 * @brief: init_dequeue, given a pointer to the queue, initialize all variables necessary; in particular, initialize array size to MIN_QUEUE_SIZE
 * @param: dq, Dequeue, pointer to Dequeue_s, should be assigned a space in memory prior to calling this function
 * 
 * */
void init_dequeue(Dequeue dq) {
    if (dq == NULL)
        return;
    else {
        dq->arr = (ValueType*) malloc(sizeof(ValueType) * MIN_QUEUE_SIZE);
        dq->head = 0;
        dq->tail = 0;
        dq->size = 0;
        dq->maxSize = MIN_QUEUE_SIZE;
    }
}

/**
 * 
 * @brief: insertHead_dq, given a value and a dequeue, insert the value 
 *         at the head of the dequeue and update dq data fields accordingly 
 *         and resize if necessary
 * @param: val, ValueType, value to be inserted into dq
 * @param: dq, Dequeue, pointer to Dequeue_s
 * 
 * */
void insertHead_dq(ValueType val, Dequeue dq) {
    if (dq == NULL)
        return;
    else {
        if (dq->size < dq->maxSize - 1) { // Not need to resize
            // Circular rotation
            if (dq->head == 0) {
                dq->head += dq->maxSize;    // Move head to tail
            }
            dq->head--;
            (dq->arr)[dq->head] = val;
            dq->size++;
        } else {    // Resize to twice the size
            _resize_dequeue(dq, dq->maxSize * 2);
            insertHead_dq(val, dq);
        }
    }
}

/**
 * 
 * @brief: insertTail_dq, given a value and a dequeue, insert the value 
 *         at the tail of the dequeue and update dq data fields accordingly 
 *         and resize if necessary. Equivalent to enqueue of Queue
 * @param: val, ValueType, value to be inserted into dq
 * @param: dq, Dequeue, pointer to Dequeue_s
 * 
 * */
void insertTail_dq(ValueType val, Dequeue dq) {
    if (dq == NULL)
        return;
    else {
        if (dq->size < dq->maxSize - 1) { // Not need to resize
            (dq->arr)[dq->tail] = val;
            (dq->tail)++;
            dq->tail %= dq->maxSize;
            dq->size++;
        } else {    // Resize to twice the size
            _resize_dequeue(dq, dq->maxSize * 2);
            insertTail_dq(val, dq);
        }
    }
}

/**
 * 
 * @brief: removeHead_dq, given a dequeue, remove and return its value at 
 *         head position, resize if necessary. Equivalent to dequeue of Queue
 * @param: dq, Dequeue, pointer to Dequeue_s
 * @return: ValueType, value originally at head position
 * 
 * */
ValueType removeHead_dq(Dequeue dq) {
    if (dq == NULL)
        return (ValueType) 0;
    else {
        if (dq->size < (dq->maxSize / 4) - 1 && dq->maxSize > MIN_QUEUE_SIZE) {  // Resize to 1/4
            _resize_dequeue(dq, dq->maxSize / 2);
            return removeHead_dq(dq);
        } else if (!isEmpty_dq(dq)) {  // Dequeue
            ValueType res = (dq->arr)[dq->head];
            (dq->head)++;
            dq->head %= dq->maxSize;
            dq->size--;
            return res;
        } else  // Do nothing if the queue is empty
            return (ValueType) 0;
    }
}

/**
 * 
 * @brief: removeHead_dq, given a dequeue, remove and return its value at tail position, resize if necessary
 * @param: dq, Dequeue, pointer to Dequeue_s
 * @return: ValueType, value originally at tail position
 * 
 * */
ValueType removeTail_dq(Dequeue dq) {
    if (dq == NULL)
        return (ValueType) 0;
    else {
        if (dq->size < (dq->maxSize / 4) - 1 && dq->maxSize > MIN_QUEUE_SIZE) {  // Resize to 1/4
            _resize_dequeue(dq, dq->maxSize / 2);
            return removeTail_dq(dq);
        } else if (!isEmpty_dq(dq)) {  // Dequeue
            if (dq->tail == 0)
                dq->tail = dq->maxSize;
            dq->tail--;
            ValueType res = (dq->arr)[dq->tail];
            dq->size--;
            return res;
        } else  // Do nothing if the queue is empty
            return (ValueType) 0;
    }
}

/**
 * 
 * @brief: peekHead_dq, return the element at head position of dq without removing it
 * @param: dq, Dequeue, pointer to Dequeue_s
 * @return: ValueType, value currently at head position
 * 
 * */
ValueType peekHead_dq(Dequeue dq) {
    if (dq == NULL)
        return (ValueType) 0;
    else {
        if (!isEmpty_dq(dq))
            return (dq->arr)[dq->head];
        else
            return (ValueType) 0;
    }
}

/**
 * 
 * @brief: peekTail_dq, return the element at tail position of dq without removing it
 * @param: dq, Dequeue, pointer to Dequeue_s
 * @return: ValueType, value currently at tail position
 * 
 * */
ValueType peekTail_dq(Dequeue dq) {
    if (dq == NULL)
        return (ValueType) 0;
    else {
        if (!isEmpty_dq(dq))
            return (dq->arr)[dq->tail - 1];
        else
            return (ValueType) 0;
    }
}

/**
 * 
 * @brief: isEmpty_dq, check if dequeue dq is empty (element count is zero)
 * @param: dq, Dequeue, pointer to Dequeue_s
 * @return: int, 1 means the dq is empty, 0 other wise
 * 
 * */
int isEmpty_dq(Dequeue dq) {
    if (dq == NULL)
        return 1;
    else
        return dq->size == 0;
}

/**
 * 
 * @brief: free the memory assigned to Dequeue dq during init_dequeue
 * @param: dq, Dequeue, pointer to Dequeue_s
 * 
 * */
void free_dq(Dequeue dq) {
    if (dq == NULL)
        return;
    else {
        free(dq->arr);
        dq->arr = NULL;
        dq->head = 0;
        dq->tail = 0;
        dq->size = 0;
        dq->maxSize = MIN_QUEUE_SIZE;
    }
}