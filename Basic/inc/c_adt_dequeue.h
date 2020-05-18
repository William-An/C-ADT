#ifndef __C_ADT_DEQUEUE_H__
#define __C_ADT_DEQUEUE_H__

/**
 * 
 * Array implementation of dequeue
 * 
 * */

#include <stdint.h>
#include <stdlib.h>

#ifndef ValueType
#define ValueType int
#endif

// Minimum queue size used to initialize queue
#ifndef MIN_QUEUE_SIZE
#define MIN_QUEUE_SIZE 10
#endif // MIN_QUEUE_SIZE

/**
 * 
 * Data Structure definition for array implementation of Dequeue
 * 
 * */

struct Dequeue_s {
    ValueType* arr;
    uint32_t size;      // Current element count in the dequeue
    uint32_t maxSize;   // Current array size
    uint32_t head;      // Current dequeue head index in the array (next element to be remove from head)
    uint32_t tail;      // Current dequeue tail index in the array (next available slot to insert element)
};

// Data Structure Definition
struct Dequeue_s;
typedef struct Dequeue_s* Dequeue;

// Queue API
void init_dequeue(Dequeue dq);
void insertHead_dq(ValueType val, Dequeue dq);
void insertTail_dq(ValueType val, Dequeue dq);
ValueType removeHead_dq(Dequeue dq);
ValueType removeTail_dq(Dequeue dq);
ValueType peekHead_dq(Dequeue dq);
ValueType peekTail_dq(Dequeue dq);
int isEmpty_dq(Dequeue dq);
void free_dq(Dequeue dq);

#endif